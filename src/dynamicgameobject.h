#ifndef DYNAMICGAMEOBJECT_H
#define DYNAMICGAMEOBJECT_H

#include "gameobject.h"

class DynamicGameObject : public GameObject {
 protected:
  Direction::eDirection direction;
  Direction::eDirection nextDirection;

  InputComponent *input;
  PhysicsComponent *physics;
  GraphicsComponent *graphics;

 public:
  DynamicGameObject();
  DynamicGameObject(QString);
  DynamicGameObject(InputComponent *, PhysicsComponent *, GraphicsComponent *);
  DynamicGameObject(QString, InputComponent *, PhysicsComponent *,
                    GraphicsComponent *);

  Direction::eDirection GetDirection();
  Direction::eDirection GetNextDirection();
  void SetDirection(Direction::eDirection);
  void SetNextDirection(Direction::eDirection);
  virtual void Update(Maze &);
  virtual void Delete();
};

#endif  // DYNAMICGAMEOBJECT_H
