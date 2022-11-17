#ifndef PACMAN_H
#define PACMAN_H

#include <QKeyEvent>
#include <QList>
#include <QObject>
#include <QPixmap>
#include <QWidget>

#include "gameobject.h"

class Pacman : public GameObject {
  Q_OBJECT

 public:
  Pacman(InputComponent* input, PhysicsComponent* physics,
         GraphicsComponent* graphics);
};
#endif  // PACMAN_H
