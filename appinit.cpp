#include "appinit.h"
#include "qapplication.h"
#include "qevent.h"

AppInit::AppInit(QObject *parent) : QObject(parent)
{
}

bool AppInit::eventFilter(QObject *obj, QEvent *evt)
{
    QWidget *w = static_cast<QWidget *>(obj);
    if (!w->property("canMove").toBool()) {
        return QObject::eventFilter(obj, evt);
    }

    static QPoint mousePoint;
    static bool mousePressed = false;

    QMouseEvent *event = static_cast<QMouseEvent *>(evt);
    if (event->type() == QEvent::MouseButtonPress) {
        if (event->button() == Qt::LeftButton) {
            mousePressed = true;
            mousePoint = event->globalPos() - w->pos();
            return true;
        }
    } else if (event->type() == QEvent::MouseButtonRelease) {
        mousePressed = false;
        return true;
    } else if (event->type() == QEvent::MouseMove) {
        if (mousePressed && (event->buttons() & Qt::LeftButton)) {
            if (w->property("max").toBool())
            {
                w->showNormal();
                w->setProperty("max", false);
            }
            w->move(event->globalPos() - mousePoint);
            return true;
        }
    } else if (event->type() == QEvent::MouseButtonDblClick) {
        if (w->property("max").toBool()) {
            w->showNormal();
            w->setProperty("max", false);
        } else {
            w->showMaximized();
            w->setProperty("max", true);
        }
    }

    return QObject::eventFilter(obj, evt);
}
