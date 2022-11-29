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
  void lifeDisplay();

 private:
  QGraphicsScene *scene;

  Maze *maze;
  Score *score;
  QGraphicsPixmapItem *lifeLabel;
  int life;
  GameObject *pacman;
  GameObject *blinky;
  GameObject *clyde;
  GameObject *inky;
  GameObject *pinky;

  QList<GameObject *> ghosts;
  QList<GameObject *> items;

  DotFactory *dotFactory;

 private slots:
  void Update();
  void lifeDecrease();
};

#endif  // GAME_H
