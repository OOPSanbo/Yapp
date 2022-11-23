#include "dynamicgameobject.h"

DynamicGameObject::DynamicGameObject() : GameObject() {}

DynamicGameObject::DynamicGameObject(QString name) : GameObject(name) {}

DynamicGameObject::DynamicGameObject(InputComponent* input,
                                     PhysicsComponent* physics,
                                     GraphicsComponent* graphics)
    : input(input), physics(physics), graphics(graphics) {}

DynamicGameObject::DynamicGameObject(QString name, InputComponent* input,
                                     PhysicsComponent* physics,
                                     GraphicsComponent* graphics)
    : GameObject(name), input(input), physics(physics), graphics(graphics) {}

eDirection DynamicGameObject::GetDirection() { return direction; }

eDirection DynamicGameObject::GetNextDirection() { return nextDirection; }

void DynamicGameObject::SetDirection(eDirection direction) {
  this->direction = direction;
}

void DynamicGameObject::SetNextDirection(eDirection nextDirection) {
  this->nextDirection = nextDirection;
}

void DynamicGameObject::Update(Maze& maze) {
  input->Update(*this);
  physics->Update(*this, maze);
  graphics->Update(*this);
}
