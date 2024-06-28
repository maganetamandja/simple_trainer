//#include "inductor.h"
#include "trainer.h"
#include <Eigen/Dense>
#include <cmath>
#include <vector>
//trainer take a matrix of data 

//take the weight vector 

//update these values

//w(t+1)= w(t) + learning_rate * (expected(t) - predicted(t)) * x(t)
//bias(t+1) = bias(t) + learning_rate * (expected(t) - predicted(t))


// data size

using Eigen::MatrixXd;

int expected_value ;
int predicted_value ;
double sum_err = 0;
std::vector<std::vector<double>> return_V;


int inductor(double x1, double x2, std::vector<double> weight_pre){
    int predict ;

   if( ((weight_pre[0] * x1)+(weight_pre[1]*x2) + weight_pre[2]) >= 0){
        predict = 1;
   }else{
        predict = 0;
   }

   return predict;

}
 




//train each weigth

//enter each row
std::vector<std::vector<double>> trainer(int epochs, float training_rate,  const MatrixXd& t_data ){

    int  row_size = static_cast<int>(t_data.rows());
    int  Colmn_size = static_cast<int>(t_data.cols());
    //due to our data shape
    std::vector<double> private_weight(Colmn_size, 0);
   
    std::vector<double> error_v(epochs, 0);
    //MatrixXd t_data(row_size, Colmn_size);



    

    for (int k = 0; k< epochs ; k++){

        for (int i = 0; i< row_size; i++){
            //now I am in the row, I enter the column
        // for (int j = 0; j<Colmn_size ; j++){

                //implement induction = (w1 * X1) + (w2 * X2) + bias
                
                predicted_value = inductor(t_data(i,0), t_data(i,1), private_weight);

                expected_value = t_data(i,2);

                //record last itteration
                //int last_iteration = 0;

                for (int l =0; l< private_weight.size()-1; l++){
                    private_weight[l] = private_weight[l] +  training_rate*(expected_value -predicted_value)*(t_data(i,l));

                    // last_iteration++;

                }
                //weight one:

            

                //weight two
            // private_weight[1] = private_weight[1] +  training_rate*(expected_value -predicted_value)*(t_data(i,1));

            //}
                //bias 
                private_weight[private_weight.size()-1] = private_weight[private_weight.size()-1] + training_rate*(expected_value-predicted_value);


                sum_err = pow((predicted_value - expected_value),2);
        }

        error_v[k]= sum_err;
    }
    //return vector of weight and error 

    return_V.push_back(private_weight);
    return_V.push_back(error_v);
    return return_V;
}
