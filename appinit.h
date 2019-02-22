#ifndef APPINIT_H
#define APPINIT_H

#include <QObject>
#include <QWidget>
#include <QMutex>

class AppInit : public QObject
{
    Q_OBJECT
public:
    static AppInit *Instance(QObject *parent = nullptr) {
        static AppInit instance(parent);
        return &instance;
    }

protected:
    bool eventFilter(QObject *obj, QEvent *evt);

private:
    //static AppInit *self;
    explicit AppInit(QObject *parent = nullptr);

signals:

public slots:
};

#endif // APPINIT_H
