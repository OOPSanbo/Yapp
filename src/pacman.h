#ifndef PACMAN_H
#define PACMAN_H

#include <QList>
#include <QObject>
#include <QPixmap>
#include <QWidget>

#include "dynamicgameobject.h"

class Pacman : public DynamicGameObject {
  Q_OBJECT

 public:
  Pacman(QString, InputComponent*, PhysicsComponent*, GraphicsComponent*);
  bool lifeStatus = true;
};
#endif  // PACMAN_H
