#include "dotphysicscomponent.h"

#include "dot.h"
#include "staticgameobject.h"

DotPhysicsComponent::DotPhysicsComponent() {}

void DotPhysicsComponent::Update(GameObject& object, Maze& maze) {
  StaticGameObject& staticObject = static_cast<StaticGameObject&>(object);

  if (staticObject.status == false) return;

  if (maze.CheckCollisionDot(staticObject.GetPos())) {
    staticObject.status = false;
    if (staticObject.GetName() == QString("dot")) {
      emit staticObject.Eaten();

    } else if (staticObject.GetName() == QString("pellet")) {
      emit staticObject.Eaten();
      // change pacman and ghost status
    }
  }
}
