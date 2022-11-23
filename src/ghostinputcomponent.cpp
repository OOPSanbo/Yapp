#include "ghostinputcomponent.h"

GhostInputComponent::GhostInputComponent() {}

void GhostInputComponent::Update(GameObject& obj) {
  if (obj.nextDir == eDirection::STOP) {
    obj.nextDir = static_cast<eDirection>(rand() % 4);
  }
}
