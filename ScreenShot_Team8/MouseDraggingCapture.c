// ***************************************************************************************//
//This source uses OpenCV version 2.3 to take mouse events and work with screenshot image. 
// ***************************************************************************************//

#include <opencv2\opencv.hpp>
#include <Windows.h>

//Creating image containers globally
IplImage * g_src = NULL;
IplImage * g_copy = NULL;
IplImage * g_dst = NULL;
IplImage * g_result = NULL;

CvPoint pt1; //starting points of rectangle (x,y)
CvPoint pt2; //end points of rectangle (x,y)

LPTSTR reFile;

void drawRectangle(IplImage * src, IplImage * dst, CvPoint p1, CvPoint p2) 
{
	//width and height of rectangle
	int w = p2.x - p1.x;  
	int h = p2.y - p1.y;  

	

	//in case if user drags from right down to left up
	//p1 and p2 points switch their x,y positions
	CvPoint temp; //creating temp point to simple switch
	if (p1.x > p2.x) {
		temp.x = p1.x;
		p1.x = p2.x;
		p2.x = temp.x;
	}
	if (p1.y > p2.y) {
		temp.y = p1.y;
		p1.y = p2.y;
		p2.y = temp.y;
	}

	//drawing rectangle
	for (int x = 0; x<w; x++)
		for (int y = 0; y<h; y++)
		{
			int x1 = (float)(x) / w * src->width;
			int y1 = (float)(y) / h * src->height;
			int x2 = x + p1.x;
			int y2 = y + p1.y;

			//if mouse cursor dragged out from window after click - continue
			if (x1<0 || x1>src->width - 1) continue;
			if (y1<0 || y1>src->height - 1) continue;
			if (x2<0 || x2>dst->width - 1) continue;
			if (y2<0 || y2>dst->height - 1) continue;

			
			CvScalar c = cvGet2D(src, y2, x2); //taking color (1by1 pixel) of selected area from source image (our fullscreen screenshot)
			CvScalar f = c; 

			//Increasing brightness by 10 for each rgb channel
			f.val[0] += 10;
			f.val[1] += 10;
			f.val[2] += 10;

			cvSet2D(dst, y2, x2, f); //setting color with increased brightness to the selected area
		}

}


void myMouse(int event, int x, int y, int flags, void * param) //mouse callback function
{
	
	if (event == CV_EVENT_LBUTTONDOWN) {
		pt1 = cvPoint(x, y); //starting point of rectangle when left button is clicked (down)
		cvCopy(g_dst, g_copy, NULL); //copy image to buffer image
	}
	else if (event == CV_EVENT_MOUSEMOVE && flags&CV_EVENT_FLAG_LBUTTON) {  //while mouse is moving and left button is pressed
		pt2 = cvPoint(x, y); //end point when mouse is moved

		if (pt1.x<0) return;
		if (pt1.y<0) return;
		if (pt2.x<0) return;
		if (pt2.y<0) return;
		if (pt1.x>g_dst->width - 1) return;
		if (pt2.x>g_dst->width - 1) return;
		if (pt1.y>g_dst->height - 1) return;
		if (pt2.y>g_dst->height - 1) return;

		cvCopy(g_copy, g_dst, NULL); //copying buffer image to destination image
		drawRectangle(g_src, g_dst, pt1, pt2);

		cvShowImage("dst", g_dst); //showing image in window
	}
	else if (event == CV_EVENT_LBUTTONUP) {
		CvScalar f;
		int w = pt2.x - pt1.x;
		int h = pt2.y - pt1.y;
		g_result = cvCreateImage(cvSize(w, h), 8, 3); //image of selected area

		for (int x = pt1.x; x<pt2.x; x++)
			for (int y = pt1.y; y < pt2.y; y++) {
				f = cvGet2D(g_dst, y, x); //getting color of dst image to each pixel
				cvSet2D(g_result, y - pt1.y, x - pt1.x, f); //setting color to result image
			}

		cvSaveImage(reFile, g_result, NULL); //saving image to computer
		cvDestroyWindow("dst"); //closing window
	}

}
int captureWithMouseDragging(char *RFile) {
	g_src = cvLoadImage(RFile, CV_LOAD_IMAGE_COLOR); //loading fullscreen screnshot and saving in g_src image container
	reFile = (LPSTR)(LPCTSTR)RFile;

	if (g_src == NULL) { printf("Couldn't find the image file"); exit(0); } //handling error if screenshot wasn't found
	CvSize size = cvGetSize(g_src);

	for (int x = 0; x<size.width; x++)
		for (int y = 0; y < size.height; y++) {
			CvScalar s = cvGet2D(g_src, y, x); //getting collor for each pixel from screenshot
			for (int k = 0; k < 3; k++)
				s.val[k] -= 10; //lowering brightness for each rgb channel
			cvSet2D(g_src, y, x, s); //setting to g_src
		}

	g_copy = cvCreateImage(size, 8, 3); //defining size of buffer img
	g_dst = cvCreateImage(size, 8, 3); //defining size of destination img

	cvCopy(g_src, g_dst, NULL); //making copy of source image

	cvShowImage("dst", g_dst); 
	cvMoveWindow("dst", -4, -26); //moving window to fetch the screen
	cvSetMouseCallback("dst", myMouse, NULL); //mouse callback
	cvWaitKey(0); 
	//clearing memory
	cvReleaseImage(&g_src); 
	cvReleaseImage(&g_dst);
	cvReleaseImage(&g_copy);
	return 1;
}