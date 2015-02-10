
#pragma once

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/features2d/features2d.hpp"

namespace cv
{

	//! finds intrinsic and extrinsic camera parameters from several fews of a known calibration pattern.
	double calibrateCamera(InputArrayOfArrays objectPoints,
		InputArrayOfArrays imagePoints,
		Size imageSize,
		CV_OUT InputOutputArray cameraMatrix,
		CV_OUT InputOutputArray distCoeffs,
		OutputArrayOfArrays rvecs, OutputArrayOfArrays tvecs,
		int flags = 0, TermCriteria criteria = TermCriteria(
		TermCriteria::COUNT + TermCriteria::EPS, 30, DBL_EPSILON));
};