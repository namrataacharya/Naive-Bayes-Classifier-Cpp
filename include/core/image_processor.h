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
    //void SetSide(int side_length);
    //int GetSide();

    std::vector<Image> GetImages();
    int GetImageLength();
    void SetImageLength(int length);


    int GetNumLabels();
    int GetNumImages();
    int GetLineCount();
    int GetLineCount2();

    /*
    void LabelsPlus1(); //testing
    void ImagesPlus1(); //testing*/

    friend std::istream &operator>>(std::istream &in, ImageProcessor &processor);
    //std::istream &operator>>(std::istream &in, ImageProcessor &processor);

private:

    std::vector<Image> images_;

    //int label_;
    int image_length_;

    int test_num_labels_;
    int test_num_images;

    int line_count_ = 1;
    int line_count_2_ = 1;



};
}  // namespace naivebayes
