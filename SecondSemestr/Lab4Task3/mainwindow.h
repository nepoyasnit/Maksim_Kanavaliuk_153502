#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "myPair.h"
#include "myVector.h"
#include <QMainWindow>

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
    void on_number_editingFinished();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
