#include <core/naive_bayes_model.h>

namespace naivebayes {

Model::Model() {}

Model::Model(ImageProcessor &processor) {

    //created vector of training images for model
    for (int i = 0; i < processor.GetImages().size(); i++) {
        training_images_.push_back(processor.GetImages()[i]);
    }

    /*
    for (int i = 0; i < processor.GetClasses().size(); i++) {
        image_classes_.push_back(processor.GetClasses()[i]);
    }
    //sort(image_classes_.begin(), image_classes_.end()); //std::sort?
     */

    image_width_ = training_images_[0].GetLength(); //image dimensions
}


//use unordered map for storing class probability?? less run time with large amounts of data
void Model::TrainModel(int k) {
    k_ = k;

    FindClassFrequencies(); //should work - done?

    CalculateClassProbability();

    CalculatePixelProbability();
}


void Model::FindClassFrequencies() {
    for (Image &image : training_images_) {
        class_frequency_[image.GetLabel()]++; //updates #times label is found w/ label as key
    }
    v_ = class_frequency_.size();

    //std::vector<std::vector<std::vector<std::vector<int>>>> class_freq_vector;
}

    // (k_ + class_frequency_[c]) / (10k_ + training_images_.size())
    // (# of classes = 10 --> v_)
void Model::CalculateClassProbability() { // P(class = c)
    //class_probability (unordered map)

    for (int i = 0; i < class_frequency_.size(); i++) {
        double probability = (k_ + class_frequency_[i]) / ((v_ * k_) + training_images_.size());
        class_probability_[i] = probability;
    }
}

void Model::CalculatePixelProbability() { //int i, int j, int c) {

    //vector<vector<vector<vector<int>>>> vec(100, vector<vector<vector<int>>>(200, vector<vector<int>>(100, vector<int>(50))));

    int v = 2;

    std::vector<
            std::vector<
                    std::vector<
                            std::vector<int>>>> pixel_match_count(image_width_,
                                                           std::vector<std::vector<std::vector<int>>>(image_width_,
                                                           std::vector<std::vector<int>>(v, //true or false (n)
                                                           std::vector<int>(class_frequency_.size()))));

    //map[row (i)][col (j)][shaded (bool)][class (c)] - see slides

    //stores the # of images of class c where pixel is specified shade (numerator)
    for (auto class_c : class_frequency_) {
        int c = class_c.first;

        for (Image &image : training_images_) {
            if (image.GetLabel() == c) {
                for (int i = 0; i < image.GetLength(); i++) {
                    for (int j = 0; j < image.GetLength(); j++) {
                        if (PixelShaded(image, i, j) == true) {
                            pixel_match_count[i][j][1][c]++; // 1 = SHADED
                        } else {
                            pixel_match_count[i][j][0][c]++; // 1 = UNSHADED
                        }
                    }
                }
            }
        }
    }

    //put probabilities into pixel_probability vector

    for (int i = 0; i < image_width_; i++) {
        for (int j = 0; j < image_width_; j++) {
            for (int shade = 0; shade < v; shade++) {
                for (int c = 0; c < class_frequency_.size(); c++) {
                    pixel_probability_[i][j][shade][c] = (k_ + pixel_match_count[i][j][shade][c])
                            / ((v * k_) + class_frequency_.at(c));
                }
            }
        }
    }

    /*
    std::vector<
            std::vector<
                    std::vector<
                            std::vector<int>>>> class_freq_vector;*/

}



bool Model::PixelShaded(Image &image, int row, int col) {
    /*if (image.GetPixels()[row][col] == " ") {
        return false;
    }*/
    /*
    if (std::strcmp(image.GetPixels()[row][col], " ")) {
        return false;
    }
    return true;
     */

    if (image.GetPixels()[row][col] == ' ') {
        return false; // 0 = unshaded
    }
    return true; // 1 = shaded
}


void Model::LoadModel() {}

void Model::SaveModel() {}

/*
std::vector<int> Model::GetImageClasses() {
    return image_classes_;
}

std::vector<Image> Model::GetTrainingImages() {
    return training_images_;
}*/

}  // namespace naivebayes