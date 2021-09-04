#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char *argv[])
{
    // Make sure the commandline arguments are correct
    if (argc < 3)
    {
        std::cout << "Usage:\n\t./rgb2gray input_color_image_filename output_grayscale_image_filename" << std::endl;
        return 1;
    }
    std::string inpImagePath = argv[1];
    std::string outImagePath = argv[2];

    // Read the image
    cv::Mat image = cv::imread(inpImagePath, -1);
    int H = image.size[0];
    int W = image.size[1];
    
    // Initialize an empty grayscale image (8-bit unsigned integer matrix with one channel)
    cv::Mat imageGray(H, W, CV_8UC1);

    // Loop through the pixels of the image
    for (int r = 0; r < H; r++)
    {
        for (int c = 0; c < W; c++)
        {
            // Retrieve the pixel from location (r, c)
            cv::Vec3b pix = image.at<cv::Vec3b>(r, c);
            
            // Apply formula to get the grayscale value and assign it to imageGray
            uint8_t res = 0.2989 * pix[2] + 0.5871 * pix[1] + 0.1140 * pix[0];
            imageGray.at<uint8_t>(r, c) = res;
        }
    }
    
    // Show original and grayscale images
    cv::imshow("Image", image);
    cv::imshow("ImageGray", imageGray);
    
    // Save the image to the output location
    cv::imwrite(outImagePath, imageGray);

    // Wait for keyboard input to close imshow windows
    cv::waitKey(0);
    return 0;
}
