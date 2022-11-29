#ifndef MAZE_H
#define MAZE_H

#include <QObject>

#include "direction.h"
#include "point.h"

#define WIDTH 28
#define HEIGHT 31

class Maze : public QObject {
  Q_OBJECT
 private:
  const int width = 28;
  const int height = 31;
  const int guiGridSize = 20;
  QList<QList<int>> map;
  bool CheckBound(Point pos);
  Point TranslateToMazeCord(Point pos);
  int ReferMapOnCord(Point cord);

 public:
  Maze();
  bool CanFowardToDirection(Point pos, Point dir);
  bool CanTurnAroundToNextDirection(Point pos, Point dir, Point nextdir);
  bool IsEncounterIntersection(Point pos, Point dir);
  QList<Point> WhereAreDots();
  QList<Point> WhereArePellets();
  Point pacmandir;
  Point pacmanpos;
  Point blinkypos;
  Point clydepos;
  Point inkypos;
  Point pinkypos;
  bool CheckCollisionGhost();
  bool CheckCollisionBlinky();
  bool CheckCollisionClyde();
  bool CheckCollisionInky();
  bool CheckCollisionPinky();
  bool CheckCollisionDot(Point dotpoint);
};

#endif  // MAZE_H
