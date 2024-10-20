#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_PUSH_clicked(){
    stack->push(ui->spinBox->value());

    QString newEl = "|" + QString::number(ui->spinBox->value()) + "| ";
    QString strStack = ui->lineEdit->text();
    QString newStrStack = strStack + newEl;
    ui->lineEdit->setText(newStrStack);
}

void MainWindow::on_POP_clicked(){
    if(!stack->isEmpty()){
    QString strStack = ui->lineEdit->text();

    int itemLength = QString::number(stack->top()->value).size() + 3;
    int beg = strStack.size() - itemLength;

    QString newStrStack = strStack.remove(beg, itemLength);
    ui->lineEdit->setText(newStrStack);

    stack->pop();
    }else
        QMessageBox::critical(nullptr, "", "Stack is empty");
}


void MainWindow::on_TOP_clicked(){
    if(!stack->isEmpty()){
        QMessageBox::information(nullptr, "", QString::number(stack->top()->value));
    }else
        QMessageBox::critical(nullptr, "", "Stack is empty");
}


void MainWindow::on_EXIT_clicked(){
    std::exit(0);
}


void MainWindow::on_ISEMPTY_clicked(){
    QString isEmpty = stack->isEmpty() == true ? "true" : "false";
    QMessageBox::information(nullptr, "", isEmpty);
}


void MainWindow::on_Size_clicked(){
    QMessageBox::information(nullptr, "", QString::number(stack->size()));
}

