#ifndef ITEMGRAPHICSCOMPONENT_H
#define ITEMGRAPHICSCOMPONENT_H

#include "gameobject.h"

class ItemGraphicsComponent : public GraphicsComponent {
 private:
  QString name;
  QGraphicsPixmapItem shape;
  QGraphicsScene& graphics;
  QPixmap sprite;
  const int scale = 20;

 public:
  ItemGraphicsComponent();
  // TODO remove name
  ItemGraphicsComponent(QString, QGraphicsScene&);
  virtual void Update(GameObject&);
  virtual void Delete();
};

#endif  // ITEMGRAPHICSCOMPONENT_H
