#include <iostream>
#include <core/image_processor.h>
#include <core/image.h>
#include <core/naive_bayes_model.h>
#include <fstream>

// TODO: You may want to change main's signature to take in argc and argv
int main() {
  // TODO: Replace this with code that reads the training data, trains a model,
  // and saves the trained model to a file.


    naivebayes::ImageProcessor processor;
    std::ifstream txt_file("data/trainingimagesandlabels.txt");

    txt_file >> processor;

    naivebayes::Model model(processor);
    model.TrainModel(1);

    std::ofstream trained_model("data/trained_model.txt");

    trained_model << model;

    return 0;
}
