//#include "inductor.h"
#include "trainer.h"
#include <vector>
#include <iostream>
#include <Eigen/Dense>

using Eigen::MatrixXd;
    //initialize values
    int epochs = 10;
    float training_rate = 0.1f;

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



   
    int main(){



         std::vector<std::vector<double>> report ;

         report = trainer(epochs, training_rate,  dummy_data );

        //print weght size
         std::cout << "weights size"<< report[0].size()<<std::endl;
         //print weights
          std::cout << "weights\n"<<std::endl;
         for(int i; i<report[0].size()-1; i++){

            std::cout << "weight  "<<i<<" is :"<<report[0][i]<<std::endl;

         }
         std::cout << "bias : "<<report[0][report[0].size()-1]<<std::endl;

         //print error per epoch

         for(int j; j<epochs; j++){

            std::cout << "epoch = "<<j<<" error =  "<<report[1][j]<<std::endl;

         }
         return 0;
    }
    
   