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

    SECTION("set up") {
        naivebayes::ImageProcessor processor;
        std::ifstream test_image_processor("data/trainingimagesandlabels.txt");

        test_image_processor >> processor;
        int num_labels = processor.GetNumLabels();
        int num_images = processor.GetNumImages();

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
