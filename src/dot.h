#ifndef DOT_H
#define DOT_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

#include "staticgameobject.h"

class Dot : public StaticGameObject {
 signals:
  // void DotEaten();

 public:
  QGraphicsPixmapItem shape;
  Dot(QString, PhysicsComponent*, GraphicsComponent*);
  virtual void Eaten();
};

#endif  // DOT_H
