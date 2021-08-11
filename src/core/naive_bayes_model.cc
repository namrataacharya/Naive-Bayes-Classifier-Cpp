#include <core/naive_bayes_model.h>
#include <iostream>

namespace naivebayes {

Model::Model() {}

Model::Model(ImageProcessor &processor) {

    //creates vector of training images for model
    for (int i = 0; i < processor.GetImages().size(); i++) {
        training_images_.push_back(processor.GetImages()[i]);
    }

    num_classes_ = processor.GetClasses().size();
    for (int i = 0; i < num_classes_; i++) {
        //creates vector w/ size = num of image classes
        class_frequencies_.push_back(0);
        class_probabilities_.push_back(0);
    }

    //sets image dimensions
    image_width_ = training_images_[0].GetLength();
}

void Model::TrainModel(int k) {
    k_ = k;

    FindClassFrequencies();
    CalculateClassProbability();
    CalculatePixelProbability();
}

void Model::FindClassFrequencies() {

    for (Image &image : training_images_) {
        class_frequencies_[image.GetLabel()]++;
    }
}

// P(class = c)
void Model::CalculateClassProbability() {
    int v = class_frequencies_.size();

    for (int i = 0; i < num_classes_; i++) {
        double probability = (double(k_ + class_frequencies_[i]) / double((v * k_) + training_images_.size()));
        class_probabilities_[i] = probability;
    }
}

// P(F(i,j) = f | class = c)
void Model::CalculatePixelProbability() {
    int v = 2;

    std::vector<
            std::vector<
                    std::vector<
                            std::vector<double>>>> pixel_match_count(image_width_,
                                                      std::vector<std::vector<std::vector<double>>>(image_width_,
                                                      std::vector<std::vector<double>>(v,  // T(1)/F(0)
                                                      std::vector<double>(num_classes_))));

    pixel_probability_ = pixel_match_count;

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
}

bool Model::PixelShaded(Image &image, int row, int col) {
    if (image.GetPixels()[row][col] == '#' || image.GetPixels()[row][col] == '+') {
        return true; // 1 = shaded
    }
    return false; // 0 = unshaded
}

double Model::GetClassProbability(int c) {
    return class_probabilities_[c];
}

double Model::GetPixelProbability(double row, double col, double shaded, double c) {
    if (shaded == true) {
        return pixel_probability_[row][col][1][c];
    }
    return pixel_probability_[row][col][0][c];
}

// >> - Loads Model from file (OVERLOAD)
std::istream &operator>>(std::istream &in, Model &model) {

    int width;
    in >> width;
    model.image_width_ = width;

    int num_classes;
    in >> num_classes;
    model.num_classes_ = num_classes;

    for (int i = 0; i < num_classes; i++) {
        double probability;
        in >> probability;

        model.class_probabilities_.push_back(0.0);
        model.class_probabilities_[i] = probability;
    }

    //initializes 4d pixel probability vector
    std::vector<
        std::vector<
            std::vector<
                std::vector<double>>>> pixel_vector(width, std::vector<std::vector<std::vector<double>>>(width,
                                                                std::vector<std::vector<double>>(model.v_,
                                                                   std::vector<double>(model.num_classes_))));

    model.pixel_probability_ = pixel_vector;
    while (!in.eof()) {
        int i;
        int j;
        int shade;
        int c;
        double probability;

        in >> i >> j >> shade >> c >> probability;
        model.pixel_probability_[i][j][shade][c] = probability;
    }

    return in;
}

// << - Save Model to file (OVERLOAD)
std::ostream &operator<<(std::ostream &out, Model &model) {

    int image_dimensions = model.image_width_;
    out << image_dimensions << std::endl;

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

std::vector<Image> Model::GetTrainingImages() {
    return training_images_;
}

}  // namespace naivebayes