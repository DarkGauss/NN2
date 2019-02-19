
#include <iostream>
#include <cmath>

#include "utility.h"
#include "neuralnet.h"
#include "dataset.h"

NeuralNet::NeuralNet(DataSet& data)
{
    data.print();
}

NeuralNet::~NeuralNet()
{

}

//public functions
void NeuralNet::train(double eta = 0.1, double num_iter = 10000)
{

}

Eigen::VectorXd output NeuralNet::predict(const Eigen::VectorXd &input)
{   
    Eigen::VectorXd output(5);
    return output;
}

//private functions
double NeuralNet::transfer(double x)
{
    return 2.0;
}

void NeuralNet::feedForward(const Eigen::MatrixXd &input)
{

}

void NeuralNet::backProp()
{

}
