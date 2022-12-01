#include "pacmangraphicscomponent.h"

#include "pacman.h"

PacmanGraphicsComponent::PacmanGraphicsComponent(QGraphicsScene& graphics)
    : graphics(graphics) {
  for (int i = 0; i < 3; i++) {
    sprite.append(QPixmap(":/res/img/pacman/" + QString::number(i) + ".png")
                      .scaledToHeight(scale));
  }
  shape.setPixmap(sprite[0]);
  shape.setTransformOriginPoint(scale / 2, scale / 2);
  graphics.addItem(&shape);

  index = 0;
  add = 1;
  lastPos = Point(0, 0);
}

void PacmanGraphicsComponent::Update(GameObject& object) {
  DynamicGameObject& dynamicObject = static_cast<DynamicGameObject&>(object);
  Pacman& pacman = static_cast<Pacman&>(object);

  if (pacman.lifeStatus) {
    shape.setPos(object.GetPos());
    if (object.GetPos() == lastPos) return;
    lastPos = object.GetPos();

    shape.setPixmap(sprite[index]);
    index += add;
    if (index >= 2 || index <= 0) add = -add;

    switch (dynamicObject.GetDirection()) {
      case (Direction::UP):
        shape.setRotation(270);
        break;
      case (Direction::DOWN):
        shape.setRotation(90);
        break;
      case (Direction::LEFT):
        shape.setRotation(180);
        break;
      case (Direction::RIGHT):
        shape.setRotation(0);
        break;
      case (Direction::STOP):
        break;
    }
  } else {
    if (index == 14) {
      index = 0;
      object.SetPos(QPoint(14 * 20 - 10, 17 * 20 - 10));
      pacman.lifeStatus = true;
      emit pacman.pacmanRevive();
    }
    shape.setPixmap(QPixmap(QString(":/res/img/pacman/dead/") +
                            QString::number(index) + QString(".png"))
                        .scaledToHeight(40));
    index += 1;
  }
}
void PacmanGraphicsComponent::Delete() { graphics.removeItem(&shape); }
