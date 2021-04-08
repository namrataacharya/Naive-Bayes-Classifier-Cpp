#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "image.h"
#include "image_processor.h"

namespace naivebayes {

class Model {

  public:

    Model();

    Model(ImageProcessor &processor);

    void TrainModel(int k);

    void FindClassFrequencies();

    void CalculateClassProbability();

    void CalculatePixelProbability();

    bool PixelShaded(Image &image, int row, int col);

    double GetClassProbability(int c);

    double GetPixelProbability(double row, double col, double shaded, double c);

    friend std::istream &operator>>(std::istream &in, Model &model);

    friend std::ostream &operator<<(std::ostream &out, Model &model);

    std::vector<Image> GetTrainingImages();

  private:

    int image_width_;
    int num_classes_;
    int k_ = 1;
    int v_ = 2;

    std::vector<int> class_frequencies_;
    std::vector<double> class_probabilities_;
    std::vector<Image> training_images_;
    std::vector<std::vector<std::vector<std::vector<double>>>> pixel_probability_;

};

}  // namespace naivebayes
