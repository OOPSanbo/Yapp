#include "dotphysicscomponent.h"

#include "staticgameobject.h"

DotPhysicsComponent::DotPhysicsComponent() {}

void DotPhysicsComponent::Update(GameObject& object, Maze& maze) {
  StaticGameObject& staticObject = static_cast<StaticGameObject&>(object);
  if (maze.CheckCollisionDot(staticObject.GetPos())) {
    staticObject.status = false;
    if (staticObject.GetName() == QString("dot")) {
      // dot score increase
    } else if (staticObject.GetName() == QString("pellet")) {
      // pellet score increase
      // change pacman and ghost status
    }
  }
}
