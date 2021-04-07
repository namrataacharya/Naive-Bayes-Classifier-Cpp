#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "image.h"
#include "image_processor.h"

namespace naivebayes {

class Model {

  public:

    //calculate probabilities for each class
    //calculate conditional probabilities o a pixel being (un)shaded
    //save trained model to a file
    //load model from file

    Model();
    Model(ImageProcessor &processor);

    void TrainModel(int k);

    void FindClassFrequencies();

    void CalculateClassProbability();

    void CalculatePixelProbability();

    bool PixelShaded(Image &image, int row, int col);

    void LoadModel();

    void SaveModel();

    /*
  std::vector<int> GetImageClasses();
  std::vector<Image> GetTrainingImages();
   */
  private:

    int image_width_;
    int k_ = 1; //laplace smoothing
    int v_;


    std::vector<Image> training_images_;
    //std::vector<int> image_classes_;

    std::unordered_map<int, int> class_frequency_;
    std::unordered_map<int, double> class_probability_;
    //std::unordered_map<int, double> pixel_probability;

    //map[row (i)][col (j)][shaded (bool)][class (c)] - see slides
    /*
    std::unordered_map<int, std::unordered_map<int,
        std::unordered_map<bool, std::unordered_map<int, double>>>> pixel_probability;
        */

    //std::vector<std::vector<int>
    std::vector<std::vector<std::vector<std::vector<int>>>> pixel_probability_;



    //std::vector<double> class_chance_;
    //std::vector<double> pixel_shade_chance_;
};

}  // namespace naivebayes
