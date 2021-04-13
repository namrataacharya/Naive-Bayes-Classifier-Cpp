#include <iostream>
#include <core/image_processor.h>
#include <core/image.h>
#include <core/naive_bayes_model.h>
#include <fstream>

// TODO: You may want to change main's signature to take in argc and argv
int main() {
  // TODO: Replace this with code that reads the training data, trains a model,
  // and saves the trained model to a file.

  //std::cout << "Welcome to " << naivebayes::Placeholder().GetBestClass() << std::endl;


  ///*
    naivebayes::ImageProcessor processor;
    //std::ifstream txt_file("../../../../../../data/trainingimagesandlabels.txt");

    std::ifstream txt_file("data/trainingimagesandlabels.txt");
    std::cout << txt_file.is_open() << std::endl;

    txt_file >> processor;

    naivebayes::Model model(processor);
    model.TrainModel(1);

    //std::ofstream trained_model("../../../../../../data/trained_model.txt");
    std::ofstream trained_model("data/trained_model.txt");

    trained_model << model;
    //*/


    //TEST SAVE
    /*
    naivebayes::ImageProcessor test_processor;
    std::ifstream test_txt_file("../../../../../../data/test_sample.txt");
    test_txt_file >> test_processor;

    naivebayes::Model test_model(test_processor);
    test_model.TrainModel(1);

    std::ofstream test_trained_model("../../../../../../data/test_model_ignore.txt");

    test_trained_model << test_model;
     //*/


    return 0;
}
