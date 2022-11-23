#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsScene>
#include <QObject>

#include "maze.h"

class InputComponent;
class PhysicsComponent;
class GraphicsComponent;

class GameObject : public QObject {
  Q_OBJECT

 protected:
  QString name;
  int x;
  int y;

 public:
  GameObject();
  GameObject(QString name);
  QPoint GetPos();
  void SetPos(QPoint);
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
