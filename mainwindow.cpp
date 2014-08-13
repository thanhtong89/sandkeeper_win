#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStyleFactory>
#include <QDebug>
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->timeEditDay->set_digits(3);
    ui->timeEditSecond->setText("aa");
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pushButtonAlarm_clicked(bool checked){
    if (checked){
        this->ui->pushButtonPower->setChecked(false);
        if (get_time_left()){
            set_countdown_state(true);
        }
        else{
            set_countdown_state(false);
        }
    }
}

void MainWindow::on_pushButtonPower_clicked(bool checked){
    if (checked){
        this->ui->pushButtonAlarm->setChecked(false);
        if (get_time_left()){
            set_countdown_state(true);
        }
        else{
            set_countdown_state(false);
        }
    }
}


void MainWindow::on_pushButtonAlarm_toggled(bool checked){
    if (!checked && !this->ui->pushButtonPower->isChecked()){
        set_countdown_state(false);
    }
}

void MainWindow::on_pushButtonPower_toggled(bool checked){
    if (!checked && !this->ui->pushButtonAlarm->isChecked()){
        set_countdown_state(false);
    }
}

int MainWindow::get_time_left(){
    int days = this->ui->timeEditDay->text().toInt();
    int hours = this->ui->timeEditHour->text().toInt();
    int minutes = this->ui->timeEditMinute->text().toInt();
    int seconds = this->ui->timeEditSecond->text().toInt();
    return days * 86400 + hours * 3600 + minutes * 60 + seconds;
}

void MainWindow::set_countdown_state(bool state){
    bool allow_input = !state;
    this->ui->timeEditDay->setEnabled(allow_input);
    this->ui->timeEditHour->setEnabled(allow_input);
    this->ui->timeEditMinute->setEnabled(allow_input);
    this->ui->timeEditSecond->setEnabled(allow_input);

    // starting an already started timer will briefly stop it,
    // resulting in a perceptible pause of the countdown
    // even when we're just switching between the two actions.
    if (!timer->isActive()){
        if (state){
            timer->start(1000);
        }
    }
    else{
        if (!state){
            timer->stop();
        }
    }
}

void MainWindow::tick(){
    qDebug() << QTime::currentTime();
}
