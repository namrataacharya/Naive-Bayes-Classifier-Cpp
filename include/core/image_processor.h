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

    /**
     * Default constructor that creates an processor
     */
    ImageProcessor();

    /**
     * Gets the images found in the txt file
     * @return vector of Image objects
     */
    const std::vector<Image>& GetImages();

    /**
     * Gets the distinct labels/image classes found in the txt file
     * @return vector of distinct image labels
     */
    const std::vector<int>& GetClasses();

    /**
     * Gets the length the images found in the txt file
     * @return number representing image length
     */
    const int GetImageLength();

    /**
     * Overloads >> operator and reads contents of txt file
     */
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
