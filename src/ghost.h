#ifndef GHOST_H
#define GHOST_H

#include <QList>
#include <QObject>
#include <QPixmap>
#include <QWidget>

#include "dynamicgameobject.h"
#include "gameobject.h"

enum eGhostBehavior { Chase = 0, Scatter, Frightened, Eaten };

class Ghost : public DynamicGameObject {
  Q_OBJECT
 private:
  eGhostBehavior behavior;
  QPoint target;

 public:
  eGhostBehavior GetBehavior();
  void SetBehavior(eGhostBehavior behavior);
  QPoint GetTarget();
  void SetTarget(QPoint target);
  Ghost(QString, InputComponent*, PhysicsComponent*, GraphicsComponent*);

 private slots:
  void PelletEaten();
};
#endif  // GHOST_H
