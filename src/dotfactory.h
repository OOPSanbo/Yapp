#ifndef DOTFACTORY_H
#define DOTFACTORY_H

#include "dot.h"
#include "gameobject.h"
#include "objectfactory.h"
#include "point.h"

class DotFactory : public ObjectFactory {
 private:
  QGraphicsScene* scene;

 public:
  DotFactory();
  DotFactory(QGraphicsScene*);
  DotFactory(PhysicsComponent*, GraphicsComponent*);

  // get Score * to Connect Signal
  virtual GameObject* CreateObject(QString, Point);
  virtual GameObject* CreateObject(QString, Point, Score*);
};

#endif  // DOTFACTORY_H
