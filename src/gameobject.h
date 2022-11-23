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
  virtual void Update(Maze& maze) = 0;
  QString GetName();
};

class InputComponent : public QObject {
  Q_OBJECT
 public:
  virtual void Update(GameObject&) = 0;
};

class PhysicsComponent : public QObject {
  Q_OBJECT
 public:
  virtual void Update(GameObject&, Maze&) = 0;
};

class GraphicsComponent : public QObject {
  Q_OBJECT
 public:
  virtual void Update(GameObject&) = 0;
};

#endif  // GAMEOBJECT_H
