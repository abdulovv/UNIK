#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->VALUES->setEnabled(false);
    ui->KEYS->setEnabled(false);
    ui->result->setEnabled(false);

    ui->add->setEnabled(false);
    ui->remove->setEnabled(false);
    ui->search->setEnabled(false);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_create_clicked(){
    int size = ui->SIZE->value();

    table = new HashTable(size);
    ui->KEYS->setText("");
    ui->VALUES->setText("");
    ui->result->setText("");

    ui->add->setEnabled(true);
    ui->remove->setEnabled(true);
    ui->search->setEnabled(true);
}


void MainWindow::on_exit_clicked(){
    std::exit(0);
}


void MainWindow::on_add_clicked(){
    int key = ui->spinBox->value();
    QString value = ui->value->text();

    table->add(new Item(key, value));

    ui->VALUES->setText(table->toQStringValues());
    ui->KEYS->setText(table->toQStringKeys());

    ui->result->setText("");
}


void MainWindow::on_remove_clicked(){
    int key = ui->spinBox_2->value();

    table->remove(key);

    ui->VALUES->setText(table->toQStringValues());
    ui->KEYS->setText(table->toQStringKeys());

    ui->result->setText("");
}


void MainWindow::on_search_clicked(){
    int key = ui->spinBox_2->value();

    QString res = table->search(key);

    ui->result->setText(res);
}















