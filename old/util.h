
#include "Eigen/Dense"

#ifndef UTIL_H
#define UTIL_H

//stores paremeters for dataset
struct dataParam{
    int inputs;
    int hiddenNodes;
    int ofClasses;
};



/**
 * u_read_std
 * -----------
 * Reads an input file given my proffesor in his standard format
 *  row col
 *  1 2 3 .. col
 *  1 2 3 .. col
 *  1 2 3 .. col
 * 
 * Inputs: none
 * Outputs: Matrix with the specficed r&c from
 * stdin
 */

//reads standard method of reading in matrix from class
Eigen::MatrixXd read_std();


/**
 * read_data_param
 * --------------
 * Reads the std data paramaeters about training data
 * Inputs: none
 * Outputs: struct containings the params
 */
struct dataParam read_data_param();

#endif