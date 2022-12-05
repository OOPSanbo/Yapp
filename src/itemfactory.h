#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "gameobject.h"
#include "objectfactory.h"

class ItemFactory : public ObjectFactory {
 private:
  QGraphicsScene* scene;
  const int guiGridSize = 20;

 public:
  ItemFactory();
  ItemFactory(QGraphicsScene* scene);

  virtual GameObject* CreateObject(QString name, QPointF cord);
};

#endif  // ITEMFACTORY_H
