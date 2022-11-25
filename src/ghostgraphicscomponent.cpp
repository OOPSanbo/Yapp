#include "ghostgraphicscomponent.h"

#include "ghost.h"

GhostGraphicsComponent::GhostGraphicsComponent(QGraphicsScene& graphics,
                                               QString name) {
  for (int i = 0; i < 8; i++) {
    sprite.append(
        QPixmap(":/res/img/ghost/" + name + "/" + QString::number(i) + ".png")
            .scaledToHeight(scale));
  }
  for (int i = 0; i < 4; i++) {
    sprite.append(QPixmap(":/res/img/ghost/nerf/" + QString::number(i) + ".png")
                      .scaledToHeight(scale));
  }
  for (int i = 0; i < 4; i++) {
    sprite.append(
        QPixmap(":/res/img/ghost/eaten/" + QString::number(i) + ".png")
            .scaledToHeight(scale));
  }

  shape.setPixmap(sprite[0]);
  shape.setTransformOriginPoint(scale / 2, scale / 2);
  graphics.addItem(&shape);

  index = 0;
  add = 1;
}

void GhostGraphicsComponent::Update(GameObject& object) {
  Ghost& ghostObject = static_cast<Ghost&>(object);
  if (ghostObject.GetBehavior() == Frightened) {
    if (index != 8)
      index = 8;
    else
      index = 9;
    shape.setPos(object.GetPos());
    shape.setPixmap(sprite[index]);

    return;
  }

  shape.setPos(object.GetPos());
  shape.setPixmap(sprite[index]);
  if (index % 2 == 0) {
    index += add;
  } else {
    index -= add;
  }

  if (ghostObject.GetNextDirection() != STOP) return;

  switch (ghostObject.GetDirection()) {
    case (eDirection::UP):
      index = 6;
      break;
    case (eDirection::DOWN):
      index = 0;
      break;
    case (eDirection::LEFT):
      index = 2;
      break;
    case (eDirection::RIGHT):
      index = 4;
      break;
    case (eDirection::STOP):
      break;
  }
}
