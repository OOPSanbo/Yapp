#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QObject>
#include <QTimer>
#include <QWidget>

#include "character.h"
#include "dotmodel.h"
#include "graphicengine.h"
#include "item.h"
#include "maze.h"
#include "pacman.h"

class GameEngine : QObject {
  Q_OBJECT

public:
  GraphicEngine *graphicEngine;
  GameEngine();
  void StartGame();
  void EndGame();
  ~GameEngine();

private:
  const int width = 600;
  const int height = 800;

  Maze *maze;
  Character *pacman;
  QTimer *pacmanTimer;
  QList<Item *> items;
  DotModel dotModel;
  void InitMaze();
};

#endif // GAMEENGINE_H
