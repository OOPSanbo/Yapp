#include "dot.h"
#include "item.h"

Dot::Dot(QPoint pos) : Item::Item(pos) {
  pic = new QPixmap(":/res/img/item/dot.png");
  pic->scaledToWidth(20);
  setPixmap(*pic);
}
