#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include "profileentity.h"

/**
 * @brief this is the header file for the edit dialog
 * @brief edit dialog will open a window for user to enter their input to edit their profile
 * @author Wenlong Zheng
 * @return
 */

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(int userID, QWidget *parent = nullptr);
    ~EditDialog();
    QString readContent();

signals:
    /**
     * @brief translate the new data to the profile dialog
     * @author Wenlong Zheng
     * @return
     */
    void transmit(QString txt);

private slots:

    void on_Save_clicked();

    void on_textEdit_textChanged();

    void on_Cancel_clicked();

private:
    Ui::EditDialog *ui;
    int userID;
};

#endif // EDITDIALOG_H
