#include "stdafx.h"
#include "opencv2/core/core.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

void help();

bool test(int argc, char **argv)
{
	if (argc != 3)
	{
		help();
		return false;
	}

	Mat img1 = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
	Mat img2 = imread(argv[2], CV_LOAD_IMAGE_GRAYSCALE);

	return true;
}

void help()
{
	printf("help");
}

