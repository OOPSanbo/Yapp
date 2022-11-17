#include "gameobject.h"

GameObject::GameObject(InputComponent* input, PhysicsComponent* physics,
                       GraphicsComponent* graphics)
    : input(input), physics(physics), graphics(graphics) {}

void GameObject::Update(Maze& maze) {
  input->Update(*this);
  physics->Update(*this, maze);
  graphics->Update(*this);
}
