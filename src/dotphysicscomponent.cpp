#include "dotphysicscomponent.h"

#include "staticgameobject.h"

DotPhysicsComponent::DotPhysicsComponent() {}

void DotPhysicsComponent::Update(GameObject& object, Maze& maze) {
  StaticGameObject& staticObject = static_cast<StaticGameObject&>(object);

  if (staticObject.status == false) return;

  if (maze.CheckCollisionDot(staticObject.GetPos())) {
    staticObject.status = false;
    emit staticObject.Eaten();
  }
}
