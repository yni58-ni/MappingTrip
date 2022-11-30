#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

    QString getUserName();

    QString getPassword();

private slots:
    /**
     * invoke when accept button clicked
     * @brief on_acceptButton_clicked
     */
    void on_acceptButton_clicked();

    /**
     * invoke when cancel button clicked
     * @brief on_cancelButton_clicked
     */
    void on_cancelButton_clicked();

private:
    Ui::RegisterDialog *ui;
};

#endif // REGISTERDIALOG_H
