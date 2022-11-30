#ifndef PICTUREDIALOG_H
#define PICTUREDIALOG_H

#include <QDialog>
#include <QLabel>
#include "dbhelper.h"
#include "pictureentity.h"

namespace Ui {
class PictureDialog;
}

class PictureDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PictureDialog(int pointId, QWidget *parent = nullptr);
    ~PictureDialog();

    /**
     * query database and update picture list
     * @brief updateList
     */
    void updateList();

private slots:
    /**
     * invoke when add button clicked
     * @brief on_addButton_clicked
     */
    void on_addButton_clicked();

    /**
     * invoke when delete button clicked
     * @brief on_deleteButton_clicked
     */
    void on_deleteButton_clicked();

    /**
     * invoke when piture item clicked
     * @brief on_listView_clicked
     * @param index
     */
    void on_listView_clicked(const QModelIndex &index);

private:
    Ui::PictureDialog *ui;
    /**
     * current pointId
     * @brief pointId
     */
    int pointId;

    QLabel *label;

    DBHelper helper;
    QList<PictureEntity> list;
};

#endif // PICTUREDIALOG_H
