#ifndef MAZE_H
#define MAZE_H

#include <QGraphicsPixmapItem>
#include <QObject>

#define WIDTH 28
#define HEIGHT 31

class Maze : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
private:
  const unsigned int width = 28;
  const unsigned int height = 31;
  QList<QList<int>> map;
  QList<QPixmap> sprites[4];

public:
  Maze();
  bool CanMove();
  QList<QPoint> WhereAreDots();
  QList<QPoint> WhereArePellets();
};

#endif // MAZE_H
