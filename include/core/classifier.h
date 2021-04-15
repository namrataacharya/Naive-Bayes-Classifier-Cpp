#pragma once

#include "naive_bayes_model.h"

#ifndef NAIVE_BAYES_CLASSIFIER_H
#define NAIVE_BAYES_CLASSIFIER_H
#endif //NAIVE_BAYES_CLASSIFIER_H

namespace naivebayes {
class Classifier {

    public:

    /**
     * Constructor that creates an image classifier
     */
    Classifier();

    /**
     * Sets the model to be used by the classifier and gives classifier default details
     * @param model to be used by classifier
     */
    void SetModel(Model &model);

    /**
     * Clears and rebuilds likelihood scores vector
     */
    void ResetLikelihoodScores();

    /**
     * Classifies class to which passed in image belongs to
     * @param image passed in for classification
     * @return predicted class image belongs to
     */
    int ClassifyImage(Image &image);

    /**
     * Calculates likelihood scores for the image based on info from the model
     * @param image that scores are being calculated for
     */
    void CalculateLikelihoodScores(Image &image);

    /**
     * Gets the vector of likelihood scores that was already calculated
     * @return vector of likelihood scores
     */
    std::vector<double> GetLikelihoodScores();


    private:

    int num_classes_;
    int image_length_;
    Model model_;
    std::vector<double> likelihood_scores_;

};
}
