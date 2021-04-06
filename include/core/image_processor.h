// Created by Namrata Acharya on 4/5/21.

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
    int GetNumLabels();
    int GetNumImages();

    friend std::istream &operator>>(std::istream &in, ImageProcessor &processor);
    //std::istream &operator>>(std::istream &in, ImageProcessor &processor);

private:
    //std::vector<Image> images_;
    std::vector<Image> images_;

    //int label_;
    int image_length_;

    int test_num_labels_;
    int test_num_images;



};
}  // namespace naivebayes
