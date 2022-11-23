#include "dotfactory.h"

#include "dot.h"
#include "gameobject.h"

DotFactory::DotFactory() {}

DotFactory::DotFactory(PhysicsComponent* physics, GraphicsComponent* graphics)
    : physics(physics), graphics(graphics) {}

GameObject* DotFactory::CreateObject(QString name, QPoint pos) {
  Dot* dot = new Dot(name, physics, graphics);
  dot->SetPos(pos * 20);

  return dot;
}
