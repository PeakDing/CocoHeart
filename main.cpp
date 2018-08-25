

//opencv
#include <opencv2\opencv.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/highgui/highgui.hpp>

using namespace cv;

int main()
{
	RNG& rng = theRNG();

	Mat Mono_heart = imread("Mono_heart.png", 0);
	Mat Color_heart = Mono_heart.clone();

	cvtColor(Color_heart, Color_heart, CV_GRAY2BGR);

	for (;;)
	{
		int color_B = rng.uniform(0, 255);
		int color_G = rng.uniform(0, 255);
		int color_R = rng.uniform(0, 255);


		MatConstIterator_<uchar> it_in = Mono_heart.begin<uchar>();
		MatConstIterator_<uchar> itend_in = Mono_heart.end<uchar>();
		MatIterator_<Vec3b> it_out = Color_heart.begin<Vec3b>();
		MatIterator_<Vec3b> itend_out = Color_heart.end<Vec3b>();

		while (it_in != itend_in)
		{
			if ((*it_in) <= 1)
			{
				(*it_out)[0] = color_B;
				(*it_out)[1] = color_G;
				(*it_out)[2] = color_R;
			}
			else if ((*it_in) <= 125)
			{
				(*it_out)[0] = color_R;
				(*it_out)[1] = color_G;
				(*it_out)[2] = color_B;
			}

			  it_in++;
			  it_out++;
	    }

		imshow("Color_heart", Color_heart);
		cvWaitKey(520);
	}
}