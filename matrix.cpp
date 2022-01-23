#include "matrix.h"

Matrix::Matrix()
{

}

Matrix::~Matrix(){

}

void Matrix::change_size(int r, int c){
    matrix.clear();
    for (int i = 0; i < r; i++){
        matrix.emplace(i,row);
        for(int j = 1; j< c ; j++){
            matrix.at(i).push_back(0);
        }
    }
    rows = r;
    columns = c;
}

void Matrix::change_value(int r, int c, int ch){
    matrix.at(r).at(c) = ch;
}

void Matrix::change_matrix(std::map<int, std::vector<int>> matrix_){
    matrix = matrix_;
    rows = matrix.size();
    columns = matrix.at(0).size();
}

std::map<int,std::vector<int>> Matrix::get_matrix(){
    return matrix;
}

int Matrix::get_rows(){
    return rows;
}

int Matrix::get_columns(){
    return columns;
}


