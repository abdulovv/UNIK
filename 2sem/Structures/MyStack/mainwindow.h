#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stack.h"
#include "QMessageBox"

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
    void on_PUSH_clicked();

    void on_POP_clicked();

    void on_TOP_clicked();

    void on_EXIT_clicked();

    void on_ISEMPTY_clicked();

    void on_Size_clicked();

private:
    Ui::MainWindow *ui;
    Stack* stack = new Stack();
};
#endif // MAINWINDOW_H
