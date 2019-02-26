

#include <cstdlib> 
#include <iostream>
#include <cmath>
#include "Eigen/Dense"
#include "dataset.h"
#include "utility.h"
#include "neuralnet.h"

int main(int argc, char *argv[])
{
    //make sure all params past
    if(argc == 1)
    {
        DataSet data;
        NeuralNet est(data,0.0,0.5,0.0,0.5);
        est.train(0.1,1);
        est.predict(0);
    }
    else if(argc != 8)
    {
        printf("ERROR inccorect arguments, give no arguments or give arguments in order\neta num_iter V_lower V_upper W_lower W_upper is_oneof(for iris)");
    }
    else if(argc == 8)
    {
        DataSet data;

        double eta = atof(argv[1]);
        int num_iter = atoi(argv[2]);
        double V_lower = atof(argv[3]);
        double V_upper = atof(argv[4]);
        double W_lower = atof(argv[5]);
        double W_upper = atof(argv[6]);
        int oneof = atoi(argv[7]);

        NeuralNet est(data,V_lower,V_upper,W_lower,W_upper);
        est.train(eta,num_iter,true);
        est.predict(oneof,true);
    }
    else
    {
        printf("ERROR: something bad happened");
    }
    return 0;
}

