#include "staticgameobject.h"

StaticGameObject::StaticGameObject() {}

void StaticGameObject::AddPhysicsComponent(PhysicsComponent* physics) {
  this->physics = physics;
}

void StaticGameObject::AddGraphicsComponent(GraphicsComponent* graphics) {
  this->graphics = graphics;
}

StaticGameObject::StaticGameObject(QString name, PhysicsComponent* physics,
                                   GraphicsComponent* graphics)
    : GameObject(name), physics(physics), graphics(graphics) {}

StaticGameObject::StaticGameObject(QString name, Point pos) {
  this->name = name;
  SetPos(pos);
}

void StaticGameObject::Update(Maze& maze) {
  physics->Update(*this, maze);
  graphics->Update(*this);
}
void StaticGameObject::Delete() { graphics->Delete(); }
