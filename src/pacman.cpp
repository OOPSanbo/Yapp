#include "pacman.h"

#include <QList>
#include <QPixmap>
#include <QTimer>

Pacman::Pacman(QString name, InputComponent* input, PhysicsComponent* physics,
               GraphicsComponent* graphics)
    : DynamicGameObject(name, input, physics, graphics) {
  // TODO: Replace hardcoded positon & direction set
  x = 14 * 20 - 10;
  y = 17 * 20 - 10;
  direction = Direction::RIGHT;
  nextDirection = Direction::DOWN;
}

void Pacman::Energize() {
  energized = true;
  timer = 100;
}
