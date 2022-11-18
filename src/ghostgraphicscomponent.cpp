#include "ghostgraphicscomponent.h"

GhostGraphicsComponent::GhostGraphicsComponent(QGraphicsScene& graphics, QString name) {
  for (int i = 0; i < 8; i++) {
    sprite.append(QPixmap(":/res/img/ghost/" + name + "/" + QString::number(i) + ".png")
                      .scaledToHeight(scale));
  }
  shape.setPixmap(sprite[0]);
  shape.setTransformOriginPoint(scale / 2, scale / 2);
  graphics.addItem(&shape);

  index = 0;
  add = 1;
}

void GhostGraphicsComponent::Update(GameObject& obj) {
  shape.setPos(obj.x, obj.y);
  shape.setPixmap(sprite[index]);
  if (index == 0){
      index += add;
  }
  else {
      index -= add;
  }

  if (obj.nextDir != STOP) return;
  switch (obj.dir) {
    case (eDirection::UP):
      shape.setPixmap(sprite[index+6]);
      break;
    case (eDirection::DOWN):
      shape.setPixmap(sprite[index]);
      break;
    case (eDirection::LEFT):
      shape.setPixmap(sprite[index+2]);
      break;
    case (eDirection::RIGHT):
      shape.setPixmap(sprite[index+4]);
      break;
    case (eDirection::STOP):
      break;
  }
}
