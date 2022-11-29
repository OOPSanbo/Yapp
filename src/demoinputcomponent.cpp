#include "demoinputcomponent.h"

#include <QDebug>

#include "dynamicgameobject.h"

DemoInputComponent::DemoInputComponent() {}

void DemoInputComponent::Update(GameObject& object, Maze& maze) {
  DynamicGameObject& dynamicObject = static_cast<DynamicGameObject&>(object);

  if (dynamicObject.GetNextDirection() == Direction::eDirection::STOP) {
    dynamicObject.SetNextDirection(static_cast<Direction::eDirection>(rand() % 4));
  }
}
