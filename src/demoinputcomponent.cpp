#include "demoinputcomponent.h"

#include <QDebug>

#include "dynamicgameobject.h"

DemoInputComponent::DemoInputComponent() {}

void DemoInputComponent::Update(GameObject& object) {
  DynamicGameObject& dynamicObject = static_cast<DynamicGameObject&>(object);

  if (dynamicObject.GetNextDirection() == eDirection::STOP) {
    dynamicObject.SetNextDirection(static_cast<eDirection>(rand() % 4));
  }
}
