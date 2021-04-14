#include <visualizer/naive_bayes_app.h>
#include <core/image_processor.h>
#include <core/naive_bayes_model.h>
#include <core/classifier.h>

namespace naivebayes {

namespace visualizer {

NaiveBayesApp::NaiveBayesApp()
    : sketchpad_(glm::vec2(kMargin, kMargin), kImageDimension,
                 kWindowSize - 2 * kMargin) {
  ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);

  //train model here and give to classifier to classify sketchpad image
    naivebayes::ImageProcessor processor;

    std::ifstream txt_file("data/trainingimagesandlabels.txt");
    txt_file >> processor;

    naivebayes::Model model(processor);
    model.TrainModel(1);

    classifier_.SetModel(model);

    //Classifier copy_classifier_(model);
    //classifier_ = &copy_classifier_;
    //give model to classifier ...how?

    //naivebayes::Classifier classifier;


}

void NaiveBayesApp::draw() {
  ci::Color8u background_color(255, 246, 148);  // light yellow
  ci::gl::clear(background_color);

  sketchpad_.Draw();

  ci::gl::drawStringCentered(
      "Press Delete to clear the sketchpad. Press Enter to make a prediction.",
      glm::vec2(kWindowSize / 2, kMargin / 2), ci::Color("black"));

  ci::gl::drawStringCentered(
      "Prediction: " + std::to_string(current_prediction_),
      glm::vec2(kWindowSize / 2, kWindowSize - kMargin / 2), ci::Color("blue"));
}

void NaiveBayesApp::mouseDown(ci::app::MouseEvent event) {
  sketchpad_.HandleBrush(event.getPos());
}

void NaiveBayesApp::mouseDrag(ci::app::MouseEvent event) {
  sketchpad_.HandleBrush(event.getPos());
}

void NaiveBayesApp::keyDown(ci::app::KeyEvent event) {
  switch (event.getCode()) {
    case ci::app::KeyEvent::KEY_RETURN:
      // ask your classifier to classify the image that's currently drawn on the
      // sketchpad and update current_prediction_
      break;

      case ci::app::KeyEvent::KEY_BACKSPACE:   //KEY_DELETE: -> //KEY_BACKSPACE used for mac
      sketchpad_.Clear();
      break;
  }
}

}  // namespace visualizer

}  // namespace naivebayes
