#include <iostream>
#include <opencv2/opencv.hpp>
#include <cmath>
using namespace cv;
using namespace std;

int main()
{
    //Read an image
    Mat image = imread("pics/pearl.jpg", 1);
    int height = image.rows;
    int width = image.cols;
    cout << "Height and Width: " << image.rows << "x" << image.cols << "\n";
    //getting the pixel values
    int RED, GREEN, BLUE;
    tuple<int, int, int>** img_RGB = new tuple<int, int, int>* [height];

    //characters from lightest to darkest
    char characters[] = { '.', '`', '^', '\\', '"', ',', ':', ';', 'l', 'i', '~', '+', '_', '-', '?', ']', '[', '}', '{', '1', ')', '(', '|', '\\',
                '/', 't', 'f', 'j', 'r', 'x', 'n', 'u', 'v', 'c', 'z', 'X', 'Y', 'U', 'J', 'C', 'L', 'Q', '0', '0', 'Z', 'm', 'w', 'q', 'p', 'd', 'b', 'k', 'g', 'h', 'a',
                'o', '*','P', '#', 'A', 'M', 'W', 'R', '&', '8', '%', 'B', '@', '$'};

    const double k = 0.271;
    char** char_matrix = new char* [height];

    for (int i = 0; i < height; i++) {
        img_RGB[i] = new tuple<int, int, int>[width];
        char_matrix[i] = new char[width];
    }
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
        {
            BLUE = image.at<Vec3b>(i, j)[0];
            GREEN = image.at<Vec3b>(i, j)[1];
            RED = image.at<Vec3b>(i, j)[2];
            //turning RGB values to brightness by finding RGB average
            int brightness_average = (int)round((RED + BLUE + GREEN) / 3);
            int char_index = (int)round(brightness_average * k);
            char_matrix[i][j] = characters[char_index];
        }
    }
    //print out all the pixel values
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++)
        {
            //printing out each pixel three times, because terminal characters are
            //rectangles, three times as tall as they are wide
            cout << char_matrix[i][j] << char_matrix[i][j] << char_matrix[i][j];
        }
        cout << "\n";
    }
    //Free each sub-array
    for (int i = 0; i < height; i++) {
        delete[] img_RGB[i];
        delete[] char_matrix[i];
    }
    //Free the array of pointers
    delete[] img_RGB;
    delete[] char_matrix;

    return 0;
}
