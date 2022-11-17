#include "pacmangraphicscomponent.h"

PacmanGraphicsComponent::PacmanGraphicsComponent(QGraphicsScene& graphics) {
  for (int i = 0; i < 3; i++) {
    sprite.append(QPixmap(":/res/img/pacman/" + QString::number(i) + ".png")
                      .scaledToHeight(scale));
  }
  shape.setPixmap(sprite[0]);
  shape.setTransformOriginPoint(scale / 2, scale / 2);
  graphics.addItem(&shape);

  index = 0;
  add = 1;
}

void PacmanGraphicsComponent::Update(GameObject& obj) {
  shape.setPos(obj.x, obj.y);
  shape.setPixmap(sprite[index]);
  index += add;
  if (index >= 2 || index <= 0) add = -add;

  if (obj.nextDir != STOP) return;
  switch (obj.dir) {
    case (eDirection::UP):
      shape.setRotation(270);
      break;
    case (eDirection::DOWN):
      shape.setRotation(90);
      break;
    case (eDirection::LEFT):
      shape.setRotation(180);
      break;
    case (eDirection::RIGHT):
      shape.setRotation(0);
      break;
    case (eDirection::STOP):
      break;
  }
}
