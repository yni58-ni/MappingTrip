#ifndef PROFILEDIALOG_H
#define PROFILEDIALOG_H

#include <QDialog>
#include "profileentity.h"
#include "dbhelper.h"
#include <string.h>
#include "editdialog.h"
#include "clickablelabel.h"
#include <QFileDialog>

#include <QQuickItem>
#include <QMenu>
#include <QAction>
#include <QPixmap>
#include <QMessageBox>
#include <QString>
#include <QMouseEvent>
#include <QDebug>

namespace Ui {
class ProfileDialog;
}
/**
 * @brief Profile dialog is the ui for users to view their profile and edit it
 * @author Wenlong Zheng
 * @return
 */
class ProfileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProfileDialog(int userID, QWidget *parent = nullptr);
    ~ProfileDialog();
    /**
     * @brief update all the information to the database
     * @brief and refresh the dialog with the new data
     * @author Wenlong Zheng
     * @return
     */
    void update();
    /**
     * @brief generate the placeholders for the profile information
     * @author Wenlong Zheng
     * @return
     */
    void generate_profile();
    /**
     * @brief update the name to the profile from the edit dialog
     * @author Wenlong Zheng
     * @return
     */
    void update_name();
    /**
     * @brief update the gender to the profile from the edit dialog
     * @author Wenlong Zheng
     * @return
     */
    void update_gender();
    /**
     * @brief update the location to the profile from the edit dialog
     * @author Wenlong Zheng
     * @return
     */
    void update_location();
    /**
     * @brief update the tagline to the profile from the edit dialog
     * @author Wenlong Zheng
     * @return
     */
    void update_tagline();

signals:
    void transmit(QString txt);

private slots:
    void on_pushButton_clicked();

private:
    QFont font;
    Ui::ProfileDialog *ui;
    int userID;
    DBHelper db;
    ProfileEntity Profile;
    QList<ClickableLabel*> profile_list;
};

#endif // PROFILEDIALOG_H
