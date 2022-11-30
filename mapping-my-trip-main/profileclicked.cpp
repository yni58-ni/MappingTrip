#include "profileclicked.h"
/**
 * @brief create a profile image in the map dialog so user can click on it to enter the profile dialog
 * @author Wenlong Zheng
 * @return
 */

ProfileClicked::ProfileClicked(int userID, QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent),
      userID(userID)
{
    dialog = new ProfileDialog(userID);
    connect(dialog,&ProfileDialog::transmit,this,&ProfileClicked::update);
}

ProfileClicked::~ProfileClicked() {}

void ProfileClicked::mousePressEvent(QMouseEvent* event) {
    /**
     * @brief open the profile dialog when user press on the profile image
     * @author Wenlong Zheng
     * @return
     */

    dialog -> setWindowTitle("Profile");
    dialog -> setModal(true);
    dialog -> exec();
    emit clicked();
}

void ProfileClicked::update(QString txt)
{
    /**
     * @brief translate the new profile image from profile dialog to the map dialog
     * @author Wenlong Zheng
     * @return
     */

    emit transmit(txt);
}
