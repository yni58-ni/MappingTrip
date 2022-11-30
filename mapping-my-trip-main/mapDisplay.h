#ifndef MAPDISPLAY_H
#define MAPDISPLAY_H

#include <QDialog>
#include <QVariant>

namespace Ui {
class mapDisplay;
}

class mapDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit mapDisplay(QWidget *parent = nullptr);
    ~mapDisplay();

private:
    Ui::mapDisplay *ui;

signals:
    void setCenter(QVariant, QVariant);
    void addMarker(QVariant, QVariant);
};

#endif // MAPDISPLAY_H
