#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "mapdialog.h"
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    /**
     * invoke when register button clicked
     * @brief on_registerButton_clicked
     */
    void on_registerButton_clicked();

    /**
     * invoke when login button clicked
     * @brief on_loginButton_clicked
     */
    void on_loginButton_clicked();

private:
    Ui::LoginDialog *ui;

    MapDialog* map;
};

#endif // LOGINDIALOG_H
