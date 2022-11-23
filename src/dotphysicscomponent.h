#ifndef DOTPHYSICSCOMPONENT_H
#define DOTPHYSICSCOMPONENT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>

#include "gameobject.h"

class DotPhysicsComponent : public PhysicsComponent {
 public:
  DotPhysicsComponent();
  virtual void Update(GameObject&, Maze&);
};

#endif  // DOTPHYSICSCOMPONENT_H
