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

  base = 0;
  add = 1;
}

void GhostGraphicsComponent::Update(GameObject& object) {
  Ghost& ghostObject = static_cast<Ghost&>(object);

  switch (ghostObject.GetBehavior()) {
    case Frightened:
      ChangeSpriteFrightened(ghostObject);
      break;
    case Dead:
      ChangeSpriteDead(ghostObject);
      break;
    case Stop:
      break;
    default:
      ChangeSpriteDefault(ghostObject);
  }

  RenderSprite(ghostObject);
}

void GhostGraphicsComponent::Delete() { graphics.removeItem(&shape); }

void GhostGraphicsComponent::ChangeSpriteFrightened(Ghost& ghostObject) {
  if (ghostObject.frightenedtimer >= 85) {
    base = 9;

  } else {
    base = 8;
  }
}

void GhostGraphicsComponent::ChangeSpriteDead(Ghost& ghostObject) {
  switch (ghostObject.GetDirection()) {
    case (Direction::UP):
      base = 15;
      break;
    case (Direction::DOWN):
      base = 12;
      break;
    case (Direction::LEFT):
      base = 13;
      break;
    case (Direction::RIGHT):
      base = 14;
      break;
    case (Direction::STOP):
      break;
  }
}

void GhostGraphicsComponent::ChangeSpriteDefault(Ghost& ghostObject) {
  switch (ghostObject.GetDirection()) {
    case (Direction::UP):
      base = 6;
      break;
    case (Direction::DOWN):
      base = 0;
      break;
    case (Direction::LEFT):
      base = 2;
      break;
    case (Direction::RIGHT):
      base = 4;
      break;
    case (Direction::STOP):
      break;
  }
}

void GhostGraphicsComponent::RenderSprite(Ghost& ghostObject) {
  shape.setPos(ghostObject.GetPos());
  if (base >= 12)
    shape.setPixmap(sprite[base]);
  else
    shape.setPixmap(sprite[base + add]);
  add ^= 1;
}
