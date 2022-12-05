#include "itemfactory.h"

#include <QObject>
#include <iostream>

#include "dotgraphicscomponent.h"
#include "dotphysicscomponent.h"
#include "gameobject.h"
#include "staticgameobject.h"

ItemFactory::ItemFactory() {}

ItemFactory::ItemFactory(QGraphicsScene* scene) { this->scene = scene; }

GameObject* ItemFactory::CreateObject(QString name, Point pos) {
  DotPhysicsComponent* dotphysicscomponent = new DotPhysicsComponent();
  DotGraphicsComponent* dotgraphicscomponent =
      new DotGraphicsComponent(name, *scene);

  StaticGameObject* item = new StaticGameObject(name, pos * 20);
  item->AddPhysicsComponent(dotphysicscomponent);
  item->AddGraphicsComponent(dotgraphicscomponent);

  return item;
}
