#include "ghost.h"

#include <QList>
#include <QPixmap>
#include <QTimer>

eGhostBehavior Ghost::GetBehavior() { return behavior; }

void Ghost::SetBehavior(eGhostBehavior behavior) { this->behavior = behavior; }

QPoint Ghost::GetTarget() { return target; }

void Ghost::SetTarget(QPoint target) { this->target = target; }

Ghost::Ghost(QString name, InputComponent* input, PhysicsComponent* physics,
             GraphicsComponent* graphics)
    : DynamicGameObject(name, input, physics, graphics) {
  // TODO: Replace hardcoded positon & direction set
  if (name == "blinky") {
    x = 20 * 4.5;
    y = 20 * 4.5;
  } else if (name == "pinky") {
    x = 20 * 24.5;
    y = 20 * 4.5;
  } else if (name == "inky") {
    x = 20 * 4.5;
    y = 20 * 24.5;
  } else if (name == "clyde") {
    x = 20 * 24.5;
    y = 20 * 24.5;
  }
  SetBehavior(Chase);
  direction = eDirection::DOWN;
  nextDirection = eDirection::RIGHT;
}

void Ghost::PelletEaten() { SetBehavior(Frightened); }
