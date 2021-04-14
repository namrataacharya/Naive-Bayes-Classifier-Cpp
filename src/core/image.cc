// Created by Namrata Acharya on 4/5/21.
#include <core/image_processor.h>
#include <core/naive_bayes_model.h>
#include <core/image.h>
#include <iostream>

namespace naivebayes {

    Image::Image(int label, int length, std::vector<std::vector<char>> &pixels) {
        label_ = label;
        length_ = length;
        pixels_ = pixels;
    }

    //used in sketchpad - OVERLOADED CONSTRUCTOR
    /*
    Image::Image(int length, std::vector<std::vector<char>> &pixels) {
        length_ = length;
        pixels_ = pixels;
    }*/

    //used in sketchpad
    Image::Image(int length) {
        length_ = length;
        //created 2d vector of pixels based on image length from sketchpad
        std::vector<std::vector<char>> copy_pixels (length, std::vector<char> (length));
        pixels_ = copy_pixels;
    }


    const int Image::GetLabel() {
        return label_;
    }

    const int Image::GetLength() {
        return length_;
    }

    /*
    const std::vector<std::vector<char>>& Image::GetPixels() {
        return pixels_;
    }*/

    //removed const return type so sketchpad can change image pixels
    std::vector<std::vector<char>>& Image::GetPixels() {
        return pixels_;
    }


    //added during classifier - WEEK 2
    void Image::SetLabel(int label) {
        label_ = label;
    }

}  // namespace naivebayes