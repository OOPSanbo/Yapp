#include "itemgraphicscomponent.h"

#include "staticgameobject.h"

ItemGraphicsComponent::ItemGraphicsComponent(QString name,
                                             QGraphicsScene& graphics)
    : graphics(graphics) {
  sprite = QPixmap(":/res/img/item/" + name + ".png").scaledToHeight(scale);

  shape.setPixmap(sprite);
  shape.setTransformOriginPoint(scale / 2, scale / 2);
  graphics.addItem(&shape);
}

void ItemGraphicsComponent::Update(GameObject& object) {
  StaticGameObject& staticObject = static_cast<StaticGameObject&>(object);
  shape.setPos(object.GetPos());
  if (staticObject.status == false) {
    shape.setVisible(false);
    // Delete();
  }
}
void ItemGraphicsComponent::Delete() { graphics.removeItem(&shape); }
