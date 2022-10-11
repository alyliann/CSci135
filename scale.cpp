/*
Author: Alysa Liann Vega
Course: CSCI-135
Instructor: Tong Yi
Date: March 18, 2022
Assignment: Lab 8E

This program reads a PGM image and outputs the image at 200% the original scale.
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
    int temp[2][2];
    
    for(int row = 0; row < h; row++) {
        for(int col = 0; col < w; col++) {
            for (int r = 0; r < 2; r++) {
                for (int c = 0; c < 2; c++) {
                    temp[r][c] = img[row][col];
                    out[2*row][2*col] = temp[r][c];
                    out[2*row][(2*col)+1] = temp[r][c];
                    out[(2*row)+1][(2*col)+1] = temp[r][c];
                    out[(2*row)+1][2*col] = temp[r][c];
                }
            }
        }
    }

    // and save this new image to file "outImage.pgm"
    writeImage(out, (2*h), (2*w));

}

