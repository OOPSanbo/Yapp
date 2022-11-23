#include "pellet.h"

#include <QPixmap>

Pellet::Pellet(QString name, PhysicsComponent* physics,
               GraphicsComponent* graphics)
    : StaticGameObject(name, physics, graphics) {
  //  shape = QPixmap(":/res/img/item/pellet.png");
  //  setPixmap(shape.scaledToWidth(shape.size().width() * 2.5));
}

void Pellet::Eaten() {
  // emit PelletEaten();
}
