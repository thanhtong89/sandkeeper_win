#ifndef TIMEEDIT_H
#define TIMEEDIT_H

#include <QtWidgets/QLineEdit>

class TimeEdit : public QLineEdit
{
    Q_OBJECT

public:
    explicit TimeEdit(QWidget *parent = 0);
    //explicit TimeEdit(const QString &contents, QWidget *parent = 0);
private slots:
    void keep_format();
};
//! [0]

#endif // TIMEEDIT_H
