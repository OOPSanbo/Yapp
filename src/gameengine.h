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

private slots:
  void PacManHandler();

private:
  const int width = 600;
  const int height = 800;

  Maze *maze;
  Character *pacman;
  QTimer *pacmanMoveTimer;
  QList<Item *> items;
  // DotModel dotModel;
  // PelletModel pelletModel;
  void InitMaze();
  void InitItem();
  void InitCharacter();
};

#endif // GAMEENGINE_H
