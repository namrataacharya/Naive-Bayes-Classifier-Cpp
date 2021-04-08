#include <catch2/catch.hpp>

#include <core/naive_bayes_model.h>
#include <iostream>
#include <fstream>
#include <core/image_processor.h>
#include <core/image.h>


TEST_CASE("Image processing test") {
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

TEST_CASE("Pixel shade probability tests: P(F(i,j) = 0 | class = 0)") {
    naivebayes::ImageProcessor processor;

    std::ifstream test_image_processor("../../../../../../data/testsample.txt");
    test_image_processor >> processor;

    naivebayes::Model model(processor);
    model.TrainModel(1);

    //ROW 1
    SECTION("P(F(0,0) = 0 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(0, 0, false, 0);
        REQUIRE(calculated_probability == Approx(0.33333));
    }
    SECTION("P(F(0,1) = 0 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(0, 1, false, 0);
        REQUIRE(calculated_probability == Approx(0.33333));
    }
    SECTION("P(F(0,2) = 0 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(0, 2, false, 0);
        REQUIRE(calculated_probability == Approx(0.33333));
    }

    //ROW 2
    SECTION("P(F(1,0) = 0 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(1, 0, false, 0);
        REQUIRE(calculated_probability == Approx(0.33333));
    }
    SECTION("P(F(1,1) = 0 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(1, 1, false, 0);
        REQUIRE(calculated_probability == Approx(0.66667));
    }
    SECTION("P(F(1,2) = 0 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(1, 2, false, 0);
        REQUIRE(calculated_probability == Approx(0.33333));
    }

    //ROW 3
    SECTION("P(F(2,0) = 0 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(2, 0, false, 0);
        REQUIRE(calculated_probability == Approx(0.33333));
    }
    SECTION("P(F(2,1) = 0 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(2, 1, false, 0);
        REQUIRE(calculated_probability == Approx(0.33333));
    }
    SECTION("P(F(2,2) = 0 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(2, 2, false, 0);
        REQUIRE(calculated_probability == Approx(0.33333));
    }
}

TEST_CASE("Pixel shade probability tests: P(F(i,j) = 1 | class = 0)") {
    naivebayes::ImageProcessor processor;

    std::ifstream test_image_processor("../../../../../../data/testsample.txt");
    test_image_processor >> processor;

    naivebayes::Model model(processor);
    model.TrainModel(1);

    //ROW 1
    SECTION("P(F(0,0) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(0, 0, true, 0);
        REQUIRE(calculated_probability == Approx(0.66667));
    }
    SECTION("P(F(0,1) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(0, 1, true, 0);
        REQUIRE(calculated_probability == Approx(0.66667));
    }
    SECTION("P(F(0,2) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(0, 2, true, 0);
        REQUIRE(calculated_probability == Approx(0.66667));
    }

    //ROW 2
    SECTION("P(F(1,0) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(1, 0, true, 0);
        REQUIRE(calculated_probability == Approx(0.66667));
    }
    SECTION("P(F(1,1) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(1, 1, true, 0);
        REQUIRE(calculated_probability == Approx(0.33333));
    }
    SECTION("P(F(1,2) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(1, 2, true, 0);
        REQUIRE(calculated_probability == Approx(0.66667));
    }

    //ROW 3
    SECTION("P(F(2,0) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(2, 0, true, 0);
        REQUIRE(calculated_probability == Approx(0.66667));
    }
    SECTION("P(F(2,1) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(2, 1, true, 0);
        REQUIRE(calculated_probability == Approx(0.66667));
    }
    SECTION("P(F(2,2) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(2, 2, true, 0);
        REQUIRE(calculated_probability == Approx(0.66667));
    }
}

TEST_CASE("Pixel shade probability tests: P(F(i,j) = 0 | class = 1)") {
    naivebayes::ImageProcessor processor;

    std::ifstream test_image_processor("../../../../../../data/testsample.txt");
    test_image_processor >> processor;

    naivebayes::Model model(processor);
    model.TrainModel(1);

    //ROW 1
    SECTION("P(F(0,0) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(0, 0, false, 1);
        REQUIRE(calculated_probability == Approx(0.5));
    }
    SECTION("P(F(0,1) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(0, 1, false, 1);
        REQUIRE(calculated_probability == Approx(0.25));
    }
    SECTION("P(F(0,2) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(0, 2, false, 1);
        REQUIRE(calculated_probability == Approx(0.75));
    }

    //ROW 2
    SECTION("P(F(1,0) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(1, 0, false, 1);
        REQUIRE(calculated_probability == Approx(0.75));
    }
    SECTION("P(F(1,1) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(1, 1, false, 1);
        REQUIRE(calculated_probability == Approx(0.25));
    }
    SECTION("P(F(1,2) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(1, 2, false, 1);
        REQUIRE(calculated_probability == Approx(0.75));
    }

    //ROW 3
    SECTION("P(F(2,0) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(2, 0, false, 1);
        REQUIRE(calculated_probability == Approx(0.5));
    }
    SECTION("P(F(2,1) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(2, 1, false, 1);
        REQUIRE(calculated_probability == Approx(0.25));
    }
    SECTION("P(F(2,2) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(2, 2, false, 1);
        REQUIRE(calculated_probability == Approx(0.5));
    }
}


TEST_CASE("Pixel shade probability tests: P(F(i,j) = 1 | class = 1)") {
    naivebayes::ImageProcessor processor;

    std::ifstream test_image_processor("../../../../../../data/testsample.txt");
    test_image_processor >> processor;

    naivebayes::Model model(processor);
    model.TrainModel(1);

    //ROW 1
    SECTION("P(F(0,0) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(0, 0, true, 1);
        REQUIRE(calculated_probability == Approx(0.5));
    }
    SECTION("P(F(0,1) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(0, 1, true, 1);
        REQUIRE(calculated_probability == Approx(0.75));
    }
    SECTION("P(F(0,2) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(0, 2, true, 1);
        REQUIRE(calculated_probability == Approx(0.25));
    }

    //ROW 2
    SECTION("P(F(1,0) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(1, 0, true, 1);
        REQUIRE(calculated_probability == Approx(0.25));
    }
    SECTION("P(F(1,1) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(1, 1, true, 1);
        REQUIRE(calculated_probability == Approx(0.75));
    }
    SECTION("P(F(1,2) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(1, 2, true, 1);
        REQUIRE(calculated_probability == Approx(0.25));
    }

    //ROW 3
    SECTION("P(F(2,0) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(2, 0, true, 1);
        REQUIRE(calculated_probability == Approx(0.5));
    }
    SECTION("P(F(2,1) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(2, 1, true, 1);
        REQUIRE(calculated_probability == Approx(0.75));
    }
    SECTION("P(F(2,2) = 1 | class = 0)") {
        double calculated_probability = model.GetPixelProbability(2, 2, true, 1);
        REQUIRE(calculated_probability == Approx(0.5));
    }
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

TEST_CASE("Save/load model from file") {
    naivebayes::ImageProcessor processor;

    std::ifstream test_image_processor("../../../../../../data/testsample.txt");
    test_image_processor >> processor;

    naivebayes::Model model(processor);
    model.TrainModel(1);
}

/*
TODO: Rename this test file. You'll also need to modify CMakeLists.txt.

Make sure to add any files that you create to CMakeLists.txt.

TODO Delete this comment and the placeholder test before submitting your code.
*/
