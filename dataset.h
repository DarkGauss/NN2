
#include "Eigen/Dense"


#ifndef DATASET_H
#define DATASET_H

/**
 * class DataSet
 * -------------
 * Represents a standard dataset from asignment 2 
 *
 */
class DataSet
{
//values
public:
    int inputs;
    int hiddenNodes;
    int numOfClasses;
    Eigen::MatrixXd TrainingData;
    Eigen::MatrixXd TestData;
//constructors
public:
    DataSet();
    ~DataSet();
    void print();
//helper functions for reading in data
private:
    Eigen::MatrixXd read_std(); //reads the standard data structure for class in
    void read_data_param();
};

#endif
