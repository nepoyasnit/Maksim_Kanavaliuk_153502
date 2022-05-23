#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->spinBox->setEnabled(false);
    ui->operatorButton->setEnabled(false);
    ui->showButton->setEnabled(false);
    ui->pop_backButton->setEnabled(false);
    ui->pop_frontButton->setEnabled(false);
    for(int i =0; i < 10000; ++i){
        if(i%2 == 1){
            deq.push_front(i);
        }
        else{
            deq.push_back(i);
        }
    }
    deq.clear();
    for(int i =0; i < 10000; ++i){
        if(i%2 == 1){
            deq.push_front(i);
        }
        else{
            deq.push_back(i);
        }
    }
    deq.clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_operatorButton_clicked()
{
    ui->showText->setText(QString::number(deq[ui->spinBox->value()]));
}



void MainWindow::on_push_frontButton_clicked()
{
    deq.push_front(ui->spinBox_2->value());
    ui->showText->setText(QString::number(deq.size()));
    ui->spinBox_2->setValue(ui->spinBox_2->value() + 1);
    ui->spinBox->setEnabled(true);
    ui->operatorButton->setEnabled(true);
    ui->showButton->setEnabled(true);
    ui->pop_backButton->setEnabled(true);
    ui->pop_frontButton->setEnabled(true);
    ui->spinBox->setMaximum(deq.size()-1);
}


void MainWindow::on_push_backButton_clicked()
{
    deq.push_back(ui->spinBox_2->value());
    ui->showText->setText(QString::number(deq.size()));
    ui->spinBox_2->setValue(ui->spinBox_2->value() + 1);
    ui->spinBox->setEnabled(true);
    ui->operatorButton->setEnabled(true);
    ui->showButton->setEnabled(true);
    ui->pop_backButton->setEnabled(true);
    ui->pop_frontButton->setEnabled(true);
    ui->spinBox->setMaximum(deq.size()-1);
}


void MainWindow::on_isEmtpyButton_clicked()
{
    ui->showText->setText(deq.empty() ? "true" : "false");

}


void MainWindow::on_pop_frontButton_clicked()
{
    deq.pop_front();
    ui->showText->setText(QString::number(deq.size()));
    ui->spinBox_2->setValue(ui->spinBox_2->value() - 1);
    ui->spinBox->setMaximum(deq.size()-1);
    if(deq.empty()){
        ui->spinBox->setMinimum(0);
        ui->spinBox->setEnabled(false);
        ui->operatorButton->setEnabled(false);
        ui->showButton->setEnabled(false);
        ui->pop_backButton->setEnabled(false);
        ui->pop_frontButton->setEnabled(false);
    }
}


void MainWindow::on_pop_backButton_clicked()
{
    deq.pop_back();
    ui->showText->setText(QString::number(deq.size()));
    ui->spinBox_2->setValue(ui->spinBox->value() - 1);
    ui->spinBox->setMaximum(deq.size()-1);
    if(deq.empty()){
        ui->spinBox->setMinimum(0);
        ui->spinBox->setEnabled(false);
        ui->operatorButton->setEnabled(false);
        ui->showButton->setEnabled(false);
        ui->pop_backButton->setEnabled(false);
        ui->pop_frontButton->setEnabled(false);
    }
}


void MainWindow::on_clearButton_clicked()
{
    deq.clear();
        ui->showText->setText(QString::number(deq.size()));
        //ui->spinBox_2->setValue(0);
        ui->spinBox_2->setValue(0);
        ui->spinBox->setEnabled(false);
        ui->operatorButton->setEnabled(false);
        ui->showButton->setEnabled(false);
        ui->pop_backButton->setEnabled(false);
        ui->pop_frontButton->setEnabled(false);
        ui->spinBox->setMaximum(0);
}


void MainWindow::on_showButton_clicked()
{
    QString res;
    for(auto c : deq){
        res += QString::number(c) + ' ';
    }
    ui->showText->setText(res);
}

