#ifndef MAZE_H
#define MAZE_H

#include <QObject>

#include "direction.h"

#define WIDTH 28
#define HEIGHT 31

class Maze : public QObject {
  Q_OBJECT
 private:
  const int width = 28;
  const int height = 31;
  const int guiGridSize = 20;
  QList<QList<int>> map;
  bool CheckBound(QPoint pos);
  QPoint TranslateToMazeCord(QPoint pos);
  int ReferMapOnCord(QPoint cord);

 public:
  Maze();
  bool CanFowardToDirection(QPoint pos, QPoint dir);
  bool CanTurnAroundToNextDirection(QPoint pos, QPoint dir, QPoint nextdir);
  bool IsEncounterIntersection(QPoint pos, QPoint dir);
  QList<QPoint> WhereAreDots();
  QList<QPoint> WhereArePellets();
  QPoint pacmanpos;
  QPoint pacmandir;
  QPoint blinkypos;
  QPoint clydepos;
  QPoint inkypos;
  QPoint pinkypos;
  bool CheckCollisionGhost();
  bool CheckCollisionBlinky();
  bool CheckCollisionClyde();
  bool CheckCollisionInky();
  bool CheckCollisionPinky();
  bool CheckCollisionDot(QPoint dotpoint);
};

#endif  // MAZE_H
