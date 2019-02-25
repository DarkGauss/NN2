

#include <cstdlib> 
#include <iostream>
#include <cmath>
#include "Eigen/Dense"
#include "dataset.h"
#include "utility.h"
#include "neuralnet.h"

double eta = 0.1;
double num_iter = 10000;

int main(int argc, char *argv[])
{
    //make sure all params past
  /*  if(argc != 8)
    {
        printf("ERROR inccorect arguments");
        std::cout << "Have " << argc << " arguments:" << std::endl;
            for (int i = 0; i < argc; ++i)
            {
                std::cout << argv[i] << std::endl;
            }
    }
    
    eta = atof(argv[1]);
    num_iter = atoi(argv[2]);
    double V_lower = atof(argv[3]);
    double V_upper = atof(argv[4]);
    double W_lower = atof(argv[5]);
    double W_upper = atof(argv[6]);
    int oneof = atoi(argv[7]);
    */
    DataSet data;
    NeuralNet est(data,0.0,0.5,0.0,0.5);

    est.train(eta,num_iter);
    est.predict(0);
    return 0;
}

