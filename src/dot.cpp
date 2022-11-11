#include "dot.h"
#include "item.h"
#include <QPixmap>

Dot::Dot(QPoint pos) : Item::Item(pos) {
  shape = QPixmap(":/res/img/item/dot.png");
  setPixmap(shape.scaledToWidth(shape.size().width() * 2.5));
}

void Dot::Eaten() {
  // emit DotEaten();

  setVisible(false);
  delete this;
}
