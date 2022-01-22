#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <map>


class Matrix
{
public:
    Matrix();
    ~Matrix();

    std::map<int,std::vector<int>> get_matrix();
    void change_size(int r, int c);
    void change_value(int r, int c, int ch);
    void change_matrix( std::map<int,std::vector<int>> matrix_);
    int get_rows();
    int get_columns();


private:

    int rows = 0;
    int columns = 0;

    std::vector<int> row= {0};
    std::map<int,std::vector<int>> matrix = {{0,row}};

};

#endif // MATRIX_H
