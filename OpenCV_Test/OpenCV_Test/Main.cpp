// OpenCV_Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "video_homography.h"
#include "SURF_Homography.h"
#include "calibration.h"
#include "ReadImageList.h"


int main(int argc, char** argv)
{
	//readStringList(argc, argv);
	calibration(argc,argv);

	return 0;
}

