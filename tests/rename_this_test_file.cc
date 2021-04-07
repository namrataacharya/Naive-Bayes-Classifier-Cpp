#include <catch2/catch.hpp>

#include <core/naive_bayes_model.h>
#include <iostream>
#include <fstream>
#include <core/image_processor.h>
#include <core/image.h>


TEST_CASE("Image processing test") {
    //145001 lines in txt file
    /*
    SECTION("trainingimagesandlabels.txt Set Up") { //works
        //naivebayes::Model model;
        naivebayes::ImageProcessor processor;


        std::ifstream test_image_processor("../../../../../../data/trainingimagesandlabels.txt");

        test_image_processor >> processor;

        naivebayes::Model model(processor);

        int length = processor.GetImageLength();
        int num_labels = processor.GetNumLabels();
        int num_images = processor.GetNumImages();

        //int vec_size = processor.GetImages().size();

        //int training_imgs_size = model.GetTrainingImages().size();
        //REQUIRE(training_imgs_size == 5000);

        REQUIRE(length == 28);
        REQUIRE(num_labels == 5000);
        REQUIRE(num_images == 5000);
        //REQUIRE(vec_size == 5000); //should be 5000 images in vector
    }
    */

    SECTION("testsample.txt Set Up") { //works
        naivebayes::ImageProcessor processor;

        std::ifstream test_image_processor("../../../../../../data/testsample.txt");
        test_image_processor >> processor;

        naivebayes::Model model(processor);

        int length = processor.GetImageLength();

        int num_training_images = model.GetTrainingImages().size();
        int vec_size = processor.GetImages().size();


        REQUIRE(length == 3);
        REQUIRE(num_training_images == 3);
        REQUIRE(vec_size == 3);
    }
    /*
    SECTION("image class vec (Model)") {
        //naivebayes::Model model;
        naivebayes::ImageProcessor processor;


        std::ifstream test_image_processor("../../../../../../data/trainingimagesandlabels.txt");

        test_image_processor >> processor;

        naivebayes::Model model(processor);
        std::vector<int> model_vector = model.GetImageClasses();
        std::vector<int> actual_classes;
        for (int i = 0; i < 10; i++) {
            actual_classes.push_back(i);
        }


        int length = processor.GetImageLength();
        int num_labels = processor.GetNumLabels();
        int num_images = processor.GetNumImages();


        REQUIRE(length == 28);
        REQUIRE(num_labels == 5000);
        REQUIRE(num_images == 5000);

        REQUIRE(actual_classes == model_vector);
    }*/
}

TEST_CASE("Pixel shade probability tests: P(F(i,j)=f|class=c)") {
    /*
    naivebayes::ImageProcessor processor;

    std::ifstream test_image_processor("../../../../../../data/testsample.txt");
    test_image_processor >> processor;

    naivebayes::Model model(processor);
    model.TrainModel(1);*/

    //f = 0 --> UNSHADED
    //f = 1 --> SHADED

    SECTION("P(F(0,0) = 0 | class = 0)") {
        naivebayes::ImageProcessor processor;

        std::ifstream test_image_processor("../../../../../../data/testsample.txt");
        test_image_processor >> processor;

        naivebayes::Model model(processor);
        model.TrainModel(1);
        double calculated_probability = model.GetPixelProbability(0, 0, false, 0);
        REQUIRE(calculated_probability == Approx(0.33333));
    }
    /*
    SECTION("image class vec (Model)") {
        //naivebayes::Model model;
        naivebayes::ImageProcessor processor;


        std::ifstream test_image_processor("../../../../../../data/trainingimagesandlabels.txt");

        test_image_processor >> processor;

        naivebayes::Model model(processor);
        std::vector<int> model_vector = model.GetImageClasses();
        std::vector<int> actual_classes;
        for (int i = 0; i < 10; i++) {
            actual_classes.push_back(i);
        }


        int length = processor.GetImageLength();
        int num_labels = processor.GetNumLabels();
        int num_images = processor.GetNumImages();


        REQUIRE(length == 28);
        REQUIRE(num_labels == 5000);
        REQUIRE(num_images == 5000);

        REQUIRE(actual_classes == model_vector);
    }*/
}

TEST_CASE("Class probability tests: P(class=c)") {
    naivebayes::ImageProcessor processor;

    std::ifstream test_image_processor("../../../../../../data/testsample.txt");
    test_image_processor >> processor;

    naivebayes::Model model(processor);
    model.TrainModel(1);

    SECTION("P(class = 0)") {
        double calculated_probability = model.GetClassProbability(0);
        REQUIRE(calculated_probability == Approx(0.4));
    }

    SECTION("P(class = 1)") {
        double calculated_probability = model.GetClassProbability(1);
        REQUIRE(calculated_probability == Approx(0.6));
    }
}

/*
TODO: Rename this test file. You'll also need to modify CMakeLists.txt.

Make sure to add any files that you create to CMakeLists.txt.

TODO Delete this comment and the placeholder test before submitting your code.
*/
