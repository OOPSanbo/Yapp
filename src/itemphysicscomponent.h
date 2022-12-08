#ifndef ITEMPHYSICSCOMPONENT_H
#define ITEMPHYSICSCOMPONENT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>

#include "gameobject.h"

class ItemPhysicsComponent : public PhysicsComponent {
 public:
  ItemPhysicsComponent();
  virtual void Update(GameObject&, Maze&);
};

#endif  // ITEMPHYSICSCOMPONENT_H
