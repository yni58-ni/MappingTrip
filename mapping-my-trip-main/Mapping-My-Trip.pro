TARGET = Mapping-My-Trip
QT = core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets location
CONFIG+= c++11

HEADERS += \
    clickablelabel.h \
    dbhelper.h \
    editdialog.h \
    logindialog.h \
    mapdialog.h \
    picturedialog.h \
    pictureentity.h \
    pointentity.h \
    profileclicked.h \
    profiledialog.h \
    profileentity.h \
    registerdialog.h \
    searchPlace.h \
    userentity.h \
    pathdialog.h \
    graph.h

SOURCES += \
    clickablelabel.cpp \
    dbhelper.cpp \
    editdialog.cpp \
    logindialog.cpp \
    main.cpp \
    mapdialog.cpp \
    picturedialog.cpp \
    pictureentity.cpp \
    pointentity.cpp \
    profileclicked.cpp \
    profiledialog.cpp \
    profileentity.cpp \
    registerdialog.cpp \
    searchPlace.cpp \
    userentity.cpp \
    pathdialog.cpp \
    graph.cpp
 


FORMS += \
    editdialog.ui \
    logindialog.ui \
    mapdialog.ui \
    picturedialog.ui \
    profiledialog.ui \
    registerdialog.ui \
    pathdialog.ui
   

RESOURCES += \
    qml.qrc
