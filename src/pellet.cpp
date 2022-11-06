#include "pellet.h"
#include "item.h"

Pellet::Pellet(QPoint pos) : Item::Item(pos) {
  pic = new QPixmap(":/res/img/item/pellet.png");
  pic->scaledToWidth(20);
  setPixmap(*pic);
}
