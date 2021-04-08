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

        Image(int label, int length, std::vector<std::vector<char>> &pixels);

        int GetLabel();

        int GetLength();

        std::vector<std::vector<char>>& GetPixels();

    private:

        int length_;
        int label_;

        std::vector<std::vector<char>> pixels_;

    };
}  // namespace naivebayes
