#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pointers.h"
#include <memory>

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


void MainWindow::on_addButton_clicked()
{
    int val = ui->numBox->value();
    stk.Push(val);
    checkStack();

}

void MainWindow::on_deleteButton_clicked()
{
    stk.Pop();
    checkStack();
}

void MainWindow::on_showButton_clicked()
{
    ui->numBox->setValue(stk.Top());
    checkStack();
}

void MainWindow::checkStack() {
    ui->deleteButton->setEnabled(stk.getSize());
    ui->showButton->setEnabled(stk.getSize());
}

void MainWindow::on_ptrButton_clicked()
{
    int val = ui->ptrBox->value();
    pointers::SharedPtr<int> ptr1 = new int(val);
    pointers::SharedPtr<int> ptr2 = new int(val);

    ui->showNum->setText("Your number is " + QString::number(*ptr2));
}

