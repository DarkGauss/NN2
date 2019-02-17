#include "util.h"
#include<iostream>
#include<exception>


struct dataParam read_data_param(){
    struct dataParam input;
    int inputs, hiddenNodes, ofClasses;
    try
    {
        std::cin>>inputs>>hiddenNodes>>ofClasses;
    }
    catch (std::ios_base::failure e)
    {
    std::cout << "Standard exception: " << e.what() << std::endl;
    }
    input.inputs = inputs;
    input.hiddenNodes = hiddenNodes;
    input.ofClasses = ofClasses;
    return input;
}

Eigen::MatrixXd read_std()
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