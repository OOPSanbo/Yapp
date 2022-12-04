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
  bool energized = false;
  int timer;

 signals:
  void pacmanRevive();

 public slots:
  void Energize();
};
#endif  // PACMAN_H
