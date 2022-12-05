#ifndef PACMANFACTORY_H
#define PACMANFACTORY_H

#include "objectfactory.h"

class PacmanFactory : public ObjectFactory {
 private:
  QGraphicsScene* scene;
  const int guiGridSize = 20;

 public:
  PacmanFactory(QGraphicsScene* scene);
  virtual GameObject* CreateObject(QString name, QPointF cord);
};

#endif  // PACMANFACTORY_H
