
#include <iostream>
#include <cmath>
#include "Eigen/Dense"
#include "dataset.h"
#include "utility.h"
#include "neuralnet.h"

double eta = 0.1;
double num_iter = 10000;

int main()
{
 DataSet data;
 NeuralNet est(data);
 est.train();
 return 0;
}

