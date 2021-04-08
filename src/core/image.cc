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

    int Image::GetLabel() {
        return label_;
    }

    int Image::GetLength() {
        return length_;
    }

    std::vector<std::vector<char>>& Image::GetPixels() {
        return pixels_;
    }

}  // namespace naivebayes