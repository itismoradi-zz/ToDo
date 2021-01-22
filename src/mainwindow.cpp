#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->comboBox->addItem("No Time");
    ui->comboBox->addItem("Mon");
    ui->comboBox->addItem("Week");
    ui->comboBox->addItem("Day");
}
QVector <QString> tasks;
QVector <bool> fav;
QVector <int> times;
QVector <int> id;
QVector <bool> iscomp;
int s=100;
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString input = ui->inputtask->text();
    if(input.length()!=0)
    {
        tasks.prepend(input);
        iscomp.prepend(false);
        id.prepend(s);
        s++;
        if(ui->checkBox->isChecked()==true)
        {
            fav.prepend(true);
        }
        else
        {
            fav.prepend(false);
        }
        if(ui->comboBox->currentText()=="No Time")
            times.prepend(0);
        if(ui->comboBox->currentText()=="Mon")
            times.prepend(1);
        if(ui->comboBox->currentText()=="Week")
            times.prepend(2);
        if(ui->comboBox->currentText()=="Day")
            times.prepend(3);
        QMessageBox msg;
        msg.setText("task added");
        msg.exec();
        ui->inputtask->setText("");
    }
    else
    {
        QMessageBox msgerr;
        msgerr.setText("no input");
        msgerr.exec();
    }

}
