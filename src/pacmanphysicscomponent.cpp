#include "pacmanphysicscomponent.h"

#include "dynamicgameobject.h"

QPoint PacmanPhysicsComponent::DirToPoint(eDirection direction) {
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

QPoint PacmanPhysicsComponent::PosToCord(QPoint point) {
  QPoint cord = QPoint(floor((point.x() + 10) / (double)20),
                       floor((point.y() + 10) / (double)20));
  return cord;
}

void PacmanPhysicsComponent::Update(GameObject& object, Maze& maze) {
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
}
