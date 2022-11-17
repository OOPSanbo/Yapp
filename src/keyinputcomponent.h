#ifndef KEYINPUTCOMPONENT_H
#define KEYINPUTCOMPONENT_H

#include <QObject>

#include "gameobject.h"

class KeyInputComponent : QObject {
  Q_OBJECT
 public:
  KeyInputComponent();
  virtual void Update(GameObject& obj) = 0;
};

#endif  // KEYINPUTCOMPONENT_H
