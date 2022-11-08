#include "pellet.h"
#include "item.h"

Pellet::Pellet(QPoint pos) : Item::Item(pos) {
  shape = new QPixmap(":/res/img/item/pellet.png");
  shape->scaledToWidth(20);
  setPixmap(*shape);
}

void Pellet::Eaten() {
  // emit PelletEaten();

  setVisible(false);
  delete this;
}
