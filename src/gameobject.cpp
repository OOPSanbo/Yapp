#include "gameobject.h"

GameObject::GameObject() {}

GameObject::GameObject(QString name) : name(name) {}

Point GameObject::GetPos() { return Point(x, y); }

void GameObject::SetPos(Point pos) {
  x = pos.x();
  y = pos.y();
}

QString GameObject::GetName() { return name; }
