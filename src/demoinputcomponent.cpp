#include "demoinputcomponent.h"

#include <QDebug>

DemoInputComponent::DemoInputComponent() {}

void DemoInputComponent::Update(GameObject& obj) {
  if (obj.nextDir == eDirection::STOP) {
    obj.nextDir = static_cast<eDirection>(rand() % 4);
  }
}
