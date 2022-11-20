#ifndef MAZE_H
#define MAZE_H

#include <QGraphicsPixmapItem>
#include <QObject>

#include "direction.h"

#define WIDTH 28
#define HEIGHT 31

class Maze : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
 private:
  const int width = 28;
  const int height = 31;
  QList<QList<int>> map;
  bool CheckBound(QPoint pos);

 public:
  Maze();
  bool CheckWall(QPoint pos, QPoint dir);
  bool CanMove(QPoint pos, QPoint dir, QPoint nextdir);
  QList<QPoint> WhereAreDots();
  QList<QPoint> WhereArePellets();
};

#endif  // MAZE_H
