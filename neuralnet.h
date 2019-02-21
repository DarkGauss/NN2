
#ifndef NEURALNET_H
#define NEURALNET_H

#define DEBUG 0
#define IF_DEBUG if(DEBUG)

#include "Eigen/Dense"
#include "dataset.h"


/**
 * This class represents a feed forward neural network with backpropergation.
 * It only has one hidden layer. 
 */
class NeuralNet
{
public:
    NeuralNet(DataSet& data);
    ~NeuralNet();
    
    /**
     * train
     * -----
     * trains the neural network on the dataset given by
     * repreating calling feedforward and backpropgerate for the number
     * of iterations
     * inputs: eta (learning rate) num_iter (num of training runs)
     */
    void train(double eta = 0.1, double num_iter = 10000);

    /**
     * predict
     * -------
     * takes a row vector of inputs and runs the network on them with the 
     * given waits to get the predicted output
     * Input: Vector of inputs
     * Output: Vector of outputs
     * 
     */
    void predict(int nnoneof = 0);

//public variables   
public:

//private functions
private:
    double transfer(double x);
    void feedForward(const Eigen::MatrixXd &input);
    void backProp(double eta);

//private variables
private:
    int numOfClasses; //number of classes

    int test_d; //number of test data rows
    int test_n; //number of test inputs
    int test_m; //number of test outputs

    int d; //number of training data rows
    int n;    //number of inputs
    int h;   //number of hidden nodes
    int m;   //number of outputs

    //matrices representing all the steps in feed forward
    Eigen::MatrixXd X;  //(d x n)Input data 
    Eigen::MatrixXd Xn; //(d x n)Input data normalized with min/max to be between [0,1]
    Eigen::MatrixXd Xb; //(d x n+!)Input data with biases of -1 added to first col
    Eigen::MatrixXd V;  //(n+1 x h) Weights for x->h connections. Init random [0,1)
    Eigen::MatrixXd H;  //(d x h) Hidden layer.
    Eigen::MatrixXd Hb; //(d x h+1) hidden layer with bias -1 added to first col
    Eigen::MatrixXd W;  //(h+1 x m) Weights for h-y connections, Init random [0,1)
    Eigen::MatrixXd Y;  //(d x m) Output nodes for input
    Eigen::MatrixXd T;  //(d x m) Target nodes for input

    //matrices for backProp
    Eigen::MatrixXd Wd; //(h+1 x m) Weight delta
    Eigen::MatrixXd Hd; //(d x h+1) Hidden layer delta
    Eigen::MatrixXd Hdnb; //(d x h) Hidden layer delta with no bias

    //Matrices for test data
    Eigen::MatrixXd test_X;  //(test_d x test_n)Input test data 
    Eigen::MatrixXd test_Xn; //(test_d x test_n)Input test data normalized with min/max to be between [0,1]
    Eigen::MatrixXd test_Xb; //(test_d x test_n+1)Input test data with biases of -1 added to first col
    Eigen::MatrixXd test_H;  //(test_d x h) Hidden layer.
    Eigen::MatrixXd test_Hb; //(test_d x h+1) hidden layer with bias -1 added to first col
    Eigen::MatrixXd test_T;  //(test_d x test_m) Target nodes for output
    Eigen::MatrixXd test_Y;  //(test_d x test_m) Output nodes for input

    //confusion matrix
    Eigen::Array<bool,Eigen::Dynamic,Eigen::Dynamic> conf; //test_d x test_m) confusion matrix.
};
#endif