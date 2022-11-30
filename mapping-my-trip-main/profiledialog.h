#ifndef PROFILEDIALOG_H
#define PROFILEDIALOG_H

#include <QDialog>
#include "profileentity.h"
#include "dbhelper.h"
#include <string.h>
#include "editdialog.h"

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

class ProfileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProfileDialog(int userID, QWidget *parent = nullptr);
    ~ProfileDialog();
    void update();

private:
    Ui::ProfileDialog *ui;
    int userID;
    DBHelper db;
    ProfileEntity Profile;
};

#endif // PROFILEDIALOG_H
