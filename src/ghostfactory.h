#ifndef GHOSTFACTORY_H
#define GHOSTFACTORY_H

#include "objectfactory.h"

class GhostFactory : public ObjectFactory {
 private:
  QGraphicsScene* scene;

 public:
  GhostFactory(QGraphicsScene* scene);

  virtual GameObject* CreateObject(QString name, Point pos);
};

#endif  // GHOSTFACTORY_H
