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
        /*
        void SetSide(int side_length);
        int GetSide();

        //Image();
        //Image(int label, int length);*/

        //Image(int label, int length, const std::vector<std::vector<char>> &pixels); //NEW (didn't work)
        Image(int label, int length, std::vector<std::vector<char>> &pixels);

        int GetLabel();
        int GetLength();
        std::vector<std::vector<char>> GetPixels();

        //bool Shaded(int row, int col);

    private:
        int length_;
        int label_;
        //const std::vector<std::vector<char>> pixels_; //NEW (didn't work)
        std::vector<std::vector<char>> pixels_;

        //std::vector<std::vector<int>> pixels_(n, vector<int> (m));   //SIZE: n rows, m columns

    };
}  // namespace naivebayes
