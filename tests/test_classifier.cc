#include <catch2/catch.hpp>

#include <core/naive_bayes_model.h>
#include <iostream>
#include <fstream>
#include <core/image_processor.h>
#include <core/image.h>
#include <core/classifier.h>


TEST_CASE("Classifier accuracy") {
    SECTION("70% minimum accuracy test - testimagesandlabels.txt") {
        naivebayes::ImageProcessor processor;
        std::ifstream test_image_processor("../../../../../../data/testimagesandlabels.txt");

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
        std::cout << "testimagesandlabels.txt ACCURACY: "<< accuracy << std::endl;

        REQUIRE(accuracy > 0.70); //81.9% accuracy
    }

    SECTION("70% minimum accuracy test - test3x3.txt") {
        naivebayes::ImageProcessor processor;
        std::ifstream test_image_processor("../../../../../../data/test3x3.txt");

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
        std::cout << "test3x3.txt ACCURACY: "<< accuracy << std::endl;

        REQUIRE(accuracy > 0.70); //100% accuracy
    }

    SECTION("70% minimum accuracy test - testsample.txt") {
        naivebayes::ImageProcessor processor;
        std::ifstream test_image_processor("../../../../../../data/testsample.txt");

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
        std::cout << "testsample.txt ACCURACY: "<< accuracy << std::endl;

        REQUIRE(accuracy > 0.70); //100% accuracy
    }
}

TEST_CASE("LikelihoodScore scores test") {
    naivebayes::ImageProcessor processor;
    std::ifstream test_image_processor("../../../../../../data/testsample.txt");

    test_image_processor >> processor;

    naivebayes::Model model(processor);
    model.TrainModel(1);

    naivebayes::Classifier classifier;
    classifier.SetModel(model);

    std::vector<std::vector<char>> pixels = {{' ', '#', ' '},
                                             {' ', '#', ' '},
                                             {' ', '#', ' '}};

    naivebayes::Image image = naivebayes::Image(1, pixels.size(), pixels);

    classifier.CalculateLikelihoodScores(image);

    SECTION("LikelihoodScore(0), class 0") {
        double score = classifier.GetLikelihoodScores()[0];
        REQUIRE(score == Approx(-4.08997131));
    }

    SECTION("LikelihoodScore(1), class 1") {
        double score = classifier.GetLikelihoodScores()[1];
        REQUIRE(score == Approx(-1.874571156));
    }
}

TEST_CASE("Image classification test") {
    naivebayes::ImageProcessor processor;
    std::ifstream test_image_processor("../../../../../../data/testsample.txt");

    test_image_processor >> processor;

    naivebayes::Model model(processor);
    model.TrainModel(1);

    naivebayes::Classifier classifier;
    classifier.SetModel(model);

    SECTION("LikelihoodScore(0): class 0") {
        std::vector<std::vector<char>> pixels = {{'#', '#', '#'},
                                                 {'#', ' ', '#'},
                                                 {'#', '#', '#'}};

        naivebayes::Image image = naivebayes::Image(0, pixels.size(), pixels);
        int prediction = classifier.ClassifyImage(image);

        REQUIRE(prediction == image.GetLabel());
    }

    SECTION("LikelihoodScore(1): class 1") {
        std::vector<std::vector<char>> pixels = {{' ', '#', ' '},
                                                 {' ', '#', ' '},
                                                 {' ', '#', ' '}};

        naivebayes::Image image = naivebayes::Image(1, pixels.size(), pixels);
        int prediction = classifier.ClassifyImage(image);

        REQUIRE(prediction == image.GetLabel());
    }
}