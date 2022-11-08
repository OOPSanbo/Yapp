#include "character.h"

Character::Character() {}

Character::Character(QPoint pos, QPoint direction) {
  this->pos = pos;
  this->direction = direction;
}

QPoint Character::GetPos() { return pos; }
