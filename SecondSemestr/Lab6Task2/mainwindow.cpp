#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MyHashTable.h"
#include "stack.h"

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

void MainWindow::on_pushButton_clicked()
{
    int size = 0;
    stlMax::MyHashTable table;
    for (int i = -10; i < 10; i += rand() % 2 + 1){
        size++;
        table.insertItem(i, i);
    }
    QString ans;
    ans += "HashTable before\n";
    ans += table.printTable();
    for (int i = -10; i <= 0; ++i){
        table.removeItem(i);
    }
    ans += "\nHashTable after\n";
    ans += table.printTable();
    ui->showAns->setText(ans);
}

