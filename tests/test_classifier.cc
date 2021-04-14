#include <catch2/catch.hpp>

#include <core/naive_bayes_model.h>
#include <iostream>
#include <fstream>
#include <core/image_processor.h>
#include <core/image.h>
#include <core/classifier.h>


TEST_CASE("Classifier accuracy") {

    SECTION("70% minimum accuracy test") {
        naivebayes::ImageProcessor processor;
        std::ifstream test_image_processor("../../../../../../data/testimagesandlabels.txt");
        std::cout << test_image_processor.is_open() << std::endl;

        test_image_processor >> processor;

        naivebayes::Model model(processor);
        model.TrainModel(1);

        naivebayes::Classifier classifier;
        classifier.SetModel(model);

        int total_images = model.GetTrainingImages().size();
        int correct_class_count = 0;

        for (int i = 0; i < total_images; i++) {
            int prediction = classifier.ClassifyImage(model.GetTrainingImages()[i]);
            if (prediction == model.GetTrainingImages()[i].GetLabel()) {
                correct_class_count++;
            }
        }

        double accuracy = double(correct_class_count)/double(total_images);

        REQUIRE(accuracy > 0.70); //73.899% accuracy
    }

}