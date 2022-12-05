#ifndef GHOSTFACTORY_H
#define GHOSTFACTORY_H

#include "objectfactory.h"

class GhostFactory : public ObjectFactory {
 private:
  QGraphicsScene* scene;
  const int guiGridSize = 20;

 public:
  GhostFactory(QGraphicsScene* scene);
  virtual GameObject* CreateObject(QString name, QPointF cord);
};

#endif  // GHOSTFACTORY_H
