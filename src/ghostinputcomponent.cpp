#include "ghostinputcomponent.h"

#include "dynamicgameobject.h"

GhostInputComponent::GhostInputComponent() {}

void GhostInputComponent::Update(GameObject& object) {
  DynamicGameObject& dynamicObject = static_cast<DynamicGameObject&>(object);

  if (dynamicObject.GetNextDirection() == eDirection::STOP) {
    dynamicObject.SetNextDirection(static_cast<eDirection>(rand() % 4));
  }
}
