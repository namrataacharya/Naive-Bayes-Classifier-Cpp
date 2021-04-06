// Created by Namrata Acharya on 4/5/21.
#include <core/image_processor.h>
#include <core/naive_bayes_model.h>
#include <core/image.h>

#include <iostream>

namespace naivebayes {

    ImageProcessor::ImageProcessor() {}

    int ImageProcessor::GetNumImages() { //TESTING
        return test_num_images;
    }

    int ImageProcessor::GetNumLabels() { //TESTING
        return test_num_labels_;
    }

    std::istream &operator>>(std::istream &in, ImageProcessor &processor) {
        int line_count = 1;
        int side_length;
        //int label;
        //std::vector<char> pixels(side_length);      // pixels.push_back()
        //std::vector<std::vector<char>> pixels_(side_length, std::vector<char> (side_length));

        std::string line;

        // finds image dimensions
        while (getline(in, line)) {
            if (line_count == 2) {   // lines in txt file AFTER label
                side_length = line.size(); // image length/width

                processor.image_length_ = side_length;
                break;
            }
            line_count++;
        }

        //finds image labels & creates image objects to be examined in Model
        int label;
        //std::vector<char> pixels(side_length);
        //std::vector<std::vector<char>> pixels_;
        std::vector<std::vector<char>> pixels;
        line_count = 1;
        int image_line_count = 1;
        int index;

        while (getline(in, line)) {
            /*
            if (line_count == 1) { //first label
                Image image;
                label = std::stoi(line); //sets label

            } else { //other image labels
                if ((line_count + side_length) % (line_count + side_length) == 0) {  //if at next label
                    Image image;
                    label = std::stoi(line); //sets label
                }
            }*/
            if (line_count == 1) { //first label
                //Image image;
                label = std::stoi(line);
                processor.test_num_labels_++; //DELETE - testing

            } else if ((line_count + side_length) % (line_count + side_length) == 0) {
                //Image image;
                label = std::stoi(line);
                processor.test_num_labels_++; //DELETE - testing

            } else { //if not at label line, add image lines to 2d vector
                pixels[0] = std::vector<char>(line.begin(), line.end()); //would this work ?

                index++;
                image_line_count++;
            }

            if (image_line_count == side_length) {
                //Image image = Image(label, side_length); //add pixel vector as 3rd parameter
                Image image = Image(label, side_length, pixels);
                processor.images_.push_back(image);
                index = 0;
                image_line_count = 1;
                pixels.clear();

                //DELETE - for testing
                processor.test_num_images++;
            }

            line_count++;
        }

        return in;
    }

}  // namespace naivebayes