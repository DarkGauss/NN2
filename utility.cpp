
#include "utility.h"

#include<iostream>
#include<exception>
#include<random>



Eigen::MatrixXd randUnif(int r, int c, double low, double high)
{
    using namespace Eigen;
    //build our output matrix
    MatrixXd output(r,c);
    //if we want a random seed, get one, else use 0 for debugging

    unsigned int seed = 0;
    if(RANDOM_SEED)
    {
        std::random_device rd;
        seed = rd();
    }
    std::mt19937 gen(seed);
    std::uniform_real_distribution<double> dis(low,high);

    for(int row = 0; row < r; row++)
    {
        for (int col = 0; col < c; col++)
        {
            output(row, col) = dis(gen);
        }
    }
    return output;
}

Eigen::MatrixXd randNormal(int r, int c, double mean, double stddev)
{
    using namespace Eigen;
    //build our output matrix
    MatrixXd output(r,c);
    //if we want a random seed, get one, else use 0 for debugging

    unsigned int seed = 0;
    if(RANDOM_SEED)
    {
        std::random_device rd;
        seed = rd();
    }
    std::mt19937 gen(seed);
    std::normal_distribution<double> dis(mean,stddev);

    for(int row = 0; row < r; row++)
    {
        for (int col = 0; col < c; col++)
        {
            output(row, col) = dis(gen);
        }
    }
    return output;
}



Eigen::MatrixXd normMinMax(const Eigen::MatrixXd& input)
{
    using namespace Eigen;
    VectorXd minVal = input.colwise().minCoeff();
    VectorXd maxVal = input.colwise().maxCoeff();

    int r = int(input.rows());
    int c = int(input.cols());

    //create a new matrix that will be rescaled
    MatrixXd output(r,c);
    for(int row = 0; row < r; row++)
    {
        for (int col = 0; col < c; col++)
        {
            double x = input(row,col);
            x = x-minVal[col];
            x = x/(maxVal[col]-minVal[col]);
            output(row, col) = x;
        }
    }
    return output;
}


void debugPrint(const Eigen::MatrixXd& input, std::string name)
{
    using namespace Eigen;
    IOFormat HeavyFmt(FullPrecision, 0, ", ", ";\n", "[", "]", "[", "]");\
    printf("------------------------\n");
    std::cout<<"DEBUG-PRINT: "<<name<<std::endl;
    printf("Size(%d x %d)\n",int(input.rows()),int(input.cols()));
    std::cout << input.format(HeavyFmt)<<std::endl;
    printf("------------------------\n");
}