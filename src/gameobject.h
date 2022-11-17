#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsScene>
#include <QObject>

#include "direction.h"
// #include "graphicscomponent.h"
// #include "inputcomponent.h"
#include "maze.h"
// #include "physicscomponent.h"

class InputComponent;
class PhysicsComponent;
class GraphicsComponent;

class GameObject : public QObject {
  Q_OBJECT

 public:
  int x;
  int y;
  eDirection dir;
  eDirection nextDir;
  InputComponent* input;
  PhysicsComponent* physics;
  GraphicsComponent* graphics;

  GameObject(InputComponent*, PhysicsComponent*, GraphicsComponent*);
  void Update(Maze& maze);
};

class InputComponent : public QObject {
  Q_OBJECT
 public:
  virtual void Update(GameObject& obj) = 0;
};

class PhysicsComponent : public QObject {
  Q_OBJECT
 public:
  virtual void Update(GameObject& obj, Maze& maze) = 0;
};

class GraphicsComponent : public QObject {
  Q_OBJECT
 public:
  virtual void Update(GameObject& obj) = 0;
};

#endif  // GAMEOBJECT_H
