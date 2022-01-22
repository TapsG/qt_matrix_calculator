#include "calculator.h"

Calculator::Calculator()
{

}

Calculator::~Calculator(){

}

Matrix Calculator::sum(Matrix matrix1, Matrix matrix2){
    Matrix sum_matrix;
    std::map<int,std::vector<int>> get_sum_matrix;
    if(matrix1.get_rows() == matrix2.get_rows() and
       matrix1.get_columns() == matrix2.get_columns()){
        for(int i = 0; i < matrix1.get_rows(); i++){
            std::vector<int> row;
            for(int j = 0; j < matrix1.get_columns(); j++){
                int first = matrix1.get_matrix().at(i).at(j);
                int second = matrix2.get_matrix().at(i).at(j);
                row.push_back(first+second);
            }
            get_sum_matrix.emplace(i,row);
        }
        sum_matrix.change_matrix(get_sum_matrix);
        return sum_matrix;
    }
    return sum_matrix;
}

Matrix Calculator::multiply(Matrix matrix1, Matrix matrix2){
    Matrix multiply_matrix;
    std::map<int,std::vector<int>> get_multi_matrix;
    if(matrix1.get_rows() == matrix2.get_rows() and
       matrix1.get_columns() == matrix2.get_columns()){
        for(int i = 0; i < matrix1.get_rows(); i++){
            std::vector<int> row;

            for(int j = 0; j < matrix1.get_columns(); j++){
                int mult_ = 0;
                for(int k = 0; k < matrix2.get_rows() ; k++){
                    int first = matrix1.get_matrix().at(i).at(k);
                    int second = matrix2.get_matrix().at(k).at(j);
                    mult_ += first*second;

                }
                row.push_back(mult_);
            }
            get_multi_matrix.emplace(i,row);
        }
        multiply_matrix.change_matrix(get_multi_matrix);
        return multiply_matrix;
    }
    return multiply_matrix;
}

