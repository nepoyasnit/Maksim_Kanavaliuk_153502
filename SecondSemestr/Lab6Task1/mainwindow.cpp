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

void MainWindow::on_insertButton_clicked()
{
    int key = ui->key->value();
    QString data = ui->lineEdit->text();
    tree.Insert(key, data);
    dushnila();
}


void MainWindow::on_deleteButton_clicked()
{
    tree.Delete(ui->deleteKey->value());
    dushnila();
}

void MainWindow::on_searchButton_clicked()
{
    QString res = tree.Search(ui->searchKey->value());
    ui->showAns->setText(res);
    update();
}

void MainWindow::on_inOrderButton_clicked()
{
    QString res = tree.inOrderPrint();
    ui->showAns->setText(res);
    update();
}

void MainWindow::on_postOrderButton_clicked()
{
    QString res = tree.postOrderPrint();
    ui->showAns->setText(res);
    update();
}

void MainWindow::on_preOrderButton_clicked()
{
    QString res = tree.preOrderPrint();
    ui->showAns->setText(res);
    update();
}

void MainWindow::dushnila() {
    bool prov = tree.isEmpty();
    ui->deleteButton->setDisabled(prov);
    ui->preOrderButton->setDisabled(prov);
    ui->postOrderButton->setDisabled(prov);
    ui->inOrderButton->setDisabled(prov);
    ui->countButton->setDisabled(prov);
    ui->searchButton->setDisabled(prov);

}

void MainWindow::on_balanceButton_clicked()
{
    tree.Balance();
}


void MainWindow::on_countButton_clicked()
{
    ui->showAns->setText(QString::number(tree.preOrderCounter()));
}
