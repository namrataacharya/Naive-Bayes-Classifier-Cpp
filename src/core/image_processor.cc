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

    std::vector<int> ImageProcessor::GetClasses() {
        return classes_;
    }

    int ImageProcessor::GetImageLength() { //TESTING
        return image_length_;
    }

    /*
    void ImageProcessor::SetImageLength(int length) {
        image_length_ = length;
    }*/

    /*
    int ImageProcessor::GetNumImages() { //TESTING
        return test_num_images;
    }

    int ImageProcessor::GetNumLabels() { //TESTING
        return test_num_labels_;
    }*/

    std::istream &operator>>(std::istream &in, ImageProcessor &processor) {

        int current_line = 1;
        int side_length;

        std::string line1;
        int line_count = 1;

        while (getline(in, line1)) {
            if (line_count == 2) {   // lines in txt file AFTER label
                side_length = line1.size(); // image length/width

                processor.image_length_ = side_length;
                break;
            }
            line_count++;
            processor.line_count_++;
        }

        in.seekg(0);

        //finds image labels & creates image objects to be examined in Model
        std::string line;
        int label;
        std::vector<std::vector<char>> pixels;
        current_line = 1;

        while (getline(in, line)) {

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

                //check if new image class/label has been found
                int label_freq = 0;
                for (int i = 0; i < processor.classes_.size(); i++) {
                    if (label == processor.classes_[i]) {
                        label_freq++;
                    }
                }

                if(label_freq == 0) {
                    processor.classes_.push_back(label); //adds new image class/label to classes_ vector
                }

                processor.images_.push_back(image);
                processor.test_num_images++;
                pixels.clear();
            }

            current_line++;
        }

        return in;
    }

}  // namespace naivebayes