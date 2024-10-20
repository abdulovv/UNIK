#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QMessageBox"
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    ui->result->setEnabled(false);
    ui->lineEdit->setEnabled(false);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_Push_back_clicked(){
    deque->push_back(ui->spinBox->value());
    ui->lineEdit->setText(deque->toQString());
    ui->result->setText("");
}


void MainWindow::on_Push_front_clicked(){
    deque->push_front(ui->spinBox->value());
    ui->lineEdit->setText(deque->toQString());
    ui->result->setText("");
}


void MainWindow::on_Pop_back_clicked(){
    deque->pop_back();
    ui->lineEdit->setText(deque->toQString());
    ui->result->setText("");
}


void MainWindow::on_Pop_front_clicked(){
    deque->pop_front();
    ui->lineEdit->setText(deque->toQString());
    ui->result->setText("");
}


void MainWindow::on_Back_clicked(){
    if(deque->isEmpty()){
        QMessageBox::critical(nullptr, "", "Qeque is empty");
    }else
        ui->result->setText(QString::number(deque->back()->value));
}


void MainWindow::on_Front_clicked(){
    if(deque->isEmpty()){
        QMessageBox::critical(nullptr, "", "Qeque is empty");
    }else
        ui->result->setText(QString::number(deque->front()->value));
}


void MainWindow::on_isEmpty_clicked(){
    QString res = (deque->isEmpty() ? "TRUE" : "FALSE");
    ui->result->setText(res);
}


void MainWindow::on_Size_clicked(){
   ui->result->setText(QString::number(deque->size()));
}

#include <string>

using namespace std;

void MainWindow::on_toFile_clicked(){
    string file = "deque.txt";

    fstream stream(file, ios::out);

    stream << deque->toQString().toStdString();

    stream.close();
}











