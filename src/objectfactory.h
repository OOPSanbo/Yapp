#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "gameobject.h"
#include "point.h"

class ObjectFactory {
 public:
  ObjectFactory();
  virtual GameObject* CreateObject(QString name, QPointF cord) = 0;
};

#endif  // OBJECTFACTORY_H
