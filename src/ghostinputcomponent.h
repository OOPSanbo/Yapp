#ifndef GHOSTINPUTCOMPONENT_H
#define GHOSTINPUTCOMPONENT_H

#include "direction.h"
#include "gameobject.h"

class GhostInputComponent : public InputComponent {
 private:
  eDirection dir = eDirection::LEFT;

 public:
  GhostInputComponent();
  virtual void Update(GameObject& obj);
};

#endif // GHOSTINPUTCOMPONENT_H
