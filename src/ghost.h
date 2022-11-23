#ifndef GHOST_H
#define GHOST_H

#include <QList>
#include <QObject>
#include <QPixmap>
#include <QWidget>

#include "dynamicgameobject.h"
#include "gameobject.h"

class Ghost : public DynamicGameObject {
  Q_OBJECT
 public:
  Ghost(QString, InputComponent*, PhysicsComponent*, GraphicsComponent*);
};
#endif  // GHOST_H
