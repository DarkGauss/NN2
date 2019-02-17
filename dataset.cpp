#include "dataset.h"

#include<iostream>
#include<exception>
#include "Eigen/Core"



DataSet::DataSet()
{
    read_data_param();
    TrainingData = read_std();
    TestData = read_std();
}
DataSet::~DataSet()
{

}

void DataSet::print()
{
    using namespace Eigen;
    IOFormat HeavyFmt(FullPrecision, 0, ", ", ";\n", "[", "]", "[", "]");
    printf("----DataSet----\n");
    printf("#inputs:%d\n#hiddenNodes:%d\n#numOfClasses%d\n",inputs,hiddenNodes,numOfClasses);
    printf("TrainingData(%d x %d)\n",int(TrainingData.rows()),int(TrainingData.cols()));
    std::cout << TrainingData.format(HeavyFmt)<<std::endl;
    printf("---TestData(%d x %d)\n",int(TestData.rows()),int(TestData.cols()));
    std::cout << TrainingData.format(HeavyFmt)<<std::endl;
    printf("----------------\n");
}
void DataSet::read_data_param()
{
    try
    {
        std::cin>>inputs>>hiddenNodes>>numOfClasses;
    }
    catch (std::ios_base::failure e)
    {
    std::cout << "Standard exception: " << e.what() << std::endl;
    }
}

Eigen::MatrixXd DataSet::read_std()
{
    //stores the number of rows/colloms and 
    //number of values read in
    int r, c;
    //figure out the dimenision of the array to read
    try
    {
        std::cin>>r>>c;
    }
    catch (std::ios_base::failure e)
    {
    std::cout << "Standard exception: " << e.what() << std::endl;
    }
    Eigen::MatrixXd input(r,c);
    try
    {
        for(int row = 0; row < r; row++)
        {
            for (int col = 0; col < c; col++)
            {
            double item = 0.0;
            std::cin >> item;
            input(row, col) = item;
            }
        }

    }
    catch (std::ios::failure e)
    {
        std::cout << "Standard exception: " << e.what() << std::endl;
    }
    return input;
}