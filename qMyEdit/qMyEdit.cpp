#include "qmyedit.h"

QMyEdit::QMyEdit(QWidget *parent) :
    QLineEdit(parent)
{

}


void QMyEdit::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
       emit LineEditClicked();
    }
    QLineEdit::mousePressEvent(event);
}
