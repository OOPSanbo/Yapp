QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/chasebehavior.cpp \
    src/demoinputcomponent.cpp \
    src/direction.cpp \
    src/dot.cpp \
    src/dotfactory.cpp \
    src/dotgraphicscomponent.cpp \
    src/dotphysicscomponent.cpp \
    src/dynamicgameobject.cpp \
    src/frightenedbehavior.cpp \
    src/game.cpp \
    src/gameobject.cpp \
    src/ghost.cpp \
    src/ghostgraphicscomponent.cpp \
    src/ghostinputcomponent.cpp \
    src/ghostphysicscomponent.cpp \
    src/keyinputcomponent.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/maze.cpp \
    src/objectfactory.cpp \
    src/pacman.cpp \
    src/pacmangraphicscomponent.cpp \
    src/pacmanphysicscomponent.cpp \
    src/pellet.cpp \
    src/point.cpp \
    src/scatterbehavior.cpp \
    src/score.cpp \
    src/soundengine.cpp \
    src/staticgameobject.cpp \
    src/title.cpp

HEADERS += \
    src/chasebehavior.h \
    src/demoinputcomponent.h \
    src/direction.h \
    src/dot.h \
    src/dotfactory.h \
    src/dotgraphicscomponent.h \
    src/dotphysicscomponent.h \
    src/dynamicgameobject.h \
    src/frightenedbehavior.h \
    src/game.h \
    src/gameobject.h \
    src/ghost.h \
    src/ghostgraphicscomponent.h \
    src/ghostinputcomponent.h \
    src/ghostphysicscomponent.h \
    src/keyinputcomponent.h \
    src/mainwindow.h \
    src/maze.h \
    src/objectfactory.h \
    src/pacman.h \
    src/pacmangraphicscomponent.h \
    src/pacmanphysicscomponent.h \
    src/pellet.h \
    src/point.h \
    src/scatterbehavior.h \
    src/score.h \
    src/soundengine.h \
    src/staticgameobject.h \
    src/title.h

FORMS += \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc \
