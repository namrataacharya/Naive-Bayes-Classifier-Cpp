#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "sketchpad.h"
//#include <sketchpad.h>
#include "../core/classifier.h"
//#include <../core/classifier.h>
#include "naive_bayes_app.h"
//#include <naive_bayes_app.h>



//#import <naive_bayes_app.h>

//#import <core/classifier.h>
//#import <../core/classifier.h>

namespace naivebayes {

namespace visualizer {

/**
 * Allows a user to draw a digit on a sketchpad and uses Naive Bayes to
 * classify it.
 */
class NaiveBayesApp : public ci::app::App {
 public:
  NaiveBayesApp();

  void draw() override;
  void mouseDown(ci::app::MouseEvent event) override;
  void mouseDrag(ci::app::MouseEvent event) override;
  void keyDown(ci::app::KeyEvent event) override;

  // TODO: Delete this comment. Feel free to play around with these variables
  // provided that you can see the entire UI on your screen.
  const double kWindowSize = 875;
  const double kMargin = 100;
  const size_t kImageDimension = 28;

 private:
  Sketchpad sketchpad_;
  int current_prediction_ = -1;

  Classifier classifier_;

  //naivebayes::Classifier classifier_;
};

}  // namespace visualizer

}  // namespace naivebayes
