#include "dotgraphicscomponent.h"

#include "staticgameobject.h"

DotGraphicsComponent::DotGraphicsComponent(QString name,
                                           QGraphicsScene& graphics)
    : graphics(graphics) {
  sprite = QPixmap(":/res/img/item/" + name + ".png").scaledToHeight(scale);

  shape.setPixmap(sprite);
  shape.setTransformOriginPoint(scale / 2, scale / 2);
  graphics.addItem(&shape);
}

void DotGraphicsComponent::Update(GameObject& object) {
  StaticGameObject& staticObject = static_cast<StaticGameObject&>(object);
  shape.setPos(object.GetPos());
  if (staticObject.status == false) {
    shape.setVisible(false);
    // Delete();
  }
}
void DotGraphicsComponent::Delete() { graphics.removeItem(&shape); }
