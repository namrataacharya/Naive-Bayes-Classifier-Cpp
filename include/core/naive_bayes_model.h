#pragma once
#include <string>
#include <vector>
#include "image.h"
#include "image_processor.h"

namespace naivebayes {

class Model {

  public:
    //std::string GetBestClass() const; //DELETE (in src too)

    //calculate probabilities for each class
    //calculate conditional probabilities o a pixel being (un)shaded
    //save trained model to a file
    //load model from file

    Model();
    Model(ImageProcessor &processor);

    std::vector<int> GetImageClasses();
    std::vector<Image> GetTrainingImages();

    void LoadModel();
    void SaveModel();
    void CalculateClassProbability();
    void CalculateShadeProbability();





  private:

    int image_width;

    std::vector<Image> training_images_;
    std::vector<int> image_classes_;

    //std::vector<double> class_chance_;
    //std::vector<double> pixel_shade_chance_;



};

}  // namespace naivebayes

/*
TODO: rename this file. You'll also need to modify CMakeLists.txt.

You can (and should) create more classes and files in include/core (header
 files) and src/core (source files); this project is too big to only have a
 single class.

Make sure to add any files that you create to CMakeLists.txt.

TODO Delete this comment before submitting your code.
*/
