#ifndef KEYINPUTCOMPONENT_H
#define KEYINPUTCOMPONENT_H

#include <QKeyEvent>
#include <QObject>

#include "direction.h"
#include "gameobject.h"

class KeyInputComponent : public InputComponent {
  Q_OBJECT
 private:
  Direction::eDirection nextdir = Direction::eDirection::STOP;

 public:
  KeyInputComponent();
  virtual void Update(GameObject &obj, Maze &maze);
  bool eventFilter(QObject *obj, QEvent *event);
};

#endif  // KEYINPUTCOMPONENT_H
