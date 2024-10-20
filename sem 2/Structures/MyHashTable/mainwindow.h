#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hashtable.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_create_clicked();

    void on_exit_clicked();

    void on_add_clicked();

    void on_remove_clicked();

    void on_search_clicked();

private:
    Ui::MainWindow *ui;
    HashTable* table;
};
#endif // MAINWINDOW_H
