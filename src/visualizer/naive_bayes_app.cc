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

    naivebayes::ImageProcessor processor;
    std::ifstream txt_file("../../../../../../data/trainingimagesandlabels.txt");

    txt_file >> processor;

    naivebayes::Model model(processor);
    model.TrainModel(1);

    classifier_.SetModel(model);
}

void NaiveBayesApp::draw() {
  ci::Color8u background_color(255, 178, 112); //light orange
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
      // classifier to classifies the image that's currently drawn on the
      // sketchpad and updates current_prediction_

      current_prediction_ = classifier_.ClassifyImage(sketchpad_.GetImage());
      sketchpad_.GetImage().SetLabel(current_prediction_);
      break;

      case ci::app::KeyEvent::KEY_BACKSPACE:
      sketchpad_.Clear();
      current_prediction_ = -1;
      break;
  }
}

}  // namespace visualizer
}  // namespace naivebayes
