#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>


using namespace std;
using namespace cv;

int main(int argc, char** argv){
    if (argc < 2)

    {
        cout << "Error" << endl;
        return -1;
    }

    string video_path = argv[1];
    VideoCapture cap(video_path);

    int fps = cap.get(CAP_PROP_FPS);
    int width = cap.get(CAP_PROP_FRAME_WIDTH);
    int height  = cap.get(CAP_PROP_FRAME_HEIGHT);
    Size frame_size(width, height);
    VideoWriter writer("output_motion.mp4", VideoWriter::fourcc('m', 'p', '4', 'v'), fps, frame_size, false);
    Mat first_frame_color,thresh_frame, prev_frame_gray, curr_frame_color, curr_frame_gray, diff_frame;

    if(!cap.read(first_frame_color))
    {
        cout << "Error" << endl;
        return -1;
    }
    cvtColor(first_frame_color, prev_frame_gray, COLOR_BGR2GRAY);

    GaussianBlur(prev_frame_gray, prev_frame_gray, size(21,21), 0);

    while(cap.read(curr_frame_color))
    {
        cvtColor(curr_frame_color, curr_frame_gray, COLOR_BGR2GRAY);
        GaussianBlur(curr_frame_gray, curr_frame_gray, size(21,21), 0);

        absdiff(curr_frame_gray, prev_frame_gray, diff_frame);
        threshold(diff_frame, thresh_frame, 10, 255, THRESH_TOZERO);

        writer.write(thresh_frame);

        prev_frame_gray = curr_frame_gray.clone();
    }
    cap.release();
    writer.release();

    cout<< "video Proccesed" << endl;
}