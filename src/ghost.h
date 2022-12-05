#ifndef GHOST_H
#define GHOST_H

#include <QList>
#include <QObject>
#include <QPixmap>
#include <QWidget>

#include "dynamicgameobject.h"
#include "gameobject.h"
#include "point.h"

enum eGhostBehavior { Chase = 0, Scatter, Frightened, Dead, Stop, GoOutGate };

class Ghost : public DynamicGameObject {
  Q_OBJECT
 private:
  eGhostBehavior behavior;
  Point target;

 public:
  Ghost(QString, InputComponent*, PhysicsComponent*, GraphicsComponent*);
  Ghost(QString name, Point pos);
  eGhostBehavior GetBehavior();
  void SetBehavior(eGhostBehavior behavior);
  Point GetTarget();
  void SetTarget(Point target);
  int frightenedtimer = 0;
  int modetimer = 0;
  int speed = 1;
  int starttimer;
  void SetStartTimer(int timeLimit);

 private slots:
  void PelletEaten();
};
#endif  // GHOST_H
