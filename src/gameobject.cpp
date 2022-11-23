#include "gameobject.h"

GameObject::GameObject() {}

GameObject::GameObject(QString name) : name(name) {}

QPoint GameObject::GetPos() { return QPoint(x, y); }

void GameObject::SetPos(QPoint pos) {
  x = pos.x();
  y = pos.y();
}
