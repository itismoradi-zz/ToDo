#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"

#define NOTFOUND -1

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    firstID(1000)
{
    ui->setupUi(this);
    ui->comboBox->addItem("No Time");
    ui->comboBox->addItem("Mon");
    ui->comboBox->addItem("Week");
    ui->comboBox->addItem("Day");
}


void MainWindow::on_pushButton_clicked()
{
    QString input = ui->inputtask->text();
    if(input.length()!=0)
    {
        task.prepend(input);
        isComplete.prepend(false);
        id.prepend(firstID);
        firstID++;
        if(ui->checkBox->isChecked()==true)
        {
            isFavorite.prepend(true);
        }
        else
        {
            isFavorite.prepend(false);
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


void MainWindow::on_allbt_clicked()
{
    QString fulltext;
        fulltext+="id      task\n";
        for(int i=0;i<task.length();i++)
        {
            fulltext+=QString::number(id[i])+"   "+task[i]+'\n';
        }
        ui->textBrowser->setText(fulltext);
}


void MainWindow::on_monbt_clicked()
{
    QString fulltext;
        fulltext+="id      task\n";
        for (int i=0;i<times.length();i++)
        {
            if(times[i]==1)
                fulltext+=QString::number(id[i])+"   "+task[i]+'\n';
        }
        ui->textBrowser->setText(fulltext);
}


void MainWindow::on_daybt_clicked()
{
    QString fulltext;
        fulltext+="id      task\n";
        for (int i=0;i<times.length();i++)
        {
            if(times[i]==3)
                fulltext+=QString::number(id[i])+"   "+task[i]+'\n';
        }
        ui->textBrowser->setText(fulltext);
}


void MainWindow::on_favbt_clicked()
{
    QString fulltext;
        fulltext+="id      task\n";
        for (int i=0;i<isFavorite.length();i++)
        {
            if(isFavorite[i] == true)
                fulltext+=QString::number(id[i])+"   "+task[i]+'\n';
        }
        ui->textBrowser->setText(fulltext);
}


void MainWindow::on_compbt_clicked()
{
    QString fulltext;
        fulltext+="id      task\n";
        for (int i=0;i<isComplete.length();i++)
        {
            if(isComplete[i] == true)
                fulltext+=QString::number(id[i])+"   "+task[i]+'\n';
        }
        ui->textBrowser->setText(fulltext);
}


void MainWindow::on_weekbt_clicked()
{
    QString fulltext;
        fulltext+="id      task\n";
        for (int i=0;i<times.length();i++)
        {
            if(times[i]==2)
                fulltext+=QString::number(id[i])+"   "+task[i]+'\n';
        }
        ui->textBrowser->setText(fulltext);
}


void MainWindow::on_selectbt_clicked()
{
    QString s = ui->lineEdit2->text();
    int newid = s.toInt();
    int index = NOTFOUND;
    for(int i=0;i<id.length();i++)
    {
        if(id[i]==newid)
        {
            index=i;
            QMessageBox msgerr;
            msgerr.setText("task selected");
            msgerr.exec();
        }
    }

    if(index == NOTFOUND)
    {
        QMessageBox msgerr;
        msgerr.setText("not found");
        msgerr.exec();
    }
    else
    {
        //disable extra buttons for selected task
        if(isFavorite[index]==true)
            ui->tofavbt->setEnabled(false);
        if(isFavorite[index]==false)
            ui->tofavbt->setEnabled(true);
        if(times[index]==1)
            ui->tomonbt->setEnabled(false);
        if(times[index]!=1)
            ui->tomonbt->setEnabled(true);
        if(times[index]==2)
            ui->toweekbt->setEnabled(false);
        if(times[index]!=2)
            ui->toweekbt->setEnabled(true);
        if(times[index]==3)
            ui->todaybt->setEnabled(false);
        if(times[index]!=3)
            ui->todaybt->setEnabled(true);
        if(isComplete[index]==true)
            ui->tocompletebt->setEnabled(false);
        if(isComplete[index]==false)
            ui->tocompletebt->setEnabled(true);
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Removebt_clicked()
{
    QString s = ui->lineEdit2->text();
    int newid = s.toInt();      //convert inputed string to integer
    int index;

    for(int i=0;i<id.length();i++)
    {
        if(id[i]==newid)
        {
            index=i;
        }
    }

    //erase function to remove task details
    task.erase(task.begin()+index);
    isComplete.erase(isComplete.begin()+index);
    isFavorite.erase(isFavorite.begin()+index);
    times.erase(times.begin()+index);
    id.erase(id.begin()+index);

    firstID--;

    QMessageBox msgerr;
    msgerr.setText("task removed");
    msgerr.exec();
}

void MainWindow::on_todaybt_clicked()
{
    QString s = ui->lineEdit2->text();
    int newid = s.toInt();      //convert inputed string to integer
    int index;
    for(int i=0;i<id.length();i++)
    {
        if(id[i]==newid)
        {
            index=i;
        }
    }
}

void MainWindow::on_toweekbt_clicked()
{

}

void MainWindow::on_tomonbt_clicked()
{

}

void MainWindow::on_tofavbt_clicked()
{

}

void MainWindow::on_tocompletebt_clicked()
{

}
