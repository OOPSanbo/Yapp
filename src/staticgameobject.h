#ifndef STATICGAMEOBJECT_H
#define STATICGAMEOBJECT_H

#include "gameobject.h"
#include "point.h"

class StaticGameObject : public GameObject {
 protected:
  PhysicsComponent *physics;
  GraphicsComponent *graphics;

 public:
  bool status = true;
  StaticGameObject();
  StaticGameObject(QString, PhysicsComponent *, GraphicsComponent *);
  StaticGameObject(QString name, Point pos);
  void AddPhysicsComponent(PhysicsComponent *physics);
  void AddGraphicsComponent(GraphicsComponent *graphics);

  virtual void Update(Maze &maze);
  virtual void Delete();
};

#endif  // STATICGAMEOBJECT_H
