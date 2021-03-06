
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
 NeuralNet est(data,0.0,0.5,0.0,0.5);
 est.train(0.1,10000);
 est.predict(1);
 return 0;
}

