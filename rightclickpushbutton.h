#ifndef RIGHTCLICKPUSHBUTTON_H
#define RIGHTCLICKPUSHBUTTON_H

#include <QtWidgets/QPushButton>
#include <QtGui/QMouseEvent>

class RightClickPushButton : public QPushButton
{
        Q_OBJECT
public:
    explicit RightClickPushButton(QWidget *parent = 0);
    void mousePressEvent (QMouseEvent *event);

signals:
    void rightclicked();
};

#endif // RIGHTCLICKPUSHBUTTON_H
