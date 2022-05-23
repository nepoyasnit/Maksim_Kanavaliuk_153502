#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_workButton_clicked()
{
    mylib::queue q1, q2;
        int size = rand() % 7 + 4;
        QString res = "The size of the queue's: " + QString::number(size) + '\n';
        res += "First queue: ";
        for (int i = 0; i < size; ++i) {
            int val = rand() % 10;
            res += QString::number(val) + ' ';
            q1.push(val);
        }
        res += "\nSecond queue: ";
        for (int i = 0; i < size; ++i) {
            int val = rand() % 10;
            res += QString::number(val) + ' ';
            q2.push(val);
        }
        res += '\n';

        int max = q1.front();
        for (int i = 0; i < size; ++i) {
            if (q1.front() > max) {
                max = q1.front();
            }
            q1.push(q1.front());
            q1.pop();
        }

        int cc = 1;
        while (q1.front() != max) {
            q1.push(q1.front());
            q1.pop();
            ++cc;
        }
        q1.push(q1.front());
        q1.pop();
        for (int i = 0; i < size; ++i) {
            q1.push(q2.front());
            q2.pop();
        }
        for(int i = 0; i < size - cc; ++i) {
            q1.push(q1.front());
            q1.pop();
        }
        res += "New queue: ";
        for (int i = 0; i < size * 2; ++i) {
            res += QString::number(q1.front()) + ' ';
            q1.pop();
        }
        ui->showText->setText(res);
}

