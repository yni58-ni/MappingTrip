#ifndef MAP_H
#define MAP_H

#include <QMainWindow>

namespace Ui {
class map;
}

class map : public QMainWindow
{
    Q_OBJECT

public:
    explicit map(QWidget *parent = nullptr);
    ~map();

private:
    Ui::map *ui;
};

#endif // MAP_H
