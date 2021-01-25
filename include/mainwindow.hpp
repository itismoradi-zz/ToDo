#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = 0);
        ~MainWindow();
    private slots:
        void on_pushButton_clicked();
        void on_allbt_clicked();
        void on_monbt_clicked();
        void on_weekbt_clicked();
        void on_selectbt_clicked();
        void on_daybt_clicked();

        void on_favbt_clicked();

        void on_compbt_clicked();

        void on_Removebt_clicked();

        void on_todaybt_clicked();

        void on_toweekbt_clicked();

        void on_tomonbt_clicked();

        void on_tofavbt_clicked();

        void on_tocompletebt_clicked();

private:
        Ui::MainWindow * ui;
        QVector <QString> task;
        QVector <bool> isFavorite;
        QVector <int> times;
        QVector <int> id;
        QVector <bool> isComplete;
        int firstID;
};

#endif
