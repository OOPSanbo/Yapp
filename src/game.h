#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QTimer>
#include <QWidget>

#include "gameobject.h"

class Game : public QObject {
  Q_OBJECT
 public:
  Maze *maze;
  GameObject *pacman;
  GameObject *blinky;
  GameObject *clyde;
  GameObject *inky;
  GameObject *pinky;
  QList<GameObject *> ghosts;
  QList<GameObject *> items;

  Game(QGraphicsScene *scene);
  void Init();
  void GameLoop();

 private:
  QGraphicsScene *scene;

 private slots:
  void Update();
};

#endif  // GAME_H
