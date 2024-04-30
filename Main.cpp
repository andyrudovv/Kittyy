#include <iostream>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace cv;

int main() {

	VideoCapture video_capture(0);
	Mat frame;

	CascadeClassifier facedetect;

	facedetect.load("Cascades/haarcascade_frontalface_default.xml");

	std::vector<Rect> faces;


	while (true) {

		video_capture.read(frame);

		facedetect.detectMultiScale(frame, faces, 1.3, 5);

		for (int i = 0; i < faces.size(); i++) {
			rectangle(frame, faces[i].tl(), faces[i].br(), Scalar(50,50,255), 3);
		}

		
		imshow("Image", frame);
		waitKey(1);
	}

	return 0;
}