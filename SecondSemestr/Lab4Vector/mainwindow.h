#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "vector.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Empty_clicked();

    void on_Front_clicked();

    void on_At_clicked();

    void on_Capacity_clicked();

    void on_Back_clicked();

    void on_PushBack_clicked();

    void on_PopBack_clicked();

    void on_Size_clicked();

    void on_pushButton_clicked();

    void on_Print_clicked();

    void on_Clear_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    stlMax::vector<int> vi;

    void dushnila();
};
#endif // MAINWINDOW_H
