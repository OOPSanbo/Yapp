#include "item.h"

Item::Item(QPoint pos) {
  this->pos = pos;
  setPos(this->pos);
}

QPoint Item::getPos() { return pos; }
