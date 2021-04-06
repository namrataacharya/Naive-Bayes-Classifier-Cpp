// Created by Namrata Acharya on 4/5/21.
#include <core/image_processor.h>
#include <core/naive_bayes_model.h>
#include <core/image.h>
#include <iostream>

namespace naivebayes {

    ImageProcessor::ImageProcessor() {}


    std::vector<Image> ImageProcessor::GetImages() {
        return images_;
    }

    int ImageProcessor::GetImageLength() { //TESTING
        return image_length_;
    }

    void ImageProcessor::SetImageLength(int length) {
        image_length_ = length;
    }

    int ImageProcessor::GetNumImages() { //TESTING
        return test_num_images;
    }

    int ImageProcessor::GetNumLabels() { //TESTING
        return test_num_labels_;
    }

    int ImageProcessor::GetLineCount() { //TESTING
        return line_count_;
    }

    int ImageProcessor::GetLineCount2() { //TESTING
        return line_count_2_;
    }

    /*
    void ImageProcessor::ImagesPlus1() {
        test_num_images++;
    }
    void ImageProcessor::LabelsPlus1() {
        test_num_images++;
    }*/

    std::istream &operator>>(std::istream &in, ImageProcessor &processor) {
        //int line_count = 1;
        //std::istream side_length_check(in);


        int current_line = 1;
        int side_length;

        //old version - 2 while loops (delete?)
        std::string line1;
        int line_count = 1;
        /*
        //int label;
        //std::vector<char> pixels(side_length);      // pixels.push_back()
        //std::vector<std::vector<char>> pixels_(side_length, std::vector<char> (side_length));*/
        /*
        //std::string line1;
        //processor.line_count_2_++;
        // finds image dimensions*/
        //*
        while (getline(in, line1)) {
            if (line_count == 2) {   // lines in txt file AFTER label
                side_length = line1.size(); // image length/width

                processor.image_length_ = side_length;
                break;
            }
            line_count++;
            processor.line_count_++;
        }//*/

        in.seekg(0);

        //finds image labels & creates image objects to be examined in Model
        std::string line;
        int label;
        std::vector<std::vector<char>> pixels;
        current_line = 1;
        //int image_line_count = 1;
        //int index;

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
            /*
            if (line_count == 1) { //first label
                //Image image;
                label = std::stoi(line);

                processor.test_num_labels_++; //DELETE - testing

            } else if ((line_count + side_length) % (line_count + side_length) == 0) { //other labels
                //Image image;
                label = std::stoi(line);

                processor.test_num_labels_++; //DELETE - testing

            } else { //if not at label line, add image lines to 2d vector

                pixels[0] = std::vector<char>(line.begin(), line.end()); //would this work ?

                index++;
                image_line_count++;
            }*/

            //finds image dimensions - see old while loop
            /*
            if (current_line == 2) {
                side_length = line.size();
                processor.image_length_ = side_length;
            }*/

            //finds labels
            if (line.size() == 1) {
                // for loop goes 28 times
                label = std::stoi(line);
                processor.test_num_labels_++;

                for (int i = 0; i < side_length; i++) {
                    getline(in, line);
                    pixels.push_back(std::vector<char>(line.begin(), line.end()));
                }

                Image image = Image(label, side_length, pixels);

                processor.images_.push_back(image);
                processor.test_num_images++;
                pixels.clear();

            } /* else {
                //pixels[index] = std::vector<char>(line.begin(), line.end()); //????
                pixels.push_back(std::vector<char>(line.begin(), line.end()));
                index++;
                */

            /*
            if (image_line_count == side_length) { //creates Image with label

                Image image = Image(label, side_length, pixels);
                processor.test_num_images++;
                processor.images_.push_back(image);

                index = 0;
                image_line_count = 1;
                pixels.clear();

                //DELETE - for testing

            }*/

            current_line++;
        }

        return in;
    }

}  // namespace naivebayes