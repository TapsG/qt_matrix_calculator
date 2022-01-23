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

Matrix Calculator::transpose(Matrix matrix){
    Matrix transpose;
    transpose.change_size(matrix.get_columns(),matrix.get_rows());
    for(int i = 0; i < matrix.get_rows();i++){

        for(int j = 0; j< matrix.get_columns(); j++){
            int value = matrix.get_matrix()[j][i];
            transpose.change_value(i,j,value);

        }
    }
    return transpose;
}

Matrix Calculator::minor_matrix(int i, int j, Matrix matrix){
    if(matrix.get_matrix().size()>2){
        Matrix minor;
        minor.change_size(matrix.get_rows()-1,matrix.get_columns()-1);
        for(int k = 0;k < matrix.get_matrix().size();k++){
            for(int m = 0; m < matrix.get_matrix().at(0).size();m++){
                if(k > i and m < j){
                    minor.change_value(k-1,m,matrix.get_matrix()[k][m]);
                }else if(k > i and m > j){
                    minor.change_value(k-1,m-1,matrix.get_matrix()[k][m]);
                }else if(k < i and m < j){
                    minor.change_value(k,m,matrix.get_matrix()[k][m]);
                }else if(k < i and m > j){
                    minor.change_value(k,m-1,matrix.get_matrix()[k][m]);
                }
            }
        }
        return minor;
    }else{
        return matrix;
    }

}

int Calculator::determinant(Matrix matrix){
    if(matrix.get_matrix().size()==matrix.get_matrix().at(1).size()){
            int det = 0;
            int sign = 1;
            if (matrix.get_matrix().size() == 1){
                det += matrix.get_matrix().at(0).at(0);
            }
            else if (matrix.get_matrix().size() == 2){

                det += matrix.get_matrix()[0][0]*matrix.get_matrix()[1][1]-
                       matrix.get_matrix()[0][1]*matrix.get_matrix()[1][0];
            }
            else if(matrix.get_matrix().size() > 2){
                for(int i = 1; i <= matrix.get_columns(); i++){
                    det += sign*matrix.get_matrix()[0][i-1]*determinant(minor_matrix(0,i-1,matrix));
                    sign = -sign;
                }
            }

            return det;

        }
}
