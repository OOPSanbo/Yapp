#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "gameobject.h"
#include "point.h"

class ObjectFactory {
 public:
  ObjectFactory();
  virtual GameObject* CreateObject(QString, Point) = 0;
};

#endif  // OBJECTFACTORY_H
