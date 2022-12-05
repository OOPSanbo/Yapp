#include "pacman.h"

Pacman::Pacman(QString name, Point pos, Direction::eDirection direction)
    : DynamicGameObject(name, pos, direction) {}

void Pacman::Energize() {
  energized = true;
  timer = 100;
}
