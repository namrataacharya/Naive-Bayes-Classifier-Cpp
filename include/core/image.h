// Created by Namrata Acharya on 4/5/21.
#pragma once
#ifndef NAIVE_BAYES_IMAGE_H
#define NAIVE_BAYES_IMAGE_H
#endif // NAIVE_BAYES_IMAGE_H

#include <string>
#include <vector>

namespace naivebayes {
    class Image {

    public:

        /**
         * Constructor that creates new Image objects to be examined by the model
         * @param label - the number associated with the image
         * @param length - the image's dimensions (width/length)
         * @param pixels - 2d vector of characters representing a pixel
         */
        Image(int label, int length, std::vector<std::vector<char>> &pixels);

        /**
         * Constructor that creates new Image objects to be examined by the model
         * @param length - the image's dimensions (width/length)
         */
        Image(int length);

        /**
         * Gets the image's label
         * @return the label of the image
         */
        const int GetLabel();

        /**
         * Gets the image's dimensions (width/length)
         * @return the image's length
         */
        const int GetLength();

        /**
         * Gets the pixels of an image to be examined by the model
         * @return 2d array of chars representing an individual pixel
         */
        std::vector<std::vector<char>>& GetPixels();

        /**
         * Sets/changes an Image label
         * @param image label
         */
        void SetLabel(int label);

        std::vector<std::vector<char>> pixels_;

    private:

        int length_;
        int label_;

    };
}  // namespace naivebayes
