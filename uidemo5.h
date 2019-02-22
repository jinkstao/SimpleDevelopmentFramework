#ifndef UIDEMO5_H
#define UIDEMO5_H

#include <QDialog>


namespace Ui {
class UIDemo5;
}

class UIDemo5 : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(bool max READ getMax WRITE setMax)

public:
    explicit UIDemo5(QWidget *parent = nullptr);
    ~UIDemo5();
    void setMax(bool value);
    bool getMax();
    
private:
    void init();
    void initMenu();
    void updateProjInfo();
    void initForm();

private:
    Ui::UIDemo5 *ui;
    bool max;
    QRect location;

private slots:
    void initIndex();

private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();
    void on_listView_pressed(const QModelIndex &index);
};

#endif // UIDEMO5_H
