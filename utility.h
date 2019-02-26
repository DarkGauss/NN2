
#include"Eigen/Dense"
#include<string>

#ifndef UTILITY_H
#define UTILITY_H

//set to 1 to use random seed for weight matrix
#define RANDOM_SEED 0

/**
 * randUnif
 * -----------
 * Returns a matrics with r rows and c collums with random values uniformaly from
 * [low,high)
 * -----
 * Inputs: int r (num rows) int c (num cols) double low, double high (range to return)
 * Returns: r x c matrix of doubles from uniform distrubutuion
 */

//reads standard method of reading in matrix from class
Eigen::MatrixXd randUnif(int r, int c, double low, double high);

/**
 * randNormal
 * -----------
 * Returns a matrics with r rows and c collums with random values uniformaly from std distrubtion
 * 
 * -----
 * Inputs: int r (num rows) int c (num cols) double mean, double stddev
 * Returns: r x c matrix of doubles from std normal dist
 */

//reads standard method of reading in matrix from class
Eigen::MatrixXd randNormal(int r, int c, double mean, double stddev);


/**
 * normMinMax
 * -----------
 * Returns a new matrix of the same size with it's values scaled
 * to new=(x-min(x))/max(x)-min(x)
 * 
 * -----
 * Inputs: a matrix with each collum representing a feature
 * Returns: a matrix with all values rescaled between 0 and 1
 */

Eigen::MatrixXd normMinMax(const Eigen::MatrixXd& input);

/**
 * debugPrint
 * -----------
 * Prints out matrix along with lots of details
 * -----
 * Inputs: a matrix 
 * Returns: nothing
 */
void debugPrint(const Eigen::MatrixXd& input, std::string name = "Matrix");
/**
 * csvPrint
 * -----------
 * Prints out the first row of the matrix passed in csv form
 * -----
 * Inputs: a matrix 
 * Returns: nothing
 */
void csvPrint(const Eigen::MatrixXd& input, std::string name = "Matrix", bool noComma = false);
/**
 * csvWeightPrint
 * -----------
 * Prints out the first row of the matrix passed in csv form
 * -----
 * Inputs: a matrix and number of inputs and number of output nodes
 * Returns: nothing
 */
void csvWeightPrint(const Eigen::MatrixXd& input, int n, int h);

/**
 * csclassPrint
 * -----------
 * Prints out matrix out in style needed for cs class
 * ex:
 * Target
 * 0.0000 0.0000 1.000
 * 0.0000 0.0000 1.000
 * -----
 * Inputs: a matrix and a title
 * Returns: nothing
 */
void csclassPrint(const Eigen::MatrixXd& input, std::string name);
#endif