#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->result->setEnabled(false);

    ui->add->setEnabled(false);
    ui->remove->setEnabled(false);
    ui->search->setEnabled(false);

    ui->KEYS->addWidget(keys);
    ui->VALUES->addWidget(vals);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_create_clicked(){
    int size = ui->SIZE->value();

    table = new HashTable(size);
    ui->result->setText("");
    ui->add->setEnabled(true);
    ui->remove->setEnabled(true);
    ui->search->setEnabled(true);
    ui->create->setEnabled(false);
    ui->SIZE->setEnabled(false);
}


void MainWindow::on_exit_clicked(){
    std::exit(0);
}


void MainWindow::on_add_clicked(){
    int key = ui->spinBox->value();
    QString value = ui->value->text();

    table->add(new Item(key, value));

    keys->setText(table->toQStringKeys());
    vals->setText(table->toQStringValues());

    ui->result->setText("");
}


void MainWindow::on_remove_clicked(){
    int key = ui->spinBox_2->value();

    bool t = table->remove(key);

    if(t == true){
        keys->setText(table->toQStringKeys());
        vals->setText(table->toQStringValues());
    }
    ui->result->setText("");
}


void MainWindow::on_search_clicked(){
    int key = ui->spinBox_2->value();

    QString res = table->search(key);

    ui->result->setText(res);
}















