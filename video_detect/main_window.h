#pragma once
#include "main_window.cpp"

namespace videodetect {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// main_window에 대한 요약입니다.
	/// </summary>
	public ref class main_window : public System::Windows::Forms::Form
	{
	public:
		main_window(void)
		{
			InitializeComponent();

			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}


	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~main_window()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:


	private: System::Windows::Forms::PictureBox^  pictureBox1;


	private: System::ComponentModel::BackgroundWorker^  backgroundWorker1;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::Button^  btn_Streaming;
	private: System::Windows::Forms::Button^  btn_recording;
	private: System::Windows::Forms::Button^  btn_detecting;
	private: System::Windows::Forms::Button^  btn_handtracking;
	private: System::Windows::Forms::Button^  btn_canny;


	protected:

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>

		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->btn_Streaming = (gcnew System::Windows::Forms::Button());
			this->btn_recording = (gcnew System::Windows::Forms::Button());
			this->btn_handtracking = (gcnew System::Windows::Forms::Button());
			this->btn_detecting = (gcnew System::Windows::Forms::Button());
			this->btn_canny = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->flowLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(640, 360);
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->btn_Streaming);
			this->flowLayoutPanel1->Controls->Add(this->btn_recording);
			this->flowLayoutPanel1->Controls->Add(this->btn_handtracking);
			this->flowLayoutPanel1->Controls->Add(this->btn_detecting);
			this->flowLayoutPanel1->Controls->Add(this->btn_canny);
			this->flowLayoutPanel1->Location = System::Drawing::Point(82, 378);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(506, 29);
			this->flowLayoutPanel1->TabIndex = 4;
			// 
			// btn_Streaming
			// 
			this->btn_Streaming->Location = System::Drawing::Point(3, 3);
			this->btn_Streaming->Name = L"btn_Streaming";
			this->btn_Streaming->Size = System::Drawing::Size(95, 25);
			this->btn_Streaming->TabIndex = 2;
			this->btn_Streaming->Text = L"스트리밍 시작";
			this->btn_Streaming->UseVisualStyleBackColor = true;
			this->btn_Streaming->Click += gcnew System::EventHandler(this, &main_window::Streaming_Click);
			// 
			// btn_recording
			// 
			this->btn_recording->Location = System::Drawing::Point(104, 3);
			this->btn_recording->Name = L"btn_recording";
			this->btn_recording->Size = System::Drawing::Size(95, 25);
			this->btn_recording->TabIndex = 3;
			this->btn_recording->Text = L"녹화 시작";
			this->btn_recording->UseVisualStyleBackColor = true;
			this->btn_recording->Click += gcnew System::EventHandler(this, &main_window::btn_recording_Click);
			// 
			// btn_handtracking
			// 
			this->btn_handtracking->Location = System::Drawing::Point(205, 3);
			this->btn_handtracking->Name = L"btn_handtracking";
			this->btn_handtracking->Size = System::Drawing::Size(95, 25);
			this->btn_handtracking->TabIndex = 5;
			this->btn_handtracking->Text = L"트래킹 시작";
			this->btn_handtracking->UseVisualStyleBackColor = true;
			this->btn_handtracking->Click += gcnew System::EventHandler(this, &main_window::btn_handtracking_Click);
			// 
			// btn_detecting
			// 
			this->btn_detecting->Location = System::Drawing::Point(306, 3);
			this->btn_detecting->Name = L"btn_detecting";
			this->btn_detecting->Size = System::Drawing::Size(95, 25);
			this->btn_detecting->TabIndex = 4;
			this->btn_detecting->Text = L"디텍팅 시작";
			this->btn_detecting->UseVisualStyleBackColor = true;
			this->btn_detecting->Click += gcnew System::EventHandler(this, &main_window::btn_detecting_Click);
			// 
			// btn_canny
			// 
			this->btn_canny->Location = System::Drawing::Point(407, 3);
			this->btn_canny->Name = L"btn_canny";
			this->btn_canny->Size = System::Drawing::Size(95, 25);
			this->btn_canny->TabIndex = 6;
			this->btn_canny->Text = L"캐니 에지 시작";
			this->btn_canny->UseVisualStyleBackColor = true;
			this->btn_canny->Click += gcnew System::EventHandler(this, &main_window::button1_Click);
			// 
			// main_window
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(665, 413);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"main_window";
			this->Text = L"main_window";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->flowLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Streaming_Click(System::Object^  sender, System::EventArgs^  e) {
		int window = 0;

		if (capture.isOpened()) {

			face_cascade.load("./data/haarcascade_frontface.xml");

			std::time(&rawtime);
			timeinfo = std::localtime(&rawtime);
			std::strftime(file_name, 80, "./record/video_%Y-%m-%d %Hh %Mm.mp4", timeinfo);

			if (btn_Streaming->Text == "스트리밍 중지") {
				btn_Streaming->Text = "스트리밍 시작";
				if (btn_recording->Text == "녹화 중지") btn_recording->Text = "녹화 시작";
				if (btn_detecting->Text == "디텍팅 중지") btn_detecting->Text = "디텍팅 시작";
				if (btn_handtracking->Text == "트래킹 중지") {
					btn_handtracking->Text = "트래킹 시작";
					frame_hand.release();
				}
			}
			else btn_Streaming->Text = "스트리밍 중지";

			// 작동				
			while (btn_Streaming->Text == "스트리밍 중지") {
				capture.read(frame);

				// 녹화
				if (btn_recording->Text == "녹화 중지") {
					if (!writer.isOpened()) writer.open(file_name, fourcc, 12, video_size);
					else writer.write(frame);
				}
				else writer.release();

				if (btn_detecting->Text == "디텍팅 중지")	detectAndDisplay(face_cascade, frame);

				if (btn_handtracking->Text == "트래킹 중지") {
					cv::cvtColor(frame, frame_hand, cv::COLOR_BGR2HSV);
					hand_tracking(face_cascade, frame, frame_hand);
				}	

				if (btn_canny->Text == "캐니 에지 중지") {
					if (window == 0) {
						cv::namedWindow("캐니 에지");
						cv::createTrackbar("canny_low", "캐니 에지", 0, 1000);
						cv::createTrackbar("canny_high", "캐니 에지", 0, 1000);

						cv::setTrackbarPos("canny_low", "캐니 에지", 50);
						cv::setTrackbarPos("canny_high", "캐니 에지", 150);

						window = 1;
					}

					cv::Mat canny;
					int low = cv::getTrackbarPos("canny_low", "캐니 에지");
					int high = cv::getTrackbarPos("canny_high", "캐니 에지");
					
					if (low > high) cv::setTrackbarPos("canny_high", "캐니 에지", low);
					if (high < low) cv::setTrackbarPos("canny_low", "캐니 에지", high);

					cv::Canny(frame, canny, low, high);

					cv::imshow("캐니 에지", canny);
				}
				else { 
					cv::destroyWindow("캐니 에지"); 
					window = 0; 
				}

				if (cv::waitKey(27) == 0) break;
				video_running(capture, frame, pictureBox1);
			}
		}
		else {
			MessageBox::Show(_T("카메라를 열 수 없습니다."), _T("경고"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
private: System::Void btn_recording_Click(System::Object^  sender, System::EventArgs^  e) {
	if (btn_Streaming->Text == "스트리밍 시작") MessageBox::Show(_T("스트리밍을 시작해주세요."), _T("경고"), MessageBoxButtons::OK, MessageBoxIcon::Warning);

	else {
		if (capture.isOpened()) {
			if (btn_recording->Text == "녹화 중지") btn_recording->Text = "녹화 시작";
			else btn_recording->Text = "녹화 중지";
		}
		else
			MessageBox::Show(_T("카메라를 열 수 없습니다."), _T("경고"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	}
}
private: System::Void btn_detecting_Click(System::Object^  sender, System::EventArgs^  e) {
	if (btn_Streaming->Text == "스트리밍 시작") MessageBox::Show(_T("스트리밍을 시작해주세요."), _T("경고"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	else {
		if (btn_detecting->Text == "디텍팅 중지") btn_detecting->Text = "디텍팅 시작";
		else btn_detecting->Text = "디텍팅 중지";
	}
}
private: System::Void btn_handtracking_Click(System::Object^  sender, System::EventArgs^  e) {

	if (btn_Streaming->Text == "스트리밍 시작") MessageBox::Show(_T("스트리밍을 시작해주세요."), _T("경고"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	else {
		if (btn_handtracking->Text == "트래킹 중지") btn_handtracking->Text = "트래킹 시작";
		else btn_handtracking->Text = "트래킹 중지";
	}
}

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	if (btn_Streaming->Text == "스트리밍 시작") MessageBox::Show(_T("스트리밍을 시작해주세요."), _T("경고"), MessageBoxButtons::OK, MessageBoxIcon::Warning);
	else {
		if (btn_canny->Text == "캐니 에지 중지") btn_canny->Text = "캐니 에지 시작";
		else btn_canny->Text = "캐니 에지 중지";
	}
}
};
}
