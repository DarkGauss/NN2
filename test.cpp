#include <iostream>
#include "Eigen/Dense"
#include "util.h"
#include "Eigen/Core"

using namespace Eigen;

int main()
{
  /*
  MatrixXd m(2,2);
  m.setRandom();
  m(1,1) = m(1,0) + m(0,1);
  std::cout << m << std::endl;
  */
 IOFormat HeavyFmt(FullPrecision, 0, ", ", ";\n", "[", "]", "[", "]");

 struct dataParam params = read_data_param();
 MatrixXd A = read_std();
 printf("%d, %d, %d\n",params.inputs,params.hiddenNodes,params.ofClasses);
 printf("Matrix size...\n");
 std::cout << "The matrix A is of size "
            << A.rows() << "x" << A.cols() << std::endl;
 std::cout<<A.format(HeavyFmt)<<std::endl;
 
 return 0;
}