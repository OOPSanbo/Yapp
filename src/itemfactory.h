#ifndef ITEMFACTORY_H
#define ITEMFACTORY_H

#include "gameobject.h"
#include "objectfactory.h"
#include "point.h"

class ItemFactory : public ObjectFactory {
 private:
  QGraphicsScene* scene;

 public:
  ItemFactory();
  ItemFactory(QGraphicsScene* scene);

  virtual GameObject* CreateObject(QString name, Point pos);
};

#endif  // ITEMFACTORY_H
