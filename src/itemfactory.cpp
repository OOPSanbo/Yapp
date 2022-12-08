#include "itemfactory.h"

#include <QObject>
#include <iostream>

#include "gameobject.h"
#include "itemgraphicscomponent.h"
#include "itemphysicscomponent.h"
#include "staticgameobject.h"

ItemFactory::ItemFactory() {}

ItemFactory::ItemFactory(QGraphicsScene* scene) { this->scene = scene; }

GameObject* ItemFactory::CreateObject(QString name, QPointF cord) {
  ItemPhysicsComponent* dotphysicscomponent = new ItemPhysicsComponent();
  ItemGraphicsComponent* dotgraphicscomponent =
      new ItemGraphicsComponent(name, *scene);

  StaticGameObject* item =
      new StaticGameObject(name, Point(cord * guiGridSize));
  item->AddPhysicsComponent(dotphysicscomponent);
  item->AddGraphicsComponent(dotgraphicscomponent);

  return item;
}
