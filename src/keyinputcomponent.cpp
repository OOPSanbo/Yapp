#include "keyinputcomponent.h"

#include <QDebug>

#include "dynamicgameobject.h"

KeyInputComponent::KeyInputComponent() {}

bool KeyInputComponent::eventFilter(QObject *object, QEvent *event) {
  if (event->type() != QEvent::KeyPress) {
    return false;
  }

  auto *keyEvent = static_cast<QKeyEvent *>(event);
  int key = keyEvent->key();

  switch (key) {
    case Qt::Key_Right:
    case Qt::Key_D:
      nextdir = eDirection::RIGHT;
      break;
    case Qt::Key_Left:
    case Qt::Key_A:
      nextdir = eDirection::LEFT;
      break;
    case Qt::Key_Up:
    case Qt::Key_W:
      nextdir = eDirection::UP;
      break;
    case Qt::Key_Down:
    case Qt::Key_S:
      nextdir = eDirection::DOWN;
      break;
  }

  return true;
}

void KeyInputComponent::Update(GameObject &object, Maze &maze) {
  DynamicGameObject &dynamicObject = static_cast<DynamicGameObject &>(object);

  dynamicObject.SetNextDirection(nextdir);
}
