#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tree.h"

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
    void on_insertButton_clicked();

    void on_deleteButton_clicked();

    void on_searchButton_clicked();

    void on_inOrderButton_clicked();

    void on_postOrderButton_clicked();

    void on_preOrderButton_clicked();

    void on_balanceButton_clicked();

    void on_countButton_clicked();

private:
    Ui::MainWindow *ui;
    stlMax::MyTree tree;
    void dushnila();
};
#endif // MAINWINDOW_H
