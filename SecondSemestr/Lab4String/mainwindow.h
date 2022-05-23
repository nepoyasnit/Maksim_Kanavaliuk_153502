#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

    void on_reverseButton_clicked();

    void on_sizeButton_clicked();

    void on_plusButton_clicked();

    void on_countButton_clicked();

    void on_isPalButton_clicked();

    void on_findButton_clicked();

    void on_showButton_clicked();

private:
    Ui::MainWindow *ui;
    void dushnila();
};
#endif // MAINWINDOW_H
