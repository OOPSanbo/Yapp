#include "ghostphysicscomponent.h"

#include "direction.h"
#include "dynamicgameobject.h"

void GhostPhysicsComponent::Update(GameObject& object, Maze& maze) {
  DynamicGameObject& dynamicObject = static_cast<DynamicGameObject&>(object);

  QPoint pos = object.GetPos();

  eDirection direction = dynamicObject.GetDirection();
  eDirection nextDirection = dynamicObject.GetNextDirection();

  QPoint directionPoint = dir::ToPoint(direction);
  QPoint nextDirectionPoint = dir::ToPoint(dynamicObject.GetNextDirection());

  if (nextDirection != eDirection::STOP &&
      maze.CanTurnAroundToNextDirection(
          pos, directionPoint,
          nextDirectionPoint)) {  // check if pacman can change direction
    directionPoint = nextDirectionPoint;
    dynamicObject.SetDirection(nextDirection);
    dynamicObject.SetNextDirection(eDirection::STOP);
  }

  if (maze.CanFowardToDirection(pos,
                                directionPoint)) {  // check if pacman can move
    QPoint nextPos = QPoint(pos.x() + directionPoint.x() * 5,
                            pos.y() + directionPoint.y() * 5);
    object.SetPos(nextPos);
  }

  if (pos == QPoint(26 * 20, 14 * 20 - 10)) {
    object.SetPos(QPoint(10, 14 * 20 - 10));
  } else if (pos == QPoint(0, 14 * 20 - 10)) {
    object.SetPos(QPoint(26 * 20 - 10, 14 * 20 - 10));
  }

  if (dynamicObject.GetName() == "blinky")
    maze.blinkypos = pos;
  else if (dynamicObject.GetName() == "clyde")
    maze.clydepos = pos;
  else if (dynamicObject.GetName() == "inky")
    maze.inkypos = pos;
  else if (dynamicObject.GetName() == "pinky")
    maze.pinkypos = pos;
}
