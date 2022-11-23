#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H

#include "gameobject.h"

class ObjectFactory {
 public:
  ObjectFactory();
  virtual GameObject* CreateObject(QString, QPoint) = 0;
};

#endif  // OBJECTFACTORY_H
