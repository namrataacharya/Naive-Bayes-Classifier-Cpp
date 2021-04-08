#include <core/naive_bayes_model.h>
#include <iostream>

namespace naivebayes {

Model::Model() {}

Model::Model(ImageProcessor &processor) {

    //created vector of training images for model
    for (int i = 0; i < processor.GetImages().size(); i++) {
        training_images_.push_back(processor.GetImages()[i]);
    }

    //VECTOR IMPLEMENTATION
    num_classes_ = processor.GetClasses().size();
    for (int i = 0; i < num_classes_; i++) {
        class_frequencies_.push_back(0); //creates vector w/ size = num of image classes
        class_probabilities_.push_back(0);
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

    FindClassFrequencies();
    CalculateClassProbability();
    CalculatePixelProbability();
}


void Model::FindClassFrequencies() {
    //DELETE THIS
    /*
    for (Image &image : training_images_) {
        class_frequency_[image.GetLabel()]++; //updates #times label is found w/ label as key
    }*/

    //VECTOR IMPLEMENTATION - KEEP THIS
    for (Image &image : training_images_) {
        class_frequencies_[image.GetLabel()]++;
    }
    //v_ = class_frequencies_.size();
}

    // (k_ + class_frequency_[c]) / (10k_ + training_images_.size())
    // (# of classes = 10 --> v_)
void Model::CalculateClassProbability() { // P(class = c)
    //DELETE THIS ?
    /*
    for (int i = 0; i < class_frequency_.size(); i++) {
        double probability = (k_ + class_frequency_[i]) / ((v_ * k_) + training_images_.size());
        class_probability_[i] = probability;
    }*/
    int v = class_frequencies_.size();

    //VECTOR IMPLEMENTATION - KEEP THIS
    for (int i = 0; i < num_classes_; i++) {
        double probability = (double(k_ + class_frequencies_[i]) / double((v * k_) + training_images_.size()));
        class_probabilities_[i] = probability;
    }
}

void Model::CalculatePixelProbability() { // P(F(i,j) = f | class = c)
    int v = 2;

    std::vector<
            std::vector<
                    std::vector<
                            std::vector<double>>>> pixel_match_count(image_width_,
                                                      std::vector<std::vector<std::vector<double>>>(image_width_,
                                                      std::vector<std::vector<double>>(v,  // T(1)/F(0)
                                                      std::vector<double>(num_classes_))));

    //vector[row (i)][col (j)][shaded (0 or 1)][class (c)] - see slides

    pixel_probability_ = pixel_match_count;

    //VECTOR IMPLEMENTATION
    //stores the # of images of class c where pixel is specified shade (numerator)
    for (int c = 0; c < num_classes_; c++) {
        for (Image &image : training_images_) {
            if (image.GetLabel() == c) {
                for (int i = 0; i < image_width_; i++) {
                    for (int j = 0; j < image_width_; j++) {
                        if (PixelShaded(image, i, j) == true) {
                            pixel_match_count[i][j][1][c]++; // 1 = SHADED

                        } else {
                            pixel_match_count[i][j][0][c]++; // 0 = UNSHADED

                        }
                    }
                }
            }
        }
    }

    //VECTOR IMPLEMENTATION
    ///*

    for (int i = 0; i < image_width_; i++) {
        for (int j = 0; j < image_width_; j++) {
            for (int shade = 0; shade < v; shade++) {
                for (int c = 0; c < class_frequencies_.size(); c++) {
                    pixel_probability_[i][j][shade][c] = (double(k_ + pixel_match_count[i][j][shade][c])
                            / double((v * k_) + class_frequencies_[c]));
                }
            }
        }
    }
     //*/

    //OLD WAY - DELETE?
    /*
    for (auto class_c : class_frequency_) {
        int c = class_c.first;

        for (Image &image : training_images_) {
            if (image.GetLabel() == c) {
                for (int i = 0; i < image.GetLength(); i++) {
                    for (int j = 0; j < image.GetLength(); j++) {
                        if (PixelShaded(image, i, j) == true) {
                            pixel_match_count[i][j][1][c]++; // 1 = SHADED
                            pixel_match_count[i][j][0][c] += 0; // ??
                        } else {
                            pixel_match_count[i][j][0][c]++; // 0 = UNSHADED
                            pixel_match_count[i][j][1][c] += 0; // ???
                        }
                    }
                }
            }
        }
    }
     */
    //OLD WAY - DELETE
    /*
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
    }*/
    /*
    std::vector<
            std::vector<
                    std::vector<
                            std::vector<int>>>> class_freq_vector;*/
    /*
    std::unordered_map<int, std::unordered_map<int,
            std::unordered_map<bool, std::unordered_map<int, double>>>> pixel_match_count;

    //map[row (i)][col (j)][shaded (bool)][class (c)] - see slides


    for (int i = 0; i < class_frequency_.size(); i++) {
        int c  = class_frequency_[i].first;
    }

    for (auto class_c : class_frequency_) {
        int c = class_c.first;

        //finds images of class c
        for (Image &image : training_images_) {
            if (image.GetLabel() == c) {
                for (int i = 0; i < image.GetLength(); i++) {
                    for (int j = 0; j < image.GetLength(); j++) {

                        if (PixelShaded(image, i, j) == true) {
                            pixel_match_count[i][j][true][c]++;

                        } else {
                            pixel_match_count[i][j][false][c]++;
                        }
                    }
                }
            }
        }
    }
     */ //DELETE
}

bool Model::PixelShaded(Image &image, int row, int col) {
    if (image.GetPixels()[row][col] == '#' || image.GetPixels()[row][col] == '+') {
        return true; // 0 = unshaded
    }
    return false; // 1 = shaded
}

double Model::GetClassProbability(int c) {
    //return class_probability_.at(c); //old way
    return class_probabilities_[c]; //vector way
}

double Model::GetPixelProbability(double row, double col, double shaded, double c) {

    if (shaded == true) {
        return pixel_probability_[row][col][1][c]; //shaded
    }
    return pixel_probability_[row][col][0][c]; //unshaded
}
/*
double Model::GetPixelProbability(int row, int col, bool shaded, int c) {
    if (shaded == true) {
        return pixel_probability_[row][col][1][c]; //shaded
    }
    return pixel_probability_[row][col][0][c]; //unshaded
}
 */


// >> - Loads Model from file (OVERLOAD)
std::istream &operator>>(std::istream &in, Model &model) {

    int num_classes;
    in >> num_classes;
    model.num_classes_ = num_classes;

    for (int i = 0; i < num_classes; i++) {
        double probability;
        in >> probability;

        model.class_probabilities_.push_back(0.0);
        model.class_probabilities_[i] = probability;
    }

    std::string line;

    while (getline(in,line)) {
        int i;
        int j;
        int shade;
        int c;
        double probability;
        in >> i >> j >> shade >> c >> probability;
        model.image_width_ = i;
        model.pixel_probability_[i][j][shade][c] = probability;
    }

    return in;
}

// << - Save Model to file (OVERLOAD)
std::ostream &operator<<(std::ostream &out, Model &model) {

    int num_classes = model.class_probabilities_.size();
    out << num_classes << std::endl;

    for (int i = 0; i < num_classes; i++) {
        out << model.class_probabilities_[i] <<std::endl;
    }

    for (int i = 0; i < model.image_width_; i++) {
        for (int j = 0; j < model.image_width_; j++) {
            for (int shade = 0; shade < model.v_; shade++) {
                for (int c = 0; c < model.class_frequencies_.size(); c++) {

                    out << i << std::endl;
                    out << j << std::endl;
                    out << shade << std::endl;
                    out << c << std::endl;
                    out << model.pixel_probability_[i][j][shade][c] << std::endl;

                }
            }
        }
    }

    return out;
}

/*
std::vector<int> Model::GetImageClasses() {
    return image_classes_;
}
 */

std::vector<Image> Model::GetTrainingImages() {
    return training_images_;
}

}  // namespace naivebayes