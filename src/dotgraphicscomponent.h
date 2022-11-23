#ifndef DOTGRAPHICSCOMPONENT_H
#define DOTGRAPHICSCOMPONENT_H

#include "gameobject.h"

class DotGraphicsComponent : public GraphicsComponent {
 private:
  QString name;
  QGraphicsPixmapItem shape;
  QPixmap sprite;
  const int scale = 20;

 public:
  DotGraphicsComponent();
  // TODO remove name
  DotGraphicsComponent(QString, QGraphicsScene&);
  virtual void Update(GameObject&);
};

#endif  // DOTGRAPHICSCOMPONENT_H
