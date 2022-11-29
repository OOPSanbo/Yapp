#ifndef PACMANPHYSICSCOMPONENT_H
#define PACMANPHYSICSCOMPONENT_H

#include <QObject>

#include "direction.h"
#include "gameobject.h"

class PacmanPhysicsComponent : public PhysicsComponent {
  Q_OBJECT
 public:
  virtual void Update(GameObject&, Maze&);
};

#endif  // PACMANPHYSICSCOMPONENT_H
