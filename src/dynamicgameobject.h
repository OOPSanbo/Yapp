#ifndef DYNAMICGAMEOBJECT_H
#define DYNAMICGAMEOBJECT_H

#include "gameobject.h"

class DynamicGameObject : public GameObject {
 protected:
  eDirection direction;
  eDirection nextDirection;

  InputComponent *input;
  PhysicsComponent *physics;
  GraphicsComponent *graphics;

 public:
  DynamicGameObject();
  DynamicGameObject(QString);
  DynamicGameObject(InputComponent *, PhysicsComponent *, GraphicsComponent *);
  DynamicGameObject(QString, InputComponent *, PhysicsComponent *,
                    GraphicsComponent *);

  eDirection GetDirection();
  eDirection GetNextDirection();
  void SetDirection(eDirection);
  void SetNextDirection(eDirection);
  virtual void Update(Maze &);
};

#endif  // DYNAMICGAMEOBJECT_H
