#include <opencv2\opencv.hpp>
#include <Windows.h>


IplImage * g_src = NULL;
IplImage * g_copy = NULL;
IplImage * g_dst = NULL;
IplImage * g_result = NULL;

CvPoint pt1;
CvPoint pt2;

LPTSTR reFile;

void drawRectangle(IplImage * src, IplImage * dst, CvPoint p1, CvPoint p2)
{

	int w = p2.x - p1.x;
	int h = p2.y - p1.y;

	if (p1.x > p2.x) p1.x = p2.x;
	if (p1.y > p2.y) p1.y = p2.y;

	for (int x = 0; x<w; x++)
		for (int y = 0; y<h; y++)
		{
			int x1 = (float)(x) / w * src->width;
			int y1 = (float)(y) / h * src->height;
			int x2 = x + p1.x;
			int y2 = y + p1.y;
			if (x1<0 || x1>src->width - 1) continue;
			if (y1<0 || y1>src->height - 1) continue;
			if (x2<0 || x2>dst->width - 1) continue;
			if (y2<0 || y2>dst->height - 1) continue;

			CvScalar c = cvGet2D(src, y2, x2);
			CvScalar f = c;
			f.val[0] += 10;
			f.val[1] += 10;
			f.val[2] += 10;
			cvSet2D(dst, y2, x2, f);
		}

}


void myMouse(int event, int x, int y, int flags, void * param)
{


	//pt1 = cvPoint(-1, -1);
	if (event == CV_EVENT_LBUTTONDOWN) {
		pt1 = cvPoint(x, y);
		cvCopy(g_dst, g_copy, NULL);
	}
	else if (event == CV_EVENT_MOUSEMOVE && flags&CV_EVENT_FLAG_LBUTTON) {
		pt2 = cvPoint(x, y);
		if (pt1.x<0) return;
		if (pt1.y<0) return;
		if (pt2.x<0) return;
		if (pt2.y<0) return;
		if (pt1.x>g_dst->width - 1) return;
		if (pt2.x>g_dst->width - 1) return;
		if (pt1.y>g_dst->height - 1) return;
		if (pt2.y>g_dst->height - 1) return;

		cvCopy(g_copy, g_dst, NULL);
		drawRectangle(g_src, g_dst, pt1, pt2);

		cvShowImage("dst", g_dst);
	}
	else if (event == CV_EVENT_LBUTTONUP) {
		CvScalar f;
		int w = pt2.x - pt1.x;
		int h = pt2.y - pt1.y;
		g_result = cvCreateImage(cvSize(w, h), 8, 3);

		for (int x = pt1.x; x<pt2.x; x++)
			for (int y = pt1.y; y < pt2.y; y++) {
				f = cvGet2D(g_dst, y, x);
				cvSet2D(g_result, y - pt1.y, x - pt1.x, f);
			}

		cvSaveImage(reFile, g_result, NULL);
		cvDestroyWindow("dst");
	}

}

int captureWithMouseDragging(char *RFile) {
	g_src = cvLoadImage(RFile, CV_LOAD_IMAGE_COLOR);
	reFile = (LPSTR)(LPCTSTR)RFile;

	if (g_src == NULL) { printf("Couldn't find the image file"); exit(0); }
	CvSize size = cvGetSize(g_src);

	for (int x = 0; x<size.width; x++)
		for (int y = 0; y < size.height; y++) {
			CvScalar s = cvGet2D(g_src, y, x);
			for (int k = 0; k < 3; k++)
				s.val[k] -= 10;
			cvSet2D(g_src, y, x, s);
		}

	g_copy = cvCreateImage(size, 8, 3);
	g_dst = cvCreateImage(size, 8, 3);

	cvCopy(g_src, g_dst, NULL);

	cvShowImage("dst", g_dst);
	cvMoveWindow("dst", -4, -26);
	cvSetMouseCallback("dst", myMouse, NULL);
	cvWaitKey(0);
	cvReleaseImage(&g_src);
	cvReleaseImage(&g_dst);
	cvReleaseImage(&g_copy);
	return 1;
}