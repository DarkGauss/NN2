#define EIGEN_USE_MKL_AL
#include <iostream>
#include <cmath>
#include "Eigen/Dense"
#include "dataset.h"
#include "utility.h"
#include "neuralnet.h"

#define DEBUG 1
#define IF_DEBUG if(DEBUG)

using namespace Eigen;

double eta = 0.1;
double num_iter = 10000;

int main()
{
 DataSet data;
 NeuralNet est(data);
 est.train();
 return 0;
}

