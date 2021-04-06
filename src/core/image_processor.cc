// Created by Namrata Acharya on 4/5/21.
#include <core/image_processor.h>
#include <core/naive_bayes_model.h>
#include <core/image.h>

#include <iostream>

namespace naivebayes {

    ImageProcessor::ImageProcessor() {}

    std::istream &operator>>(std::istream &in, ImageProcessor &processor) {
        int line_count = 1;
        int side_length;
        std::string line;


        // finds image dimensions
        while (getline(in, line)) {
            if (line_count == 2) {   // lines in txt file AFTER label
                side_length = line.size(); // image length/width
                break;
            }
            line_count++;
        }


        //std::vector<std::vector<char>> pixels_(side_length, std::vector<char> (side_length));
        std::vector<char> pixels(side_length); // pixels.push_back()

        //finds image labels & creates image objects to be examined in Model
        line_count = 1;
        while (getline(in, line)) {
            Image image;

            if (line_count == 1) { //first label
                image = Image();

            } else { //following image labels

            }



            line_count++;
        }




        return in;
    }

}  // namespace naivebayes