#ifndef DOTFACTORY_H
#define DOTFACTORY_H

#include "gameobject.h"
#include "objectfactory.h"
#include "src/dot.h"

class DotFactory : public ObjectFactory {
 private:
  QGraphicsScene* scene;

 public:
  DotFactory();
  DotFactory(QGraphicsScene*);
  DotFactory(PhysicsComponent*, GraphicsComponent*);

  // get Score * to Connect Signal
  virtual GameObject* CreateObject(QString, QPoint);
  virtual GameObject* CreateObject(QString, QPoint, Score*);

};

#endif  // DOTFACTORY_H
