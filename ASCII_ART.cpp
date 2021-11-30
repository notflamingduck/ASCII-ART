#include <iostream>
#include <opencv2/opencv.hpp>
#include <cmath>
using namespace cv;
using namespace std;

int main()
{
    //Read an image
    Mat image = imread("pics/oneRing.jpg", 1);
    int height = image.rows;
    int width = image.cols;
    cout << "Height and Width: " << image.rows << "x" << image.cols << "\n";

    int B = image.at<Vec3b>(10, 29)[0];//getting the pixel values//
    int G = image.at<Vec3b>(10, 29)[1];//getting the pixel values//
    int R = image.at<Vec3b>(10, 29)[2];//getting the pixel values//
    
    tuple<int, int, int>** img_RGB = new tuple<int, int, int>* [height];

    char characters[] = { '.', '`', '^', '\\', '"', ',', ':', ';', 'l', 'i', '~', '+', '_', '-', '?', ']', '[', '}', '{', '1', ')', '(', '|', '\\',
                '/', 't', 'f', 'j', 'r', 'x', 'n', 'u', 'v', 'c', 'z', 'X', 'Y', 'U', 'J', 'C', 'L', 'Q', '0', '0', 'Z', 'm', 'w', 'q', 'p', 'd', 'b', 'k', 'g', 'h', 'a',
                'o', '*','P', '#', 'A', 'M', 'W', 'R', '&', '8', '%', 'B', '@', '$'};

    double k = 0.271;
    char** char_matrix = new char* [height];

    for (int i = 0; i < height; i++) {
        img_RGB[i] = new tuple<int, int, int>[width];
        char_matrix[i] = new char[width];
    }
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
        {
            B = image.at<Vec3b>(i, j)[0];
            G = image.at<Vec3b>(i, j)[1];
            R = image.at<Vec3b>(i, j)[2];

            int brightness_average = round((R + B + G) / 3);
            int char_index = round(brightness_average * k);
            char_matrix[i][j] = characters[char_index];
        }
    }

    //print out all the pixel values
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
        {
            cout << char_matrix[i][j] << char_matrix[i][j] << char_matrix[i][j];
        }
        cout << "\n";
    }

    for (int i = 0; i < height; i++) {
        delete[] img_RGB[i];
        delete[] char_matrix[i];
    }
    delete[] img_RGB;
    delete[] char_matrix;

    return 0;

}
