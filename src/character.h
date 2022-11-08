#ifndef CHARACTER_H
#define CHARACTER_H

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QString>

#include "maze.h"

class Character : public QObject, public QGraphicsPixmapItem {
protected:
  const QString name;
  QPoint pos;
  QPoint direction;

public:
  Character();
  Character(QPoint pos, QPoint direction);
  QPoint GetPos();
public slots:
  virtual void Animate() = 0;
  virtual void Move(Maze *maze) = 0;
};

#endif // CHARACTER_H
