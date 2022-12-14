#ifndef PACMANGRAPHICSCOMPONENT_H
#define PACMANGRAPHICSCOMPONENT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>

#include "gameobject.h"
// class GameObject;

class PacmanGraphicsComponent : public GraphicsComponent {
  Q_OBJECT
 public:
  QGraphicsPixmapItem shape;
  QList<QPixmap> sprite;
  QGraphicsScene& graphics;
  const int scale = 40;

  PacmanGraphicsComponent(QGraphicsScene& graphics);
  virtual void Update(GameObject& obj);
  virtual void Delete();

 private:
  int index;
  int add;
  Point lastPos;
};
#endif  // PACMANGRAPHICSCOMPONENT_H
