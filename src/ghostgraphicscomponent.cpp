#include "ghostgraphicscomponent.h"

#include "ghost.h"

GhostGraphicsComponent::GhostGraphicsComponent(QGraphicsScene& graphics,
                                               QString name)
    : graphics(graphics) {
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
  if (ghostObject.GetBehavior() != Stop) {
    if (ghostObject.GetBehavior() == Frightened) {
      if (index != 8)
        index = 8;
      else
        index = 9;
      shape.setPos(object.GetPos());
      shape.setPixmap(sprite[index]);

      return;
    }

    if (ghostObject.GetBehavior() == Eaten) {
      switch (ghostObject.GetDirection()) {
        case (Direction::UP):
          index = 15;
          break;
        case (Direction::DOWN):
          index = 12;
          break;
        case (Direction::LEFT):
          index = 13;
          break;
        case (Direction::RIGHT):
          index = 14;
          break;
        case (Direction::STOP):
          break;
      }

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

    if (ghostObject.GetNextDirection() != Direction::STOP) return;

    switch (ghostObject.GetDirection()) {
      case (Direction::UP):
        index = 6;
        break;
      case (Direction::DOWN):
        index = 0;
        break;
      case (Direction::LEFT):
        index = 2;
        break;
      case (Direction::RIGHT):
        index = 4;
        break;
      case (Direction::STOP):
        break;
    }
  }
}
void GhostGraphicsComponent::Delete() { graphics.removeItem(&shape); }
