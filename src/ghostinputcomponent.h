#ifndef GHOSTINPUTCOMPONENT_H
#define GHOSTINPUTCOMPONENT_H

#include "chasebehavior.h"
#include "direction.h"
#include "frightenedbehavior.h"
#include "gameobject.h"
#include "scatterbehavior.h"

class GhostInputComponent : public InputComponent {
 private:
  Direction::eDirection dir = Direction::LEFT;
  Direction::eDirection PathFind(Ghost& ghostObject, Maze& maze);
  ChaseBehavior* chase;
  ScatterBehavior* scatter;
  FrightenedBehavior* frightened;

 public:
  GhostInputComponent();
  GhostInputComponent(ChaseBehavior* chasebehavior);
  virtual void Update(GameObject& obj, Maze& maze);
};

#endif  // GHOSTINPUTCOMPONENT_H
