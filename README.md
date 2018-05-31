# ScreenShot_Team8 

## SCREEN CAPTURING CLI PROGRAM
   * A simple ScreenShot Open Source Program written on C Language
   * Program uses CLI (Command-Line Interface).
   * Saving screenshots in .bmp extention.
   * Screenshots will be saved in 'save' folder by default. User can change saving path if wanted.
   * Features:
     * (default) Whole screen capture
     * (with changed file name) Whole screen
     * Mouse Dragging feature to take screenshot of selected region.

## GETTING STARTED:
  * To compile the project on your own machine follow this steps:
  1. Create new project in Visual Studio as Win32 Project
  2. Add all source files and headers to the project from repository
  3. Install OpenCV dependencies and library. To do that follow this link:           
    http://www.aishack.in/tutorials/installing-configuring-opencv-2-windows/
    Since we are used OpenCV version 2.3 , in Project Properties > Linker > Input add Additional dependencies: 
    core230.lib highgui230.lib imgproc230.lib 
  4. Try to build and run the project.
  * To test or use our program run ScreenShot_Team8.exe file 

## SOFTWARE REQUIREMENTS FOR COMPILING:
  * OS: Windows 7/8/10
  * Visual Studio at least 2010 version
  * OpenCV version 2.3 or higher
  * WinAPI for those who want to compile program on Linux

## LICENSE:
  * UnLicense (public domain) - <http://unlicense.org/>

## USED SOURCE:
  * <https://github.com/darealshinji/cmdline-screenshot-tool-c>
