/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: March 21, 2022
Assignment: Lab 8G

This program reads a PGM image and uses horizontal edge detection to edit the image.
*/

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

using namespace std;

const int MAX_H = 512;
const int MAX_W = 512;

// Reads a PGM file.
// Notice that: height and width are passed by reference!
void readImage(int image[MAX_H][MAX_W], int &height, int &width) {
    char c;
    int x;
    ifstream instr;
    instr.open("inImage.pgm");

    // read the header P2
    instr >> c;
    assert(c == 'P');
    instr >> c;
    assert(c == '2');

    // skip the comments (if any)
    while ((instr>>ws).peek() == '#') {
        instr.ignore(4096, '\n');
    }

    instr >> width;
    instr >> height;

    assert(width <= MAX_W);
    assert(height <= MAX_H);
    int max;
    instr >> max;
    assert(max == 255);

    for (int row = 0; row < height; row++)
        for (int col = 0; col < width; col++)
            instr >> image[row][col];
    instr.close();
    return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(int image[MAX_H][MAX_W], int height, int width) {
    ofstream ostr;
    ostr.open("outImage.pgm");
    if (ostr.fail()) {
        cout << "Unable to write file\n";
        exit(1);
    };

    // print the header
    ostr << "P2" << endl;
    // width, height
    ostr << width << ' ';
    ostr << height << endl;
    ostr << 255 << endl;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            assert(image[row][col] < 256);
            assert(image[row][col] >= 0);
            ostr << image[row][col] << ' ';
            ostr << endl;
        }
    }
    ostr.close();
    return;
}

int main() {

    int img[MAX_H][MAX_W];
    int h, w;

    readImage(img, h, w); // read it from the file "inImage.pgm"
    // h and w were passed by reference and now contain the dimensions of the picture and the 2-dimesional array img contains the image data

    // Now we can manipulate the image the way we like, for example we copy its contents into a new array
    int out[MAX_H][MAX_W];
    int sum = 0;
    
    int sobel[MAX_H][MAX_W] = { {1,2,1},
                                {0,0,0},
                                {-1,-2,-1}};
    
   /* for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            if (row <= 3/2 || row >= (h-3)/2 || col <= 3/2 || col >= (w-3)/2) {
                out[row][col] = 0;
            }
            else {
                sum = 0;
                out[row][col] = sum;
                if (out[row][col] < 0) out[row][col] = 0;
                else if (out[row][col] > 255) out[row][col] = 255;
            }
        }
    }*/
   
    for(int row = 0; row < h; row+=3) {
        for(int col = 0; col < w; col+=3) {
            if (row <= 3/2 || row >= (h-3)/2 || col <= 3/2 || col >= (w-3)/2) {
                out[row][col] = 0;
            }
            else {
                sum += img[row][col] * 1;
                sum += img[row][col+1] * 2;
                sum += img[row][col+2] * 1;
                sum += img[row+1][col] * 0;
                sum += img[row+1][col+1] * 0;
                sum += img[row+1][col+2] * 0;
                sum += img[row+2][col] * -1;
                sum += img[row+2][col+1] * -2;
                sum += img[row+2][col+2] * -1;

                if (sum < 0) sum = 0;
                else if (sum > 255) sum = 255;
                out[row+1][col+1] = sum;
                
                sum = 0;
            }
        }
    }
                
    // and save this new image to file "outImage.pgm"
    writeImage(out, h, w);

}
/*
 out[row][col] = img[row][col+1] * -1;
 out[row][col+2] = img[row][col+1] * 1;
 out[row+1][col] = img[row+1][col+1] * -2;
 out[row+1][col+2] = img[row+1][col+1] * 2;
 out[row+2][col] = img[row+2][col+1] * -1;
 out[row+2][col+2] = img[row+2][col+1] * 1;
 out[row][col+1] = 0;
 out[row+1][col+1] = 0;
 out[row+2][col+1] = 0;
 */
/*
 else {
     int a = img[row][col] * 1;
     int b = img[row][col+1] * 2;
     int c = img[row][col+2] * 1;
     int d = img[row+1][col] * 0;
     int e = img[row+1][col+1] * 0;
     int f = img[row+1][col+2] * 0;
     int g = img[row+2][col] * -1;
     int h = img[row+2][col+1] * -2;
     int i= img[row+2][col+2] * -1;

     sum = (g+(2*h)+i)-(a+(2*b)+c);
     
     if (sum < 0) sum = 0;
     else if (sum > 255) sum = 255;
     out[row+1][col+1] = sum;
     
     sum = 0;
 }
 */
