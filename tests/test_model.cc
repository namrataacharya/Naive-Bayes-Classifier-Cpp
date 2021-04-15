#include <catch2/catch.hpp>

#include <core/naive_bayes_model.h>
#include <iostream>
#include <fstream>
#include <core/image_processor.h>
#include <core/image.h>


TEST_CASE("Image processing test") {

    SECTION("traingingimagesandlabels.txt Set Up") {
        naivebayes::ImageProcessor processor;

        std::ifstream test_image_processor("../../../../../../data/trainingimagesandlabels.txt");
        test_image_processor >> processor;

        naivebayes::Model model(processor);

        int length = processor.GetImageLength();

        int num_training_images = model.GetTrainingImages().size();
        int vec_size = processor.GetImages().size();


        REQUIRE(length == 28);
        REQUIRE(num_training_images == 5000);
        REQUIRE(vec_size == 5000);
    }

    SECTION("testsample.txt Set Up") {
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
    SECTION("P(F(0,0) = 0 | class = 1)") {
        double calculated_probability = model.GetPixelProbability(0, 0, false, 1);
        REQUIRE(calculated_probability == Approx(0.5));
    }
    SECTION("P(F(0,1) = 0 | class = 1)") {
        double calculated_probability = model.GetPixelProbability(0, 1, false, 1);
        REQUIRE(calculated_probability == Approx(0.25));
    }
    SECTION("P(F(0,2) = 0 | class = 1)") {
        double calculated_probability = model.GetPixelProbability(0, 2, false, 1);
        REQUIRE(calculated_probability == Approx(0.75));
    }

    //ROW 2
    SECTION("P(F(1,0) = 0 | class = 1)") {
        double calculated_probability = model.GetPixelProbability(1, 0, false, 1);
        REQUIRE(calculated_probability == Approx(0.75));
    }
    SECTION("P(F(1,1) = 0 | class = 1)") {
        double calculated_probability = model.GetPixelProbability(1, 1, false, 1);
        REQUIRE(calculated_probability == Approx(0.25));
    }
    SECTION("P(F(1,2) = 0 | class = 1)") {
        double calculated_probability = model.GetPixelProbability(1, 2, false, 1);
        REQUIRE(calculated_probability == Approx(0.75));
    }

    //ROW 3
    SECTION("P(F(2,0) = 0 | class = 1)") {
        double calculated_probability = model.GetPixelProbability(2, 0, false, 1);
        REQUIRE(calculated_probability == Approx(0.5));
    }
    SECTION("P(F(2,1) = 0 | class = 1)") {
        double calculated_probability = model.GetPixelProbability(2, 1, false, 1);
        REQUIRE(calculated_probability == Approx(0.25));
    }
    SECTION("P(F(2,2) = 0 | class = 1)") {
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
    SECTION("P(F(0,0) = 1 | class = 1)") {
        double calculated_probability = model.GetPixelProbability(0, 0, true, 1);
        REQUIRE(calculated_probability == Approx(0.5));
    }
    SECTION("P(F(0,1) = 1 | class = 1)") {
        double calculated_probability = model.GetPixelProbability(0, 1, true, 1);
        REQUIRE(calculated_probability == Approx(0.75));
    }
    SECTION("P(F(0,2) = 1 | class = 1)") {
        double calculated_probability = model.GetPixelProbability(0, 2, true, 1);
        REQUIRE(calculated_probability == Approx(0.25));
    }

    //ROW 2
    SECTION("P(F(1,0) = 1 | class = 1)") {
        double calculated_probability = model.GetPixelProbability(1, 0, true, 1);
        REQUIRE(calculated_probability == Approx(0.25));
    }
    SECTION("P(F(1,1) = 1 | class = 1)") {
        double calculated_probability = model.GetPixelProbability(1, 1, true, 1);
        REQUIRE(calculated_probability == Approx(0.75));
    }
    SECTION("P(F(1,2) = 1 | class = 1)") {
        double calculated_probability = model.GetPixelProbability(1, 2, true, 1);
        REQUIRE(calculated_probability == Approx(0.25));
    }

    //ROW 3
    SECTION("P(F(2,0) = 1 | class = 1)") {
        double calculated_probability = model.GetPixelProbability(2, 0, true, 1);
        REQUIRE(calculated_probability == Approx(0.5));
    }
    SECTION("P(F(2,1) = 1 | class = 1)") {
        double calculated_probability = model.GetPixelProbability(2, 1, true, 1);
        REQUIRE(calculated_probability == Approx(0.75));
    }
    SECTION("P(F(2,2) = 1 | class = 1)") {
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

    //trains model to be saved
    naivebayes::Model model(processor);
    model.TrainModel(1);

    //creates file to save model in /data/saved_file.txt
    std::ofstream saved_file("../../../../../../data/saved_file.txt");

    //creates new model loaded from file
    naivebayes::Model new_model;
    std::ifstream loaded_file("../../../../../../data/saved_file.txt");

    saved_file << model;
    loaded_file >> new_model;


    //TRAININGIMAGESANDMODELS SAVE
    /*
    naivebayes::ImageProcessor processor2;
    std::ifstream test_image_processor2("../../../../../../data/trainingimagesandlabels.txt");
    test_image_processor2 >> processor2;

    //trains model to be saved
    naivebayes::Model model2(processor2);
    model2.TrainModel(1);

    //creates file to save model in /data/saved_file.txt
    std::ofstream saved_file2("../../../../../../data/test_model_ignore.txt");

    saved_file2 << model2;

    //TRAININGIMAGESANDMODELS END
     */


    SECTION("P(class = 0) equality for both models") {
        REQUIRE(model.GetClassProbability(0) == Approx(new_model.GetClassProbability(0)));
    }
    SECTION("P(class = 1) equality for both models") {
        REQUIRE(model.GetClassProbability(1) == Approx(new_model.GetClassProbability(1)));
    }
}
