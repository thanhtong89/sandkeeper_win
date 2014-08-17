#ifndef RIGHTCLICKPUSHBUTTON_H
#define RIGHTCLICKPUSHBUTTON_H

#include <QtWidgets/QPushButton>
#include <QtGui/QWheelEvent>

class ScrollPushButton : public QPushButton
{
        Q_OBJECT
public:
    explicit ScrollPushButton(QWidget *parent = 0);
    void wheelEvent (QWheelEvent *event);

signals:
    void wheelscrolled();
};

#endif // RIGHTCLICKPUSHBUTTON_H
