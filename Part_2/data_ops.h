#ifndef DATA_OPS_H
#define DATA_OPS_H

#include <vector>
#include <string>

#include "curve.h"

//takes all the variables and assigns them from the command line arguments
bool parse_arguments(int argc, char ** argv, std::string &input_s,
std::string &config_s, std::string &out_s, std::string &func);

//parse configuration file
//config_s is the configuration file, k the number of clusters
//L the number of hash tables and g the number of grid curves
bool parse_config(std::string config_s, int & k, int & L, int &g);

//takes a dataset file name and reads the curves from it
bool read_dataset_curves(std::string data_s, std::vector<real_curve> & curves,
  int & dimension);

//takes query file name and reads the curves from it
bool read_query_curves(std::string query_s, std::vector<real_curve> & curves,
  int dimension, double & R);

//print cluster results
bool write_results(std::ofstream & out_f, std::vector<real_curve*> & centroids,
  std::vector<std::vector<real_curve*>> assignment, std::vector<double> Si,
  double Stotal, int i, int j, int z, std::string dist, bool complete,
  double time, int dimension);

//checks if the user wants to test more queries
bool check_more(std::string & query_s);

#endif
