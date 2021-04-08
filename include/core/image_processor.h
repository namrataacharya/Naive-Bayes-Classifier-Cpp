// Created by Namrata Acharya on 4/5/21.
#pragma once
#ifndef NAIVE_BAYES_IMAGE_PROCESSOR_H
#define NAIVE_BAYES_IMAGE_PROCESSOR_H
#endif //NAIVE_BAYES_IMAGE_PROCESSOR_H
#include <string>
#include <vector>
#include "image.h"

namespace naivebayes {
class ImageProcessor {

public:
    ImageProcessor();

    std::vector<Image> GetImages();

    std::vector<int> GetClasses();

    int GetImageLength();

    int GetNumImages();

    int GetNumLabels();

    friend std::istream &operator>>(std::istream &in, ImageProcessor &processor);

private:

    std::vector<Image> images_;
    std::vector<int> classes_;

    int image_length_;
    int test_num_labels_;
    int test_num_images;
    int line_count_ = 1;

};
}  // namespace naivebayes
