#include "rightclickpushbutton.h"
#include <QDebug>

RightClickPushButton::RightClickPushButton(QWidget *parent) : QPushButton(parent) {

}

void RightClickPushButton::mousePressEvent(QMouseEvent *event){
    QPushButton::mousePressEvent(event);
    if (event->button() == Qt::RightButton){
        emit rightclicked();
    }

}
