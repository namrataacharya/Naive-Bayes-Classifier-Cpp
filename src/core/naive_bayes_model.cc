#include <core/naive_bayes_model.h>

namespace naivebayes {

/*std::string Model::GetBestClass() const { //DELETE
  return "CS 126";
}*/
//Model::Model() {}

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

    image_width = training_images_[0].GetLength(); //image dimensions
}

/*
std::vector<int> Model::GetImageClasses() {
    return image_classes_;
}

std::vector<Image> Model::GetTrainingImages() {
    return training_images_;
}*/

//use unordered map for storing class probability?? less run time with large amounts of data

void Model::CalculateClassProbability() {}

void Model::CalculateShadeProbability() {}


void Model::LoadModel() {}

void Model::SaveModel() {}

}  // namespace naivebayes