#ifndef PELLET_H
#define PELLET_H

#include <QPixmap>

#include "staticgameobject.h"

class Pellet : public StaticGameObject {
 signals:
  // void PelletEaten();

 public:
  QPixmap shape;
  Pellet(QString, PhysicsComponent*, GraphicsComponent*);
  virtual void Eaten();
};

#endif  // PELLET_H
