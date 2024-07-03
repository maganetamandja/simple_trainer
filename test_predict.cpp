#include "inductor.h"
#include <iostream>
//#include <sqlite3.h>
#include <Eigen/Dense>


using Eigen::MatrixXd;


int main(){
    MatrixXd dummy_data {

    {2.7810836, 2.550537003, 0},
    {1.465489372, 2.362125076, 0},
    {3.396561688, 4.400293529, 0},
    {1.38807019, 1.850220317, 0},
    {3.06407232, 3.005305973, 0},
    {7.627531214, 2.759262235, 1},
    {5.332441248, 2.088626775, 1},
    {6.922596716, 1.77106367, 1},
    {8.675418651, -0.242068655, 1},
    {7.673756466, 3.508563011, 1}
    };

     int r = static_cast<int>(dummy_data.rows());
     int c = static_cast<int>(dummy_data.cols());

    for (int i = 0; i<r ; i++ ) {

         std::cout<< "predicted out: "<< inductor(dummy_data(i,0) , dummy_data(i,1)) << "  actual out: "<< dummy_data(i,2)<<std::endl;

        }

        
    }

    
    

