#include "ghost.h"

#include <QList>
#include <QPixmap>
#include <QTimer>

eGhostBehavior Ghost::GetBehavior() { return behavior; }

void Ghost::SetBehavior(eGhostBehavior behavior) { this->behavior = behavior; }

Point Ghost::GetTarget() { return target; }

void Ghost::SetTarget(Point target) { this->target = target; }

Ghost::Ghost(QString name, InputComponent* input, PhysicsComponent* physics,
             GraphicsComponent* graphics)
    : DynamicGameObject(name, input, physics, graphics) {
  // TODO: Replace hardcoded positon & direction set
  if (name == "blinky") {
    x = 270;
    y = 210;
    starttimer = 0;
  } else if (name == "pinky") {
    x = 270;
    y = 210;
    starttimer = 10;
  } else if (name == "inky") {
    x = 270;
    y = 210;
    starttimer = 50;
  } else if (name == "clyde") {
    x = 270;
    y = 210;
    starttimer = 100;
  }
  SetBehavior(Chase);
  direction = Direction::DOWN;
  nextDirection = Direction::RIGHT;
}

void Ghost::PelletEaten() {
  if (behavior != Dead) SetBehavior(Frightened);
}
