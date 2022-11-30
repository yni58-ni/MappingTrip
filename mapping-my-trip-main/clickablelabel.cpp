#include "clickablelabel.h"

/**
 * @brief create label in profile dialog for editing
 * @author Wenlong Zheng
 * @return
 */

ClickableLabel::ClickableLabel(int userID, QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent),
    userID(userID)
{
    content = "";
    dlg = new EditDialog(userID, NULL);
    connect(dlg,&EditDialog::transmit,this,&ClickableLabel::update);
}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    /**
     * @brief open the edit dialog when user press on the label
     * @author Wenlong Zheng
     * @return
     */
    dlg -> setModal(true);
    dlg -> setWindowTitle("Edit");
    dlg -> exec();
    content = dlg -> readContent();
    emit clicked();
}

QString ClickableLabel::Content(){
    return content;
}
void ClickableLabel::update(QString txt)
{
    /**
     * @brief update information from the edit dialog to the profile dialog
     * @author Wenlong Zheng
     * @return
     */
    dlg ->close();
    content = txt;
    QMessageBox::information(this,"Message","Successfully Saved");
    emit transmit(txt);
}
