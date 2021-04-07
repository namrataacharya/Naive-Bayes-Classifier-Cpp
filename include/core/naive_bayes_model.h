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
    std::vector<int> image_classes_;

    std::unordered_map<int, int> class_frequency_;


    //std::vector<double> class_chance_;
    //std::vector<double> pixel_shade_chance_;



};

}  // namespace naivebayes
