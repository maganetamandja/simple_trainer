#include "inductor.h"
#include <vector>
#include <iostream>
 //implement induction = (w1 * X1) + (w2 * X2) + bias

 //std::vector<double> weights;
  std::vector<double> weights({-0.1, 0.20653640140000007, -0.23418117710000003});


 //double w1 = 0.0;
 //double w2 = 0.0;
 //double bias = 0.0;


int inductor(double x1, double x2){
    int predict ;
   if( ((weights[0] * x1)+(weights[1]*x2) + weights[2]) >= 0){
        predict = 0;
   }else{
        predict = 1;
   }

   return predict;

}