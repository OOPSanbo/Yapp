#include "pellet.h"
#include "item.h"
#include <QPixmap>

Pellet::Pellet(QPoint pos) : Item::Item(pos) {
  shape = QPixmap(":/res/img/item/pellet.png");
  setPixmap(shape.scaledToWidth(shape.size().width() * 2.5));
}

void Pellet::Eaten() {
  // emit PelletEaten();

  setVisible(false);
  delete this;
}
