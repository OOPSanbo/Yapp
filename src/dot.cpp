#include "dot.h"

#include <QPixmap>

Dot::Dot(QString name, PhysicsComponent* physics, GraphicsComponent* graphics)
    : StaticGameObject(name, physics, graphics) {
  // shape = QPixmap(":/res/img/item/dot.png");
  // setPixmap(shape.scaledToWidth(sshape.size().width() * 2.5));
}
