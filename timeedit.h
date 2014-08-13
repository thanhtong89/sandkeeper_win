#ifndef TIMEEDIT_H
#define TIMEEDIT_H

#include <QtWidgets/QLineEdit>

class TimeEdit : public QLineEdit
{
    Q_OBJECT

public:
    explicit TimeEdit(QWidget *parent = 0);
    void set_digits(int value);

private slots:
    void keep_format();

private:
    int digits = 2;
};
//! [0]

#endif // TIMEEDIT_H
