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
    ui->timeEditDay->set_upper_bound(1000);
    ui->timeEditHour->set_upper_bound(24);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));

    connect(ui->timeEditDay, SIGNAL(textChanged(QString)),
                    this, SLOT(check_disable_actions()));
    connect(ui->timeEditHour, SIGNAL(textChanged(QString)),
                    this, SLOT(check_disable_actions()));
    connect(ui->timeEditMinute, SIGNAL(textChanged(QString)),
                    this, SLOT(check_disable_actions()));
    connect(ui->timeEditSecond, SIGNAL(textChanged(QString)),
                    this, SLOT(check_disable_actions()));

    QString path = QDir::toNativeSeparators(
                QDir(QDir::currentPath()).filePath("ping.wav"));
    sound_effect = new QSound(path, this);
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::check_disable_actions(){
    if (!timer->isActive()){
        int time_left = get_time_left();
        this->ui->pushButtonAlarm->setEnabled(time_left > 0);
        this->ui->pushButtonPower->setEnabled(time_left > 5);
    }
}

void MainWindow::on_pushButtonAlarm_clicked(bool checked){
    if (checked){
        this->ui->pushButtonPower->setChecked(false);
        set_countdown_state(true);
    }
}

void MainWindow::on_pushButtonPower_clicked(bool checked){
    if (checked){
        this->ui->pushButtonAlarm->setChecked(false);
        set_countdown_state(true);
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
    this->ui->timeEditDay->setReadOnly(state);
    this->ui->timeEditHour->setReadOnly(state);
    this->ui->timeEditMinute->setReadOnly(state);
    this->ui->timeEditSecond->setReadOnly(state);

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

bool MainWindow::update_counters(){
    int days = this->ui->timeEditDay->text().toInt();
    int hours = this->ui->timeEditHour->text().toInt();
    int minutes = this->ui->timeEditMinute->text().toInt();
    int seconds = this->ui->timeEditSecond->text().toInt();

    if (days + hours + minutes + seconds == 0){
        return true;
    }
    if (--seconds < 0){
        seconds += 60;
        minutes--;
    }
    if (minutes < 0){
        minutes += 60;
        hours--;
    }
    if (hours < 0){
        hours += 24;
        days--;
    }
    if (days < 0){
        days = 0;
    }

    this->ui->timeEditDay->format_text(days);
    this->ui->timeEditHour->format_text(hours);
    this->ui->timeEditMinute->format_text(minutes);
    this->ui->timeEditSecond->format_text(seconds);
    return (days + hours + minutes + seconds == 0);
}

void MainWindow::do_alarm(){
    sound_effect->play();
}

void MainWindow::do_power_off(){

}

void MainWindow::tick(){
    if (update_counters()){
        qDebug() << "Time's up!";
        if (this->ui->pushButtonAlarm->isChecked()){
            do_alarm();
            this->ui->pushButtonAlarm->setChecked(false);
        }
        else if (this->ui->pushButtonPower->isChecked()){
            do_power_off();
            this->ui->pushButtonPower->setChecked(false);
        }
        check_disable_actions();
    }
}
