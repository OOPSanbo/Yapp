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
    x = 260;
    y = 210;
    starttimer = 1;
  } else if (name == "pinky") {
    x = 260;
    y = 270;
    starttimer = 10;
  } else if (name == "inky") {
    x = 220;
    y = 270;
    starttimer = 50;
  } else if (name == "clyde") {
    x = 300;
    y = 270;
    starttimer = 100;
  }
  SetBehavior(GoOutGate);
  direction = Direction::RIGHT;
  nextDirection = Direction::RIGHT;
}

void Ghost::PelletEaten() {
  if (behavior != Dead && behavior != GoOutGate) SetBehavior(Frightened);
}
