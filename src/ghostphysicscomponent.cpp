#include "ghostphysicscomponent.h"

#include "direction.h"
#include "dynamicgameobject.h"

QPoint GhostPhysicsComponent::DirToPoint(eDirection direction) {
  QPoint point;
  switch (direction) {
    case UP:
      point = QPoint(0, -1);
      break;
    case DOWN:
      point = QPoint(0, 1);
      break;
    case LEFT:
      point = QPoint(-1, 0);
      break;
    case RIGHT:
      point = QPoint(1, 0);
      break;
    default:
      point = QPoint(0, 0);
  }
  return point;
}

QPoint GhostPhysicsComponent::PosToCord(QPoint point) {
  QPoint cord = QPoint(floor((point.x() + 10) / (double)20),
                       floor((point.y() + 10) / (double)20));
  return cord;
}

void GhostPhysicsComponent::Update(GameObject& object, Maze& maze) {
  DynamicGameObject& dynamicObject = static_cast<DynamicGameObject&>(object);

  QPoint pos = object.GetPos();

  eDirection direction = dynamicObject.GetDirection();
  eDirection nextDirection = dynamicObject.GetNextDirection();

  QPoint directionPoint = DirToPoint(direction);
  QPoint nextDirectionPoint = DirToPoint(dynamicObject.GetNextDirection());

  if (nextDirection != eDirection::STOP &&
      maze.CanMove(
          pos, directionPoint,
          nextDirectionPoint) &&  // check if pacman can change direction
      pos.x() % 10 == 0 &&
      pos.y() % 10 == 0) {
    directionPoint = nextDirectionPoint;
    dynamicObject.SetDirection(nextDirection);
    dynamicObject.SetNextDirection(eDirection::STOP);
  }

  if (maze.CheckWall(pos, directionPoint)) {  // check if pacman can move
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
