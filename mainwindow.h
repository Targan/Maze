#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "gridscene.h"

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
        void on_pushButton_3_clicked();
        void on_pushButton_clicked();
        void on_buttonPause_clicked();

        void timerTimeout();

        void on_radioButton_clicked();

private:
        void timerEvent(QTimerEvent * event);
        void startGame();

        Ui::MainWindow *ui;
        GridScene *scene;
        QTimer tm;
};

#endif // MAINWINDOW_H
