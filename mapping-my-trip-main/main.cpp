#include <QApplication>

#include "logindialog.h"
#include <QQmlEngine>
#include "mapdialog.h"

int main(int argc, char**argv)
{
    QApplication app(argc,argv);
    qmlRegisterType<MapDialog>("mapdialog",1,0,"MapDialog");


    LoginDialog dialog;
    dialog.show();
    return app.exec();
}

