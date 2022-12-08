#include "ghost.h"

Ghost::Ghost(QString name, Point pos, Direction::eDirection direction)
    : DynamicGameObject(name, pos, direction) {
  this->behavior = Stop;
}

eGhostBehavior Ghost::GetBehavior() { return behavior; }

void Ghost::SetBehavior(eGhostBehavior behavior) { this->behavior = behavior; }

Point Ghost::GetTarget() { return target; }

void Ghost::SetTarget(Point target) { this->target = target; }

void Ghost::SetStartTimer(int timeLimit) { starttimer = timeLimit; }

void Ghost::PelletEaten() {
  if (behavior != Dead && behavior != GoOutGate && behavior != Stop)
    SetBehavior(Frightened);
}
