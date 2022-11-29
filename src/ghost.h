#ifndef GHOST_H
#define GHOST_H

#include <QList>
#include <QObject>
#include <QPixmap>
#include <QWidget>

#include "dynamicgameobject.h"
#include "gameobject.h"
#include "point.h"

enum eGhostBehavior { Chase = 0, Scatter, Frightened, Eaten };

class Ghost : public DynamicGameObject {
  Q_OBJECT
 private:
  eGhostBehavior behavior;
  Point target;

 public:
  eGhostBehavior GetBehavior();
  void SetBehavior(eGhostBehavior behavior);
  Point GetTarget();
  void SetTarget(Point target);
  Ghost(QString, InputComponent*, PhysicsComponent*, GraphicsComponent*);
  int timer = 0;
  int speed = 1;

 private slots:
  void PelletEaten();
};
#endif  // GHOST_H
