// Created by Namrata Acharya on 4/13/21.

//#include <naive_bayes_model.h>
#include "naive_bayes_model.h"

#ifndef NAIVE_BAYES_CLASSIFIER_H
#define NAIVE_BAYES_CLASSIFIER_H
#endif //NAIVE_BAYES_CLASSIFIER_H

namespace naivebayes {
class Classifier {

    public:
        Classifier();

        Classifier(const Model &model);

        void SetModel(Model &model);

        void CalculateLikelihoodScores();

        double GetLikelihoodScore(int c);



    private:

    int num_classes_;
    int image_length_;
    Model model_;


    std::vector<double> likelihood_scores_;





};
}
