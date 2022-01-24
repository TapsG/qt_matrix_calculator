#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "matrix.h"
#include "calculator.h"

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init_size_selection();

    void size_increase();
    void size_decrease();
    void size_of_matrixes(int rows, int columns);


    void init_matrixes();
    void set_value();

    void inite_close_edit();
    void close_edit();

    void init_int();
    void set_int();

    void init_sum();
    void calculate_sum();

    void init_multiply();
    void calculate_multiply();

    void init_transpose();
    void calculate_transpose();

    void init_determinant();
    void calculate_determinant();

    void init_adjungate();
    void calculate_adjungate();

private:
    Ui::MainWindow *ui;
    std::vector<std::vector<QPushButton*>> buttons_matrix1;
    std::vector<std::vector<QPushButton*>> buttons_matrix2;
    std::vector<std::vector<QPushButton*>> buttons_matrix3;
    std::vector<QPushButton*> size_options;

    QPushButton* close_edits = nullptr;
    QPushButton* init_ints= nullptr;
    QPushButton* sum= nullptr;
    QPushButton* mult = nullptr;
    QPushButton* trans = nullptr;
    QPushButton* determinant = nullptr;
    QPushButton* adjungate = nullptr;
    std::vector<std::vector<QLineEdit*>> edits; 
    QLineEdit* det = nullptr;


    Matrix matrix1;
    Matrix matrix2;
    Matrix matrix3;

    Calculator calculator;
};
#endif // MAINWINDOW_H
