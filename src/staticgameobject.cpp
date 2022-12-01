#include "staticgameobject.h"

StaticGameObject::StaticGameObject() {}

StaticGameObject::StaticGameObject(QString name, PhysicsComponent* physics,
                                   GraphicsComponent* graphics)
    : GameObject(name), physics(physics), graphics(graphics) {}

void StaticGameObject::Update(Maze& maze) {
  physics->Update(*this, maze);
  graphics->Update(*this);
}
void StaticGameObject::Delete() { graphics->Delete(); }
