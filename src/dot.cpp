#include "dot.h"
#include "item.h"

Dot::Dot(QPoint pos) : Item::Item(pos) {
  shape = new QPixmap(":/res/img/item/dot.png");
  shape->scaledToWidth(20);
  setPixmap(*shape);
}

void Dot::Eaten() {
  // emit DotEaten();

  setVisible(false);
  delete this;
}
