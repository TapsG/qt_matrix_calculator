#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QPushButton>
#include<QTextEdit>
#include<QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    init_size_selection();
    inite_close_edit();
    init_int();
    init_sum();
    init_multiply();
    init_transpose();
    init_determinant();
    init_adjungate();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init_size_selection(){
    QPushButton* button = new QPushButton(this);
    button->show();
    button->setGeometry(20, 20, 20, 20);
    button->setEnabled(true);
    button->setText("+");
    size_options.push_back(button);
    connect(button, &QPushButton::clicked, this, &MainWindow::size_increase);
    QPushButton* button2 = new QPushButton(this);
    button2->show();
    button2->setGeometry(20, 40, 20, 20);
    button2->setEnabled(true);
    button2->setText("-");
    size_options.push_back(button2);
    connect(button2, &QPushButton::clicked, this, &MainWindow::size_decrease);

}

void MainWindow::size_increase(){
    int rows = static_cast<int>(matrix1.get_matrix().size());
    int columns = static_cast<int>(matrix1.get_matrix().at(0).size());
    rows+=1;
    columns+=1;
    size_of_matrixes(rows,columns);
    init_matrixes();


}

void MainWindow::size_decrease(){

    int rows = static_cast<int>(matrix1.get_matrix().size());
    int columns = static_cast<int>(matrix1.get_matrix().at(0).size());
    if(rows > 1){
        rows = rows -1;
    }
    if(columns > 1){
        columns = columns -1;
    }

    size_of_matrixes(rows,columns);
    init_matrixes();
}

void MainWindow::size_of_matrixes(int rows,int columns){
    matrix1.change_size(rows,columns);
    matrix2.change_size(rows,columns);
    matrix3.change_size(rows,columns);

}

void MainWindow::init_matrixes(){

    for(auto buttons : buttons_matrix1){
        for(int i = 0; i < buttons.size(); i++){
            buttons.at(i)->close();
        }
    }
    for(auto buttons : buttons_matrix2){
        for(int i = 0; i < buttons.size(); i++){
            buttons.at(i)->close();
        }
    }
    for(auto buttons : buttons_matrix3){
        for(int i = 0; i < buttons.size(); i++){
            buttons.at(i)->close();
        }
    }
    buttons_matrix1 = {};
    buttons_matrix2 = {};
    buttons_matrix3 = {};

    int X_ =0;
    int Y_ = 100;

    for(int i= 0; i< matrix1.get_rows() ;i++){
        std::vector<QPushButton*> row;
        for(int j = 0; j < matrix1.get_columns(); j++){
            QPushButton* button = new QPushButton(this);
            button->show();
            row.push_back(button);
            button->setGeometry(X_ +40, Y_ +40, 40, 40);
            button->setEnabled(true);
            connect(button, &QPushButton::clicked, this, &MainWindow::set_value);
            X_ +=40;
        }
        buttons_matrix1.push_back(row);
        X_ = 0;
        Y_ +=40;
    }

    X_ =440;
    Y_ = 100;
    for(int i= 0; i< matrix2.get_rows();i++){
        std::vector<QPushButton*> row;
        for(int j = 0; j < matrix2.get_columns(); j++){
            QPushButton* button = new QPushButton(this);
            button->show();
            row.push_back(button);
            button->setGeometry(X_ +40, Y_ +40, 40, 40);
            button->setEnabled(true);
            connect(button, &QPushButton::clicked, this, &MainWindow::set_value);
            X_ +=40;
        }
        buttons_matrix2.push_back(row);
        X_ = 440;
        Y_ += 40;
    }
    X_ = 880;
    Y_ = 100;
    for(int i= 0; i< matrix3.get_rows();i++){
        std::vector<QPushButton*> row;
        for(int j = 0; j < matrix3.get_columns(); j++){
            QPushButton* button = new QPushButton(this);
            button->show();
            row.push_back(button);
            button->setGeometry(X_ +40, Y_ +40, 40, 40);
            button->setEnabled(true);

            X_ +=40;
        }
        buttons_matrix3.push_back(row);
        X_ = 880;
        Y_ += 40;
    }

}

void MainWindow::set_value(){


    for(int i = 0; i < buttons_matrix1.size(); i++){
        std::vector<QLineEdit*> row;
        for(int j = 0; j < buttons_matrix1.at(i).size(); j++){

            if(buttons_matrix1.at(i).at(j) == sender()){
                QLineEdit* lineEdit = new QLineEdit(this);

                row.push_back(lineEdit);
                lineEdit->show();
                lineEdit->setGeometry(buttons_matrix1.at(i).at(j)->geometry());


            }
            edits.push_back(row);
        }
    }

    for(int i = 0; i < buttons_matrix2.size(); i++){
        std::vector<QLineEdit*> row;
        for(int j = 0; j < buttons_matrix2.at(i).size(); j++){

            if(buttons_matrix2.at(i).at(j) == sender()){
                QLineEdit* lineEdit = new QLineEdit(this);
                row.push_back(lineEdit);
                lineEdit->show();
                row.push_back(lineEdit);
                lineEdit->setGeometry(buttons_matrix2.at(i).at(j)->geometry());


            }
            edits.push_back(row);
        }
    }
}

void MainWindow::inite_close_edit(){
    QPushButton* button = new QPushButton(this);
    button->show();
    button->setGeometry(40, 20, 60, 20);
    button->setEnabled(true);
    button->setText("close");
    connect(button, &QPushButton::clicked, this, &MainWindow::close_edit);
    close_edits = button;


}

void MainWindow::close_edit(){

    for (int i = 0; i < edits.size(); i++){
        for(int j = 0; j< edits.at(i).size(); j++){
            edits.at(i).at(j)->close();
        }
    }
}

