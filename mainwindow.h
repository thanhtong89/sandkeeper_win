#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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


    void on_pushButtonAlarm_clicked(bool checked);

    void on_pushButtonPower_clicked(bool checked);

private:
    Ui::MainWindow *ui;
    int days;
    int hours;
    int minutes;
    int seconds;
};

#endif // MAINWINDOW_H
