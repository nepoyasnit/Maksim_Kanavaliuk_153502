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

void MainWindow::dushnila() {
    bool isEmpty = vi.empty();
    ui->PopBack->setDisabled(isEmpty);
    ui->Front->setDisabled(isEmpty);
    ui->Back->setDisabled(isEmpty);
    ui->pushButton->setDisabled(isEmpty);
    ui->At->setDisabled(isEmpty);
    int size = vi.size();
    ui->atIndex->clear();
    ui->insertIndex->clear();
    for (int i = 0; i < size; ++i){
        ui->atIndex->addItem(QString::number(i));
        ui->insertIndex->addItem(QString::number(i));
    }
}

void MainWindow::on_Empty_clicked()
{
    ui->display->append(vi.empty() ? "vector is empty" : "Vector isn't empty");
}


void MainWindow::on_Front_clicked()
{
    ui->display->append("front element is " + QString::number(vi.front()));
}



void MainWindow::on_At_clicked()
{
    int index = ui->atIndex->currentIndex();
    ui->display->append("element with index " + QString::number(index) + " is " + QString::number(vi.at(index)));

}

void MainWindow::on_Capacity_clicked()
{
    ui->display->append("Capacity is " + QString::number(vi.capacity()));
}

void MainWindow::on_Back_clicked()
{
    ui->display->append("back element is " + QString::number(vi.back()));
}


void MainWindow::on_PushBack_clicked()
{
    vi.push_back(ui->pushBackValue->value());
    dushnila();
}

void MainWindow::on_PopBack_clicked()
{
    vi.pop_back();
    dushnila();
}


void MainWindow::on_Size_clicked()
{
    ui->display->append("Size of a vector is " + QString::number(vi.size()));
}



void MainWindow::on_pushButton_clicked()
{
    int index = ui->insertIndex->currentIndex();
    vi.insert(stlMax::vector<int>::iterator(vi.data() + index), ui->insertValue->value());
    dushnila();
}


void MainWindow::on_Print_clicked()
{
    QString data;
    for(int i = 0; i < vi.size(); ++i) {
        data += QString::number(vi[i]) + " ";
    }
    ui->display->append(data);
}


void MainWindow::on_Clear_clicked()
{
    ui->display->clear();
}


void MainWindow::on_pushButton_2_clicked()
{
    stlMax::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    vi.assign(v.begin(), v.end());
    ui->display->setText(QString::number(vi[0]) + " " + QString::number(vi[1]));
}

