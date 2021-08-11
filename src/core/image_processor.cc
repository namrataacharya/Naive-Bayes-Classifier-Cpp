// Created by Namrata Acharya on 4/5/21.
#include <core/image_processor.h>
#include <core/naive_bayes_model.h>
#include <core/image.h>
#include <iostream>

namespace naivebayes {

    ImageProcessor::ImageProcessor() {}

    const std::vector<Image>& ImageProcessor::GetImages() {
        return images_;
    }

    const std::vector<int>& ImageProcessor::GetClasses() {
        return classes_;
    }

    const int ImageProcessor::GetImageLength() {
        return image_length_;
    }

    std::istream &operator>>(std::istream &in, ImageProcessor &processor) {

        int current_line = 1;
        int side_length;

        std::string line1;
        int line_count = 1;

        while (getline(in, line1)) {
            if (line_count == 2) {
                side_length = line1.size();

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
                label = std::stoi(line);
                processor.test_num_labels_++;

                for (int i = 0; i < side_length; i++) {
                    getline(in, line);
                    pixels.push_back(std::vector<char>(line.begin(), line.end()));
                }

                //Image image = Image(label, side_length, pixels); //OG WAY OF CREATING IMAGE OBJ
                const Image image = Image(label, side_length, pixels);


                //check if new image class/label has been found
                int label_freq = 0;
                for (int i = 0; i < processor.classes_.size(); i++) {
                    if (label == processor.classes_[i]) {
                        label_freq++;
                    }
                }

                //adds new image class/label to classes_ vector
                if(label_freq == 0) {
                    processor.classes_.push_back(label);
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