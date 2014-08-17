#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSound>
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

    void check_disable_actions();
    void on_pushButtonAlarm_clicked(bool checked);
    void on_pushButtonPower_clicked(bool checked);
    void on_pushButtonAlarm_toggled(bool checked);
    void on_pushButtonPower_toggled(bool checked);
    void tick();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QSound *sound_effect;

    int get_time_left(); // counter time left, in seconds
    void set_countdown_state(bool state);
    bool update_counters(); // returns whether time's up
    void do_alarm();
    void do_power_off();
};

#endif // MAINWINDOW_H
