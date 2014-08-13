#include "timeedit.h"
#include <QtWidgets/QLineEdit>
#include <QDebug>
#include <QStyleFactory>


TimeEdit::TimeEdit(QWidget *parent) : QLineEdit(parent) {
    connect(this, SIGNAL(editingFinished()), this, SLOT(keep_format()));
    QStyle* fusion = QStyleFactory::create(QString("Fusion"));
    this->setStyle(fusion);
}

void TimeEdit::wheelEvent(QWheelEvent *event){
    if (!this->isEnabled()){
        return;
    }

    event->accept();
    int value = this->text().toInt();
    int delta = 1;
    if (event->delta() < 0) {
        delta = -delta;
    }
    value = (value + delta + max_val) % max_val;
    format_text(value);
}

void TimeEdit::set_digits(int value){
    digits = value;
}

void TimeEdit::set_upper_bound(int value){
    max_val = value;
}

void TimeEdit::format_text(int value){
    QString formatted = QString("%1").arg(value, digits, 10, QChar('0'));
    this->setText(formatted);
}

void TimeEdit::keep_format() {
    int value = this->text().toInt() % max_val;
    format_text(value);
}
