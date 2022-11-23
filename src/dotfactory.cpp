#include "dotfactory.h"

#include "dot.h"
#include "dotgraphicscomponent.h"
#include "dotphysicscomponent.h"
#include "gameobject.h"

DotFactory::DotFactory() {}

DotFactory::DotFactory(QGraphicsScene* scene) { this->scene = scene; }

DotFactory::DotFactory(PhysicsComponent* physics, GraphicsComponent* graphics) {
}

GameObject* DotFactory::CreateObject(QString name, QPoint pos) {
  Dot* dot = new Dot(name, new DotPhysicsComponent(),
                     new DotGraphicsComponent(name, *scene));
  dot->SetPos(pos * 20);

  return dot;
}
