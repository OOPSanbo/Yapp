#ifndef DEMOINPUTCOMPONENT_H
#define DEMOINPUTCOMPONENT_H

#include "direction.h"
#include "gameobject.h"

class DemoInputComponent : public InputComponent {
 private:
  eDirection dir;

 public:
  DemoInputComponent();
  virtual void Update(GameObject& obj);
};

#endif  // DEMOINPUTCOMPONENT_H
