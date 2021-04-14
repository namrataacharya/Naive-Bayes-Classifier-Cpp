// Created by Namrata Acharya on 4/13/21.

#include <core/classifier.h>
#include <core/naive_bayes_model.h>

namespace naivebayes {

    Classifier::Classifier() {}

    //overloaded constructor... DELETE ?
    /*
    Classifier::Classifier(const Model &model) {
        model_ = model;
        num_classes = model_.GetClassProbabilities().size();
    }*/

    //sets up classifier info for calculations, etc.
    void Classifier::SetModel(Model &model) {
        model_ = model;
        image_length_ = model_.GetImageLength();
        num_classes_ = model_.GetClassProbabilities().size();

        //initialize size of likelihood scores vector
        for (int i = 0; i < num_classes_; i++) {
            likelihood_scores_.push_back(0);
        }
    }

    void Classifier::CalculateLikelihoodScores() {
        /*
        //initialize size of likelihood scores vector
        for (int i = 0; i < num_classes; i++) {
            likelihood_scores_.push_back(0);
        }
         */
        //goes thru each class
        for (int c = 0; c < num_classes_; c++) {

            double score = 0;
            score = log10(model_.GetClassProbability(c));

            //goes thru rows/cols (pixels) of image
            for (int i = 0; i < image_length_; i++) {
                for (int j = 0; j < image_length_; j++) {

                }
            }
        }





    }

    double Classifier::GetLikelihoodScore(int c) {
        return likelihood_scores_[c];
        //return 1.0;
    }

}