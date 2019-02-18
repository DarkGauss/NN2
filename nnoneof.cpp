#define EIGEN_USE_MKL_AL
#include <iostream>
#include "Eigen/Dense"
#include "dataset.h"

using namespace Eigen;

int main()
{

  MatrixXd m(2,2);
  m.setRandom();
  MatrixXd m_2(4,4);
  m_2<<m,m,m,m;
  std::cout << m << std::endl;
  std::cout << m_2 << std::endl;

 /*DataSet newor;
 newor.print();
 MatrixXd In = newor.TrainingData;
 std::cout<<In<<std::endl;
 In.stableNormalize();
 std::cout<<In<<std::endl;
 return 0;*/
}