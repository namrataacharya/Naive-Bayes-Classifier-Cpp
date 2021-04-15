#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "image.h"
#include "image_processor.h"

namespace naivebayes {

class Model {

  public:

    /**
     * Default constructor that initializes/creates a Model
     */
    Model();

    /**
     * Constuctor that creates a Model using ImageProcessor info
     * @param processor that analyzes txt file
     */
    Model(ImageProcessor &processor);

    /**
     * Trains the model by finding class frequencies, calculating class probabilities, and pixel probabilities
     * @param k helps with laplace smoothing
     */
    void TrainModel(int k);

    /**
     * Finds the frequencies of the labels for each image class
     */
    void FindClassFrequencies();

    /**
     * Calculates the image class probability.
     */
    void CalculateClassProbability();

    /**
     * Calculates the conditional probabilities of a pixels being (un)shaded
     */
    void CalculatePixelProbability();

    /**
     * Determines whether a pixel is shaded or not
     * @param image whose pixel is being examined
     * @param row the pixel is in
     * @param col the pixel is in
     * @return true if pixel is shaded, false if the pixel is unshaded
     */
    bool PixelShaded(Image &image, int row, int col);

    /**
     * Gets the probability of a class: P(class = c)
     * @param c the class being examined
     * @return class's probability
     */
    double GetClassProbability(int c);

    /**
     * Gets the probability of an individual pixel: P(F(i,j) = f | class = c)
     * @param row the pixel is in
     * @param col the pixel is in
     * @param shaded number representing if the pixel is shaded/unshaded
     * @param c class the pixel is in
     * @return probability of the pixel
     */
    double GetPixelProbability(double row, double col, double shaded, double c);

    /**
     * Overloads >> operator and loads model from a file
     */
    friend std::istream &operator>>(std::istream &in, Model &model);

    /**
     * Overloads << operator and saved model to a file
     */
    friend std::ostream &operator<<(std::ostream &out, Model &model);

    /**
     * Gets all the model's training images
     * @return vector of Images
     */
    std::vector<Image> GetTrainingImages();

    /**
     * Gets all the model's image class probabilities
     * @return vector of class probabilities
     */
    std::vector<double> GetClassProbabilities();

    /**
     * Gets dimensions of training images of the model
     * @return int representing image length
     */
    int GetImageLength();

  private:

    int image_width_;
    int num_classes_;
    int k_ = 1;
    int v_ = 2;

    std::vector<int> class_frequencies_;
    std::vector<double> class_probabilities_;
    std::vector<Image> training_images_;
    std::vector<std::vector<std::vector<std::vector<double>>>> pixel_probability_;

};

}  // namespace naivebayes
