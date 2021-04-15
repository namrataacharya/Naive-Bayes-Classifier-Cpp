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

    //sets up classifier info for calculations, etc. ALWAYS HAVE TO CALL !!!
    void Classifier::SetModel(Model &model) {
        model_ = model;
        image_length_ = model_.GetImageLength();
        num_classes_ = model_.GetClassProbabilities().size();

        //initialize size of likelihood scores vector
        ResetLikelihoodScores();
        /*
        for (int i = 0; i < num_classes_; i++) {
            likelihood_scores_.push_back(0);
        }*/
    }

    void Classifier::ResetLikelihoodScores() {
        likelihood_scores_.clear();

        for (int i = 0; i < num_classes_; i++) {
            likelihood_scores_.push_back(0);
        }
    }


    //should some of these variables be made local since image passed in varies?
    //shouldnt mix up data between images if a certain method in sequence is not called

    int Classifier::ClassifyImage(Image &image) {

        //ResetLikelihoodScores(); //rebuilds likelihood scores vector
        CalculateLikelihoodScores(image);

        double max_score = likelihood_scores_[0];
        int label_classification = -1;

        for (int i = 0; i < num_classes_; i++) {
            if (likelihood_scores_[i] > max_score ) {
                max_score = likelihood_scores_[i];
                label_classification = i;
            }
        }
        if (max_score == likelihood_scores_[0]) {
            label_classification = 0;
        }

        return label_classification; //if returns -1, INVALID (handle this later)
    }


    void Classifier::CalculateLikelihoodScores(Image &image) {

        ResetLikelihoodScores(); //rebuilds likelihood scores vector (initializes it)

        //goes thru each class
        for (int c = 0; c < num_classes_; c++) {

            double score = log10(model_.GetClassProbability(c));

            //goes thru rows/cols (pixels) of image
            for (int i = 0; i < image_length_; i++) {
                for (int j = 0; j < image_length_; j++) {

                    //bool shade = model_.PixelShaded(image, i, j);
                    score += log10(model_.GetPixelProbability(i, j, model_.PixelShaded(image, i, j), c));
                }
            }

            likelihood_scores_[c] = score;
        }
    }

    std::vector<double> Classifier::GetLikelihoodScores() {
        return likelihood_scores_;
    }


    /*
    double Classifier::GetLikelihoodScore(int c) {
        return likelihood_scores_[c];
        //return 1.0;
    }*/

}