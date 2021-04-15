#include <core/classifier.h>
#include <core/naive_bayes_model.h>

namespace naivebayes {

    Classifier::Classifier() {}

    void Classifier::SetModel(Model &model) {
        model_ = model;
        image_length_ = model_.GetImageLength();
        num_classes_ = model_.GetClassProbabilities().size();

        ResetLikelihoodScores();
    }

    void Classifier::ResetLikelihoodScores() {
        likelihood_scores_.clear();

        for (int i = 0; i < num_classes_; i++) {
            likelihood_scores_.push_back(0);
        }
    }

    int Classifier::ClassifyImage(Image &image) {
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

        return label_classification;
    }

    void Classifier::CalculateLikelihoodScores(Image &image) {
        ResetLikelihoodScores();

        //goes through each class
        for (int c = 0; c < num_classes_; c++) {
            double score = log10(model_.GetClassProbability(c));

            //goes through rows/cols (pixels) of image
            for (int i = 0; i < image_length_; i++) {
                for (int j = 0; j < image_length_; j++) {
                    score += log10(model_.GetPixelProbability(i, j, model_.PixelShaded(image, i, j), c));
                }
            }

            likelihood_scores_[c] = score;
        }
    }

    std::vector<double> Classifier::GetLikelihoodScores() {
        return likelihood_scores_;
    }
}