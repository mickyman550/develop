#include "stdafx.h"
#include "ReadImageList.h"

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace cv;

std::string g_ssWinName = "Window";

static bool readStringList( const string& filename, vector<string>& l )
{
    l.resize(0);
    FileStorage fs(filename, FileStorage::READ);
    if( !fs.isOpened() )
        return false;
    FileNode n = fs.getFirstTopLevelNode();
    if( n.type() != FileNode::SEQ )
        return false;
    FileNodeIterator it = n.begin(), it_end = n.end();
    for( ; it != it_end; ++it )
        l.push_back((string)*it);
    return true;
}

bool GetFileDirectoryExt(const char *szFilePath, std::string *pssDir, std::string *pssFilename, std::string *pssExtension)
{
	std::string ssFilePath = szFilePath;
	size_t found = ssFilePath.find_last_of("\\");
	if(found == std::string::npos)
	{
		return false;
	}
	else
	{
		*pssDir = ssFilePath.substr(0, found+1);
		std::string ssFileName = ssFilePath.substr(found + 1, ssFilePath.length() - (found + 1));

		//find extension
		size_t found_ext = ssFileName.find_last_of(".");
		if (found_ext == std::string::npos)
		{
			*pssExtension = "";
			found_ext = ssFileName.length();
		}
		else
		{
			*pssExtension = ssFileName.substr(found_ext+1, ssFileName.length() - (found_ext+1));
		}
		*pssFilename = ssFileName.substr(0, found_ext);
	}
	return true;
}

int readStringList(int argc, char **argv)
{

    const char* inputFilename = "C:\\develop\\calib\\image_list.xml";
    vector<string> imageList;
	readStringList(inputFilename, imageList);
	
	namedWindow(g_ssWinName,CV_WINDOW_AUTOSIZE);

	for (int i = 0; i < imageList.size(); i++)
	{
		std::string const& ssImage = imageList[i];

		Mat img = imread(ssImage, 1);

		Mat show_img;
		resize(img, show_img, Size(img.cols/10, img.rows/10));
		imshow(g_ssWinName, show_img);
		//waitKey(0);                                          // Wait for a keystroke in the window

		std::string ssDir, ssFileName, ssExt;
		if(!GetFileDirectoryExt(ssImage.c_str(), &ssDir, &ssFileName, &ssExt))
		{
			continue;
		}
		std::string ssOut = ssDir + ssFileName + "_gray" + "." + ssExt;

		Mat img_grey;
		cvtColor( img, img_grey, CV_RGB2GRAY);

		resize(img_grey, show_img, Size(img.cols / 10, img.rows / 10));
		imshow(g_ssWinName, show_img);
		//waitKey(0);                                          // Wait for a keystroke in the window

		imwrite(ssOut.c_str(), img_grey);
	}

	return 0;
}