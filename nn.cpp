#define EIGEN_USE_MKL_AL
#include <iostream>
#include "Eigen/Dense"
#include "dataset.h"
#include "utility.h"

using namespace Eigen;

int main()
{
  /*
  MatrixXd m(2,2);
  m.setRandom();
  m(1,1) = m(1,0) + m(0,1);
  std::cout << m << std::endl;
  */
 DataSet newor;
 newor.print();
 MatrixXd In = newor.TestData;
 debugPrint(In,"test data");
 MatrixXd In2 = normMinMax(In);
 debugPrint(In2,"test data normalized");
 MatrixXd W = randUnif(2,5,0.0,1.0);
 debugPrint(W,"Weights");
 return 0;
}