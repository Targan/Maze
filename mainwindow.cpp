#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gridscene.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scene(NULL)
{
    ui->setupUi(this);
//    startGame();
    startTimer(500);
    ui->buttonPause->setEnabled(false);
    connect(&tm, SIGNAL(timeout()), this, SLOT(timerTimeout()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startGame() {

    scene = new GridScene(&tm);
    ui->graphicsView->setScene(scene);

    int timeLimit;
        if(ui->radioButton->isChecked())
            timeLimit=60;
        else
        if(ui->radioButton_2->isChecked())
            timeLimit=40;
        else
        if(ui->radioButton_3->isChecked())
            timeLimit=25;
        else
        if(ui->radioButton_4->isChecked())
            timeLimit=20;
    ui->lcdNumber->display(timeLimit);
    tm.setInterval(timeLimit * 1000);
    tm.start();

    ui->buttonPause->setEnabled(true);
    ui->buttonPause->setText("Pause");
}

void MainWindow::on_pushButton_3_clicked()
{
    exit(0);
}

void MainWindow::on_pushButton_clicked()
{
    if (scene) {
        delete scene;
    }
    startGame();
}

void MainWindow::timerEvent(QTimerEvent * event)
{
    Q_UNUSED(event);
    if (tm.isActive()) {
        if (scene->isFinished()) {
            tm.stop();
            ui->buttonPause->setEnabled(false);
            QMessageBox::information(0, QString("nePechale"), QString("You are god"), QMessageBox::Ok);
        } else {
            ui->lcdNumber->display(int(tm.remainingTime() / 1000));
        }
    }
}

void MainWindow::timerTimeout()
{
    tm.stop();
    QMessageBox::critical(0, QString("Pechale"), QString("You are looser"), QMessageBox::Ok);
    ui->buttonPause->setEnabled(false);
}

void MainWindow::on_buttonPause_clicked()
{
    if (tm.isActive()) {
        ui->buttonPause->setText("Resume");
        tm.stop();
    } else {
        ui->buttonPause->setText("Pause");
        tm.start();
    }
}

void MainWindow::on_radioButton_clicked()
{

}
