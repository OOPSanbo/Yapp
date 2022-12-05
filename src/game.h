#ifndef GAME_H
#define GAME_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QTimer>
#include <QWidget>

#include "itemfactory.h"
#include "dynamicgameobject.h"
#include "gameobject.h"
#include "soundengine.h"

class Game : public QObject {
  Q_OBJECT
 public:
  Game(QGraphicsScene *scene);
  bool eventFilter(QObject *object, QEvent *event);
  void Init();
  void GameLoop();
  void lifeDisplay();
  void gameEnd();
  void GameClear();

 private:
  QGraphicsScene *scene;

  Maze *maze;
  Score *score;
  QGraphicsPixmapItem *lifeLabel;
  QGraphicsTextItem *gameOver;
  int life = 3;
  int dotnum;
  QMetaObject::Connection updateTimer;
  GameObject *pacman;
  GameObject *blinky;
  GameObject *clyde;
  GameObject *inky;
  GameObject *pinky;

  QList<GameObject *> ghosts;
  QList<GameObject *> items;
  SoundEngine *soundengine;
  ItemFactory *dotFactory;

 private slots:
  void Update();
  void lifeDecrease();
  void resume();
  void DotCount();
};

#endif  // GAME_H
