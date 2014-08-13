#include "timeedit.h"
#include <QtWidgets/QLineEdit>
#include <QDebug>
#include <QStyleFactory>

TimeEdit::TimeEdit(QWidget *parent) : QLineEdit(parent) {
    connect(this, SIGNAL(editingFinished()), this, SLOT(keep_format()));
    QStyle* fusion = QStyleFactory::create(QString("Fusion"));
    this->setStyle(fusion);
}

void TimeEdit::set_digits(int value){
    digits = value;
}

void TimeEdit::keep_format() {
    int value = this->text().toInt();
    QString formatted = QString("%1").arg(value, digits, 10, QChar('0'));
    this->setText(formatted);
}
