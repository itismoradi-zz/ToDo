#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "ui_mainwindow.h"
#include "qmessagebox.h"
#include <QFile>
#include<QTextStream>
#include <string>

using namespace std;

#define NOTFOUND -1

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    firstID(1000)
{
    ui->setupUi(this);
    ui->comboBox->addItem("No Time");
    ui->comboBox->addItem("Month");
    ui->comboBox->addItem("Week");
    ui->comboBox->addItem("Day");
    
    QFile file("..\\data\\tasks.data");    //input your file path
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    if(!file.isOpen())
    {
        QMessageBox msgerr;
        msgerr.setText("tasks.data file in data directory is not exist!");
        msgerr.exec();
    }

    QTextStream in(&file);

    while(!in.atEnd())
    {
        QString str_Line = in.readLine();
        QStringList all=str_Line.split(";");
        QString ntask=all[0];
        QString nfav=all[1];
        QString ntimes=all[2];
        QString nid=all[4];
        QString niscomp=all[3];
        task.prepend(ntask);
        if(nfav=="1")
            isFavorite.prepend(true);
        else
            isFavorite.prepend(false);
        if(ntimes=="0")
            times.prepend(0);
        else if(ntimes=="1")
            times.prepend(1);
        else if(ntimes=="2")
            times.prepend(2);
        else if(ntimes=="3")
            times.prepend(3);
        id.prepend(nid.toInt());
        if(niscomp=="1")
            isComplete.prepend(true);
        else
            isComplete.prepend(false);
    }

    if(id.length()>0)
    {
       for(int i=0;i<id.length();i++)
       {
           if(id[i]>firstID)
               firstID=id[i];
       }
       firstID++;

    }

    on_allbt_clicked();
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

        on_allbt_clicked();
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


void MainWindow::on_Removebt_clicked()
{
    QString s = ui->lineEdit2->text();
    int newid = s.toInt();      //convert inputed string to integer
    int index = NOTFOUND;

    for(int i=0;i<id.length();i++)
    {
        if(id[i]==newid)
        {
            index=i;
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

    on_allbt_clicked();
}

void MainWindow::on_todaybt_clicked()
{
    QString s = ui->lineEdit2->text();
    int newid = s.toInt();      //convert inputed string to integer
    int index = NOTFOUND;
    for(int i=0;i<id.length();i++)
    {
        if(id[i]==newid)
        {
            index=i;
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
        times[index] = 3;
        QMessageBox msgerr;
        msgerr.setText("task time is day");
        msgerr.exec();
    }

    on_allbt_clicked();
}

void MainWindow::on_toweekbt_clicked()
{
    QString s = ui->lineEdit2->text();
    int newid = s.toInt();      //convert inputed string to integer
    int index = NOTFOUND;
    for(int i=0;i<id.length();i++)
    {
        if(id[i]==newid)
        {
            index=i;
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
        times[index] = 2;
        QMessageBox msgerr;
        msgerr.setText("task time is week");
        msgerr.exec();
    }

    on_allbt_clicked();
}

void MainWindow::on_tomonbt_clicked()
{
    QString s = ui->lineEdit2->text();
    int newid = s.toInt();      //convert inputed string to integer
    int index = NOTFOUND;
    for(int i=0;i<id.length();i++)
    {
        if(id[i]==newid)
        {
            index=i;
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
        times[index] = 1;
        QMessageBox msgerr;
        msgerr.setText("task time is month");
        msgerr.exec();
    }

    on_allbt_clicked();
}

void MainWindow::on_tofavbt_clicked()
{
    QString s = ui->lineEdit2->text();
    int newid = s.toInt();      //convert inputed string to integer
    int index = NOTFOUND;
    for(int i=0;i<id.length();i++)
    {
        if(id[i]==newid)
        {
            index=i;
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
        isFavorite[index] = true;
        QMessageBox msgerr;
        msgerr.setText("task is favorite");
        msgerr.exec();
    }

    on_allbt_clicked();
}

void MainWindow::on_tocompletebt_clicked()
{
    QString s = ui->lineEdit2->text();
    int newid = s.toInt();      //convert inputed string to integer
    int index = NOTFOUND;
    for(int i=0;i<id.length();i++)
    {
        if(id[i]==newid)
        {
            index=i;
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
        isComplete[index] = true;
        QMessageBox msgerr;
        msgerr.setText("task is compeleted");
        msgerr.exec();
    }

    on_allbt_clicked();
}


MainWindow::~MainWindow()
{
        QFile file("..\\data\\tasks.data");  //input your file path

        if(file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox msgerr;
            msgerr.setText("your tasks saved");
            msgerr.exec();

            QTextStream stream(&file);

            for (int i=0;i<task.length();i++)
            {
                stream <<task[i];
                stream<<";";
                if(isFavorite[i]==true)
                {
                    stream<<"1";
                    stream<<";";
                }
                else
                {
                    stream<<"0";
                    stream<<";";
                }
                if(times[i]==0)
                {
                    stream<<"0";
                    stream<<";";
                }
                else if(times[i]==1)
                {
                    stream<<"1";
                    stream<<";";
                }
                if(times[i]==2)
                {
                    stream<<"2";
                    stream<<";";
                }
                if(times[i]==3)
                {
                    stream<<"3";
                    stream<<";";
                }
                if(isComplete[i]==true)
                {
                    stream<<"1";
                    stream<<";";
                }
                else
                {
                    stream<<"0";
                    stream<<";";
                }
                stream<<id[i];
                stream<<";"<<endl;
            }
        }

        file.close();

    delete ui;
}
