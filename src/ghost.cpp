#include "ghost.h"

#include <QList>
#include <QPixmap>
#include <QTimer>

Ghost::Ghost(QString name, InputComponent* input, PhysicsComponent* physics,
             GraphicsComponent* graphics)
    : DynamicGameObject(name, input, physics, graphics) {
  // TODO: Replace hardcoded positon & direction set
  x = 20 * 13.5;
  y = 20 * 11.5;
  direction = eDirection::DOWN;
  nextDirection = eDirection::UP;
}
