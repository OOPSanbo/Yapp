#include "dot.h"
#include "item.h"
#include <QPixmap>

Dot::Dot(QPoint pos) : Item::Item(pos) {
  shape = QPixmap(":/res/img/item/dot.png");
  shape.scaledToHeight(40);
  setPixmap(shape);
}

void Dot::Eaten() {
  // emit DotEaten();

  setVisible(false);
  delete this;
}
