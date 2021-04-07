#include <catch2/catch.hpp>

#include <core/naive_bayes_model.h>
#include <iostream>
#include <fstream>
#include <core/image_processor.h>
#include <core/image.h>


TEST_CASE("Image processing test") {
    //145001 lines in txt file

    ///*
    SECTION("set up") { //works
        //naivebayes::Model model;
        naivebayes::ImageProcessor processor;


        std::ifstream test_image_processor("../../../../../../data/trainingimagesandlabels.txt");

        test_image_processor >> processor;

        naivebayes::Model model(processor);

        int length = processor.GetImageLength();
        int num_labels = processor.GetNumLabels();
        int num_images = processor.GetNumImages();

        int vec_size = processor.GetImages().size();

        //int training_imgs_size = model.GetTrainingImages().size();
        //REQUIRE(training_imgs_size == 5000);

        REQUIRE(length == 28);
        REQUIRE(num_labels == 5000);
        REQUIRE(num_images == 5000);
        REQUIRE(vec_size == 5000); //should be 5000 images in vector
    }//*/


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


/*
TODO: Rename this test file. You'll also need to modify CMakeLists.txt.

You can (and should) create more test files; this project is too big
for all tests to be in the same file. Remember that, for each file (foo.cc)
containing non-trivial code, you should have a corresponding test file
(foo_test.cc)

Make sure to add any files that you create to CMakeLists.txt.

TODO Delete this comment and the placeholder test before submitting your code.
*/
