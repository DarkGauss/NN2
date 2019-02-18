#define EIGEN_USE_MKL_AL
#include <iostream>
#include <cmath>
#include "Eigen/Dense"
#include "dataset.h"
#include "utility.h"

#define DEBUG 1
#define IF_DEBUG if(DEBUG)

using namespace Eigen;

double eta = 0.1;
double num_iter = 10000;

double transfer(double x)
{
  return 1.0/(1.0 + std::exp(-4.0 * x));
}


int main()
{
 DataSet data;
 data.print();

 int d = data.TrainingData.rows();
 int n = data.inputs;
 int h = data.hiddenNodes;
 int m = data.TrainingData.cols() - n;

 IF_DEBUG printf("d:%d\tn:%d\th:%d\tm:%d\n",d,n,h,m);

 //initialize X as (dxn+1) the +1 is for the bias, which will be on the left
 MatrixXd X(d,n);
 X<<data.TrainingData.leftCols(data.inputs);
 IF_DEBUG debugPrint(X,"X-inputs");

//normalize inputs
 MatrixXd Xn = normMinMax(X);
 IF_DEBUG debugPrint(Xn,"Xn-inputs normalized");

//add bias to x
MatrixXd Xb(d,n+1);
Xb<<MatrixXd::Constant(d,1,-1.0),Xn.leftCols(n);
IF_DEBUG debugPrint(Xb, "Xb-input with bias");

//first row of weights for connects to hidden layer
 MatrixXd V = randUnif(n+1,h,0.0,1.0);
 IF_DEBUG debugPrint(V, "V-weights");

//First hidden layer
 MatrixXd H = (Xb*V).unaryExpr(std::ptr_fun(transfer));
 IF_DEBUG debugPrint(H, "H-hidden nodes");
 
 //add bias nodes to H
 MatrixXd Hb(d,h+1);
 Hb<<MatrixXd::Constant(d,1,-1.0),H.leftCols(h);
 IF_DEBUG debugPrint(Hb, "Hb-hidden nodes with bias");

 //seccond row of weights for connects to output layer
 MatrixXd W = randUnif(h+1,m,0.0,1.0);
 IF_DEBUG debugPrint(W, "W-weights");

 //Y output nodes
 MatrixXd Y = (Hb*W).unaryExpr(std::ptr_fun(transfer));
 IF_DEBUG debugPrint(Y, "Y-outputs");

 //T target nodes
 MatrixXd T(d,m);
 T<<data.TrainingData.rightCols(m);
 IF_DEBUG debugPrint(T, "T-targets");
/*
 debugPrint(In,"test data");
 MatrixXd In2 = normMinMax(In);
 debugPrint(In2,"test data normalized");
 MatrixXd W = randUnif(2,5,0.0,1.0);
 debugPrint(W,"Weights");
 return 0;
 */
}