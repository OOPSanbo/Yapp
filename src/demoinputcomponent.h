#ifndef DEMOINPUTCOMPONENT_H
#define DEMOINPUTCOMPONENT_H

#include "direction.h"
#include "gameobject.h"

class DemoInputComponent : public InputComponent {
 private:
  Direction::eDirection direction = Direction::LEFT;

 public:
  DemoInputComponent();
  virtual void Update(GameObject& obj, Maze& maze);
};

#endif  // DEMOINPUTCOMPONENT_H
