// Created by Namrata Acharya on 4/5/21.
#include <core/image_processor.h>
#include <core/naive_bayes_model.h>
#include <core/image.h>
#include <iostream>

namespace naivebayes {

    Image::Image() {}

    Image::Image(int label, int length) {
        label_ = label;
        length_ = length;
    }

    Image::Image(int label, int length, std::vector<std::vector<int>> &pixels) {
        label_ = label;
        length_ = length;
        pixels_ = pixels;
    }



    /*
    Image::Image(int rows, int columns) {
        side_ = rows;
    }*/
    /*
    std::istream &operator>>(std::istream &in, std::string training_data) { //Image img) { //std::string training_data) {
        std::string line;
        while(getline(in, line)) {
            //side

        }
        return in;
    }*/

}  // namespace naivebayes