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

        // (k_ + class_frequency_[c]) / (10k_ + training_images_.size())
        // (# of classes = 10 --> v_)
    CalculateClassProbability();

    CalculatePixelProbability();
}


void Model::FindClassFrequencies() {
    for (Image &image : training_images_) {
        class_frequency_[image.GetLabel()]++; //updates #times label is found w/ label as key
    }
}

void Model::CalculateClassProbability() {}

void Model::CalculatePixelProbability() {}


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