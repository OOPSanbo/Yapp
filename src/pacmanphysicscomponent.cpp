#include "pacmanphysicscomponent.h"

#include "direction.h"

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

void PacmanPhysicsComponent::Update(GameObject& obj, Maze& maze) {
  QPoint pos = QPoint(obj.x, obj.y);
  QPoint nextDir = DirToPoint(obj.nextDir);
  QPoint dir = DirToPoint(obj.dir);

  QPoint cord = PosToCord(pos);
  if (obj.nextDir != eDirection::STOP && maze.CanMove(cord, nextDir) &&
      obj.x % 10 == 0 && obj.y % 10 == 0) {
    obj.dir = obj.nextDir;
    obj.nextDir = eDirection::STOP;
  }

  if (maze.CanMove(cord, dir)) {
    obj.x += dir.x() * 2;
    obj.y += dir.y() * 2;
  }
}
