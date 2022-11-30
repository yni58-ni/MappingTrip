#ifndef LOGIN_H
#define LOGIN_H

#include "map.h"
#include <QDialog>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_pushButton_login_clicked();

private:
    Ui::login *ui;
    map *map;
};

#endif // LOGIN_H
