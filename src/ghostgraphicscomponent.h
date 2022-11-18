#ifndef GHOSTGRAPHICSCOMPONENT_H
#define GHOSTGRAPHICSCOMPONENT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>

#include "gameobject.h"

class GhostGraphicsComponent : public GraphicsComponent {
  Q_OBJECT
 public:
  QGraphicsPixmapItem shape;
  QList<QPixmap> sprite;
  const int scale = 40;

  GhostGraphicsComponent(QGraphicsScene& graphics, QString name);
  virtual void Update(GameObject& obj);

 private:
  int index;
  int add;
};

#endif // GHOSTGRAPHICSCOMPONENT_H
