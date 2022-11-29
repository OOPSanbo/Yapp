#ifndef GHOSTPHYSICSCOMPONENT_H
#define GHOSTPHYSICSCOMPONENT_H

#include <QObject>

#include "direction.h"
#include "gameobject.h"

class GhostPhysicsComponent : public PhysicsComponent {
  Q_OBJECT
 public:
  virtual void Update(GameObject& obj, Maze& maze);
};

#endif  // GHOSTPHYSICSCOMPONENT_H
