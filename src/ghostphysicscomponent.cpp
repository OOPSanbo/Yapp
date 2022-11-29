#include "ghostphysicscomponent.h"

#include "direction.h"
#include "ghost.h"

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
  Ghost& ghostObject = static_cast<Ghost&>(object);

  QPoint pos = object.GetPos();
  eDirection direction = ghostObject.GetDirection();
  eDirection nextDirection = ghostObject.GetNextDirection();

  QPoint directionPoint = DirToPoint(direction);
  QPoint nextDirectionPoint = DirToPoint(ghostObject.GetNextDirection());

  if (nextDirection != eDirection::STOP &&
      maze.CanTurnAroundToNextDirection(
          pos, directionPoint,
          nextDirectionPoint)) {  // check if pacman can change direction
    directionPoint = nextDirectionPoint;
    ghostObject.SetDirection(nextDirection);
    ghostObject.SetNextDirection(eDirection::STOP);
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

  if (ghostObject.GetName() == "blinky") {
    maze.blinkypos = pos;
    if (maze.CheckCollisionBlinky() &&
        (ghostObject.GetBehavior() == Frightened)) {
      ghostObject.SetBehavior(Eaten);
      // speed up
    }
  } else if (ghostObject.GetName() == "clyde") {
    maze.clydepos = pos;
    if (maze.CheckCollisionClyde() &&
        (ghostObject.GetBehavior() == Frightened)) {
      ghostObject.SetBehavior(Eaten);
      // speed up
    }
  } else if (ghostObject.GetName() == "inky") {
    maze.inkypos = pos;
    if (maze.CheckCollisionInky() &&
        (ghostObject.GetBehavior() == Frightened)) {
      ghostObject.SetBehavior(Eaten);
      // speed up
    }
  } else if (ghostObject.GetName() == "pinky") {
    maze.pinkypos = pos;
    if (maze.CheckCollisionPinky() &&
        (ghostObject.GetBehavior() == Frightened)) {
      ghostObject.SetBehavior(Eaten);
      // speed up
    }
  }

  if (ghostObject.GetBehavior() != Frightened)
    ghostObject.timer = 0;
  else
    ghostObject.timer += 1;

  if (ghostObject.timer >= 100) ghostObject.SetBehavior(Chase);
}
