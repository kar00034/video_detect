#include <iostream>
#include <ctime>
#include <opencv2/opencv.hpp>
#include <tchar.h>
#define _UNICODE

using namespace System::Windows::Forms;
static cv::VideoCapture capture(0);
static cv::Mat frame, frame_hand, frame_out;


static std::time_t rawtime;
static std::tm* timeinfo;

static cv::Size video_size(capture.get(cv::CAP_PROP_FRAME_WIDTH), capture.get(cv::CAP_PROP_FRAME_HEIGHT));
static cv::VideoWriter writer;
static cv::CascadeClassifier face_cascade;

static int fourcc = cv::VideoWriter::fourcc('D', 'I', 'V', 'X');
static int step = 0, start_x, start_y, end_x, end_y;
static double fps = 29.97;
static int delay = cvRound(1000.0 / fps);



static char file_name[80];

static bool mouse_is_pressing = false;


// 스트리밍 시작
static void video_running(cv::VideoCapture capture, cv::Mat frame, System::Windows::Forms::PictureBox^  pictureBox1) {
	
	System::Drawing::Graphics^ graphics2 = pictureBox1->CreateGraphics();
	System::IntPtr ptr2(frame.ptr());
	System::Drawing::Bitmap^ b2 = gcnew System::Drawing::Bitmap(frame.cols,
		frame.rows, frame.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr2);
	System::Drawing::RectangleF rect2(0, 0, pictureBox1->Width, pictureBox1->Height);

	graphics2->DrawImage(b2, rect2);
	
		

};

static void detectAndDisplay(cv::CascadeClassifier face_cascade, cv::Mat frame){
	cv::Mat grayframe;
	cv::cvtColor(frame, grayframe, cv::COLOR_BGR2GRAY);
	equalizeHist(grayframe, grayframe);
	std::vector<cv::Rect> faces;

	face_cascade.detectMultiScale(grayframe, faces,
		1.1, // increase search scale by 10% each pass
		3,   // merge groups of three detections
		cv::CASCADE_FIND_BIGGEST_OBJECT | cv::CASCADE_SCALE_IMAGE,
		cv::Size(30, 30)
	);

	for (int i = 0; i < faces.size(); i++) {
		cv::Point lb(faces[i].x + faces[i].width, faces[i].y + faces[i].height);
		cv::Point tr(faces[i].x, faces[i].y);
		rectangle(frame, lb, tr, cv::Scalar(0, 255, 0), 3, 4, 0);
	}
}

static void remove_face(cv::CascadeClassifier cascade, cv::Mat in_frame) {  // 얼굴 디텍팅 후 제거
	std::vector<cv::Rect> faces;
	int hei = in_frame.cols;

	face_cascade.detectMultiScale(in_frame, faces,
		1.1, 5,   
		cv::CASCADE_FIND_BIGGEST_OBJECT | cv::CASCADE_SCALE_IMAGE,
		cv::Size(30, 30)
	);

	for (int i = 0; i < faces.size(); i++) {
		cv::Point lb(faces[i].x + faces[i].width, 0);
		cv::Point tr(faces[i].x, hei);
		rectangle(in_frame, lb, tr, cv::Scalar(0, 0, 0), -1);
	}	
}

static void hand_tracking(cv::CascadeClassifier cascade, cv::Mat frame, cv::Mat in_frame) {	
	std::vector<std::vector<cv::Point> > contours;
	std::vector<cv::Vec4i> hierarchy;
	
	remove_face(cascade, in_frame);
	cv::inRange(in_frame, cv::Scalar(0, 30, 0), cv::Scalar(15, 255, 255), in_frame);
	auto kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5));
	cv::morphologyEx(in_frame, in_frame, cv::MORPH_CLOSE, kernel);	
	cv::findContours(in_frame, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
	
	for (int i = 0; i < contours.size(); i++)
		cv::drawContours(frame, contours, i, cv::Scalar(255, 0, 0), 3);
	
	cv::imshow("hand tracking", in_frame);
}



static void mouse_callback(int event, int x, int y, int flags, void* userdata)
{

	cv::Mat frame_roi = frame.clone();


	if (event == cv::EVENT_LBUTTONDOWN) {
		mouse_is_pressing = true;
		start_x = x;
		start_y = y;

		cv::circle(frame_roi, cv::Point(x, y), 10, cv::Scalar(0, 255, 0), -1);
	}
	else if (event == cv::EVENT_MOUSEMOVE) {

		if (mouse_is_pressing) {

			cv::rectangle(frame_roi, cv::Point(start_x, start_y), cv::Point(x, y),
				cv::Scalar(0, 255, 0), 3);
		}

	}
	else if (event == cv::EVENT_LBUTTONUP) {

		mouse_is_pressing = false;

		cv::Mat frame(frame_roi, cv::Rect(start_x, start_y, x - start_x, y - start_y));
		cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);

		frame.copyTo(frame_roi(cv::Rect(start_x, start_y, x - start_x, y - start_y)));
		cv::imshow("ROI", frame);
	}
}