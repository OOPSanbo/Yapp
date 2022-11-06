#include "item.h"

Item::Item(QPoint pos) { this->pos = pos; }

QPoint Item::getPos() { return pos; }
