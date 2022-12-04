#ifndef GHOSTGRAPHICSCOMPONENT_H
#define GHOSTGRAPHICSCOMPONENT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>

#include "gameobject.h"
#include "ghost.h"

class GhostGraphicsComponent : public GraphicsComponent {
  Q_OBJECT
 public:
  QGraphicsPixmapItem shape;
  QList<QPixmap> sprite;
  QGraphicsScene& graphics;
  const int scale = 40;

  GhostGraphicsComponent(QGraphicsScene&, QString);
  virtual void Update(GameObject&);
  virtual void Delete();

 private:
  int base;
  int add;
  void ChangeSpriteFrightened(Ghost& ghostObject);
  void ChangeSpriteDead(Ghost& ghostObject);
  void ChangeSpriteDefault(Ghost& ghostObject);
  void RenderSprite(Ghost& ghostObject);
};

#endif  // GHOSTGRAPHICSCOMPONENT_H