void MainWindow::init_int(){
    QPushButton* button = new QPushButton(this);
    button->show();
    button->setGeometry(40, 40, 60, 20);
    button->setEnabled(true);
    button->setText("set value");
    connect(button, &QPushButton::clicked, this, &MainWindow::set_int);
    init_ints = button;
}

void MainWindow::set_int(){
    for(int i = 0; i < edits.size(); i++){

        for(int j = 0; j < edits.at(i).size(); j++){
            for(int k = 0; k <buttons_matrix1.size(); k++){
                for(int h = 0 ; h < buttons_matrix1.at(k).size(); h++){

                    if(buttons_matrix1.at(k).at(h)->geometry() == edits.at(i).at(j)->geometry()){
                        QString text = edits.at(i).at(j)->text();
                        buttons_matrix1.at(k).at(h)->setText(text);
                        int value = buttons_matrix1.at(k).at(h)->text().toInt();
                        matrix1.change_value(k,h,value);
                    }
                }
            }
        }
    }
    for(int i = 0; i < edits.size(); i++){

        for(int j = 0; j < edits.at(i).size(); j++){
            for(int k = 0; k <buttons_matrix2.size(); k++){
                for(int h = 0 ; h < buttons_matrix2.at(k).size(); h++){

                    if(buttons_matrix2.at(k).at(h)->geometry() == edits.at(i).at(j)->geometry()){
                        QString text = edits.at(i).at(j)->text();
                        buttons_matrix2.at(k).at(h)->setText(text);
                        int value = buttons_matrix2.at(k).at(h)->text().toInt();
                        matrix2.change_value(k,h,value);
                    }
                }
            }
        }
    }
}

void MainWindow::init_sum(){
    QPushButton* button = new QPushButton(this);
    button->show();
    button->setGeometry(100, 20, 110, 20);
    button->setEnabled(true);
    button->setText("sum matrixes");
    connect(button, &QPushButton::clicked, this, &MainWindow::calculate_sum);
    sum = button;
}

void MainWindow::calculate_sum(){
    Matrix sum_matrix = calculator.sum(matrix1,matrix2);

    for(int i = 0; i < matrix1.get_rows(); i++){
        for(int j = 0; j< matrix1.get_columns();j++){
            QString txt = QString::number(sum_matrix.get_matrix().at(i).at(j));
            buttons_matrix3.at(i).at(j)->setText(txt);
        }
    }
}

void MainWindow::init_multiply(){
    QPushButton* button = new QPushButton(this);
    button->show();
    button->setGeometry(100, 40, 110, 20);
    button->setEnabled(true);
    button->setText("multiply matrixes");
    connect(button, &QPushButton::clicked, this, &MainWindow::calculate_multiply);
    mult = button;
}

void MainWindow::calculate_multiply(){
    Matrix mul_matrix = calculator.multiply(matrix1,matrix2);

    for(int i = 0; i < matrix1.get_rows(); i++){
        for(int j = 0; j< matrix1.get_columns();j++){
            QString txt = QString::number(mul_matrix.get_matrix().at(i).at(j));
            buttons_matrix3.at(i).at(j)->setText(txt);
        }
    }
}

void MainWindow::init_transpose(){
    QPushButton* button = new QPushButton(this);
    button->show();
    button->setGeometry(210, 40, 140, 20);
    button->setEnabled(true);
    button->setText("transpose matrix1");
    connect(button, &QPushButton::clicked, this, &MainWindow::calculate_transpose);
    trans = button;
}

void MainWindow::calculate_transpose(){
    Matrix transpose = calculator.transpose(matrix1);

    for(int i = 0; i < transpose.get_rows(); i++){
        for(int j = 0; j< transpose.get_columns();j++){
            QString txt = QString::number(transpose.get_matrix().at(i).at(j));
            buttons_matrix1.at(i).at(j)->setText(txt);
        }
    }
    for(int i = 0; i < matrix1.get_rows(); i++){
        for(int j=0; j < matrix1.get_columns();j++){
            matrix1.change_value(i,j,transpose.get_matrix().at(i).at(j));
        }
    }
}

void MainWindow::init_determinant(){
    QPushButton* button = new QPushButton(this);
    button->show();
    button->setGeometry(210, 20, 140, 20);
    button->setEnabled(true);
    button->setText("determinant matrix1:");
    connect(button, &QPushButton::clicked, this, &MainWindow::calculate_determinant);
    determinant = button;
    QLineEdit* lineEdit = new QLineEdit(this);
    lineEdit->show();
    lineEdit->setGeometry(350, 20, 140, 20);
    det = lineEdit;
}

void MainWindow::calculate_determinant(){
    QString deter = QString::number(calculator.determinant(matrix1));
    det->setText(deter);
}

void MainWindow::init_adjungate(){
    QPushButton* button = new QPushButton(this);
    button->show();
    button->setGeometry(210, 40, 140, 20);
    button->setEnabled(true);
    button->setText("adjungate matrix1:");
    connect(button, &QPushButton::clicked, this, &MainWindow::calculate_adjungate);
    adjungate = button;

}

void MainWindow::calculate_adjungate(){
    Matrix adjungate = calculator.adjungate(matrix1);

    for(int i = 0; i < adjungate.get_rows(); i++){
        for(int j = 0; j< adjungate.get_columns();j++){
            QString txt = QString::number(adjungate.get_matrix().at(i).at(j));
            buttons_matrix1.at(i).at(j)->setText(txt);
        }
    }
    for(int i = 0; i < matrix1.get_rows(); i++){
        for(int j=0; j < matrix1.get_columns();j++){
            matrix1.change_value(i,j,adjungate.get_matrix().at(i).at(j));
        }
    }
}
