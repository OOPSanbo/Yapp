#include "pacmangraphicscomponent.h"

#include "dynamicgameobject.h"

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

void PacmanGraphicsComponent::Update(GameObject& object) {
  DynamicGameObject& dynamicObject = static_cast<DynamicGameObject&>(object);

  shape.setPos(object.GetPos());
  shape.setPixmap(sprite[index]);
  index += add;
  if (index >= 2 || index <= 0) add = -add;

  if (dynamicObject.GetNextDirection() != STOP) return;

  switch (dynamicObject.GetDirection()) {
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
