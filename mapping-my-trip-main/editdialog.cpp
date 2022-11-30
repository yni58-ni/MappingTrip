#include "editdialog.h"
#include "ui_editdialog.h"

/**
 * @brief edit dialog will open a window for user to enter their input to edit their profile
 * @author Wenlong Zheng
 * @return
 */

EditDialog::EditDialog(int userID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog),
    userID(userID)
{
    ui->setupUi(this);
}

EditDialog::~EditDialog()
{
    delete ui;
}

void EditDialog::on_textEdit_textChanged()
{
    readContent();
}

QString EditDialog::readContent()
{
    return ui->textEdit->toPlainText();
}

void EditDialog::on_Save_clicked()
{
    /**
     * @brief translate the input data to the clickable labels
     * @author Wenlong Zheng
     * @return
     */
    emit transmit(ui->textEdit->toPlainText());
}


void EditDialog::on_Cancel_clicked()
{
    emit close();
}

