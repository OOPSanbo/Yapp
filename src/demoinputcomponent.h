#ifndef DEMOINPUTCOMPONENT_H
#define DEMOINPUTCOMPONENT_H

#include "direction.h"
#include "gameobject.h"

class DemoInputComponent : public InputComponent {
 private:
  eDirection dir = eDirection::LEFT;

 public:
  DemoInputComponent();
  virtual void Update(GameObject& obj, Maze& maze);
};

#endif  // DEMOINPUTCOMPONENT_H
