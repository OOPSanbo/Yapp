#ifndef KEYINPUTCOMPONENT_H
#define KEYINPUTCOMPONENT_H

#include <QObject>
#include <QKeyEvent>

#include "direction.h"
#include "gameobject.h"

class KeyInputComponent : public InputComponent {
  Q_OBJECT
 private:
  eDirection nextdir = eDirection::STOP;

 public:
  KeyInputComponent();
  virtual void Update(GameObject& obj);
  bool eventFilter(QObject *obj, QEvent *event);
};

#endif  // KEYINPUTCOMPONENT_H
