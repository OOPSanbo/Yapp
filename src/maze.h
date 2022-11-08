#ifndef MAZE_H
#define MAZE_H

#include "direction.h"

#include <QGraphicsPixmapItem>
#include <QObject>

#define WIDTH 28
#define HEIGHT 31

class Maze : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
private:
  const int width = 28;
  const int height = 31;
  QList<QList<int>> map;
  bool CheckBound(QPoint pos);
  bool CheckWall(QPoint pos);

public:
  Maze();
  bool CanMove(QPoint pos, QPoint dir);
  QList<QPoint> WhereAreDots();
  QList<QPoint> WhereArePellets();
};

#endif // MAZE_H
