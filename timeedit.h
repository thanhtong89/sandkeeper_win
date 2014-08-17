#ifndef TIMEEDIT_H
#define TIMEEDIT_H

#include <QtWidgets/QLineEdit>
#include <QtGui/QWheelEvent>

class TimeEdit : public QLineEdit
{
    Q_OBJECT

public:
    explicit TimeEdit(QWidget *parent = 0);
    void set_digits(int value);
    void set_upper_bound(int value);
    void format_text(int value);
    void wheelEvent (QWheelEvent *event);

private slots:
    void keep_format();

private:
    int digits = 2;
    int max_val = 60;
};
//! [0]

#endif // TIMEEDIT_H
