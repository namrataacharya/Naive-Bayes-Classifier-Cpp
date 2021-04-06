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
        Image(int rows, int columns);
        Image(int side_length);*/
        /*
        void SetSide(int side_length);
        int GetSide();*/
        /*
        //Image();
        //Image(int label, int length);*/

        Image(int label, int length, std::vector<std::vector<char>> &pixels);

        int GetLabel();
        int GetLength();
        std::vector<std::vector<char>> GetPixels();

        //friend std::istream &operator>>(std::istream &in, std::string data);

    private:
        int length_;
        int label_;
        std::vector<std::vector<char>> pixels_;

        //std::vector<std::vector<int>> pixels_(n, vector<int> (m));   //SIZE: n rows, m columns

    };
}  // namespace naivebayes
