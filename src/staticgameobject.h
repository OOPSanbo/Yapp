#ifndef STATICGAMEOBJECT_H
#define STATICGAMEOBJECT_H

#include "gameobject.h"

class StaticGameObject : public GameObject {
 protected:
  PhysicsComponent *physics;
  GraphicsComponent *graphics;

 public:
  StaticGameObject();
  StaticGameObject(QString, PhysicsComponent *, GraphicsComponent *);

  virtual void Update(Maze &);
};

#endif  // STATICGAMEOBJECT_H
