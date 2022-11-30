#ifndef PROFILECLICKED_H
#define PROFILECLICKED_H

#include <QLabel>
#include <QWidget>
#include <Qt>
#include "profiledialog.h"

/**
 * @brief create a profile image in the map dialog so user can click on it to enter the profile dialog
 * @author Wenlong Zheng
 * @return
 */

class ProfileClicked : public QLabel {
    Q_OBJECT

public:
    explicit ProfileClicked(int userID, QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~ProfileClicked();

signals:
    void clicked();
    void transmit(QString txt);

protected:
    void mousePressEvent(QMouseEvent* event);

private:
    int userID;
    ProfileDialog * dialog;

private slots:
    void update(QString txt);
};

#endif // PROFILECLICKED_H
