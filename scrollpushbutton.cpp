#include "scrollpushbutton.h"
#include <QDebug>

ScrollPushButton::ScrollPushButton(QWidget *parent) : QPushButton(parent) {

}

void ScrollPushButton::wheelEvent(QWheelEvent *event){
    event->accept();
    emit wheelscrolled();
}
