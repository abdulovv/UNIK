#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "deque.h"

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
    void on_Push_back_clicked();

    void on_Push_front_clicked();

    void on_Pop_back_clicked();

    void on_Pop_front_clicked();

    void on_Back_clicked();

    void on_Front_clicked();

    void on_isEmpty_clicked();

    void on_Size_clicked();

    void on_toFile_clicked();

private:
    Ui::MainWindow *ui;
    Deque* deque = new Deque();
};
#endif // MAINWINDOW_H
