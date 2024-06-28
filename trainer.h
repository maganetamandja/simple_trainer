#ifndef TRAINER_H
#define TRAINER_H
#include <vector>
#include <Eigen/Dense>
using Eigen::MatrixXd;



std::vector<std::vector<double>> trainer(int epochs, float training_rate,  const MatrixXd& t_data );

#endif