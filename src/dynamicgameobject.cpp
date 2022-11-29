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

Direction::eDirection DynamicGameObject::GetDirection() { return direction; }

Direction::eDirection DynamicGameObject::GetNextDirection() { return nextDirection; }

void DynamicGameObject::SetDirection(Direction::eDirection direction) {
  this->direction = direction;
}

void DynamicGameObject::SetNextDirection(Direction::eDirection nextDirection) {
  this->nextDirection = nextDirection;
}

void DynamicGameObject::Update(Maze& maze) {
  input->Update(*this, maze);
  physics->Update(*this, maze);
  graphics->Update(*this);
}
