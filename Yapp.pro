QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/character.cpp \
    src/demoinputcomponent.cpp \
    src/dot.cpp \
    src/dotmodel.cpp \
    src/game.cpp \
    src/gameengine.cpp \
    src/gameobject.cpp \
    src/ghost.cpp \
    src/graphicengine.cpp \
    src/item.cpp \
    src/keyinputcomponent.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/maze.cpp \
    src/pacman.cpp \
    src/pacmangraphicscomponent.cpp \
    src/pacmanphysicscomponent.cpp \
    src/pellet.cpp

HEADERS += \
    src/character.h \
    src/demoinputcomponent.h \
    src/direction.h \
    src/dot.h \
    src/dotmodel.h \
    src/game.h \
    src/gameengine.h \
    src/gameobject.h \
    src/ghost.h \
    src/graphicengine.h \
    src/item.h \
    src/keyinputcomponent.h \
    src/mainwindow.h \
    src/maze.h \
    src/pacman.h \
    src/pacmangraphicscomponent.h \
    src/pacmanphysicscomponent.h \
    src/pellet.h

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc \
