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

    enum class PowerActions {
        SHUTDOWN,
        HIBERNATE
    };

private slots:

    void check_disable_actions();
    void on_pushButtonAlarm_clicked(bool checked);
    void on_pushButtonPower_clicked(bool checked);
    void on_pushButtonAlarm_toggled(bool checked);
    void on_pushButtonPower_toggled(bool checked);
    void tick();
    void switch_power_mode();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QSound *sound_effect;
    PowerActions power_mode = PowerActions::SHUTDOWN;
    std::map<PowerActions, QString> poweraction_map;
    QIcon icon_shutdown;
    QIcon icon_hibernate;

    int get_time_left(); // counter time left, in seconds
    void set_countdown_state(bool state);
    bool update_counters(); // returns whether time's up
    void do_alarm();
    void do_power_off(PowerActions mode);
};

#endif // MAINWINDOW_H
