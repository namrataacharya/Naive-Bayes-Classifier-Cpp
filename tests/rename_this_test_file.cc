#include <catch2/catch.hpp>

#include <core/naive_bayes_model.h>
#include <iostream>
#include <fstream>
#include <core/image_processor.h>
#include <core/image.h>

/*
TEST_CASE("Check that 126 is the best class") {
  REQUIRE(naivebayes::Placeholder().GetBestClass() == "CS 126");
}*/

TEST_CASE("Image processing test") {
    //145001 lines in txt file

    SECTION("set up") {
        naivebayes::ImageProcessor processor;

        std::ifstream test_image_processor("../../../../../../data/trainingimagesandlabels.txt");

        //std::ifstream test_image_processor;
        //test_image_processor.open("data/trainingimagesandlabels.txt");

        test_image_processor >> processor;

        /*
        if (test_image_processor.is_open()) {
            test_image_processor >> processor;
            test_image_processor.close();
        }
        */


        int num_labels = processor.GetNumLabels();
        int num_images = processor.GetNumImages();
        //int test_line_count = processor.GetLineCount();
        //int test_line_count2 = processor.GetLineCount2(); //DELETE

        //int num_images = processor.GetImages().size();


        int length = processor.GetImageLength();
        REQUIRE(length == 28);

        //REQUIRE(test_line_count == 145001);
        //REQUIRE(test_line_count2 == 2); //this one works, while(getline()) NOT RUNNING - DELETE
        REQUIRE(num_labels == 5000);
        REQUIRE(num_images == 5000);

        REQUIRE(true == true);
    }
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
