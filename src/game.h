#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QTimer>
#include <QWidget>

#include "dotfactory.h"
#include "dynamicgameobject.h"
#include "gameobject.h"

class Game : public QObject {
  Q_OBJECT
 public:
  Game(QGraphicsScene *scene);
  void Init();
  void GameLoop();

 private:
  QGraphicsScene *scene;
  Maze *maze;
  GameObject *pacman;
  GameObject *blinky;

  QList<GameObject *> ghosts;
  QList<GameObject *> items;

  DotFactory *dotFactory;
 private slots:
  void Update();
};

#endif  // GAME_H
