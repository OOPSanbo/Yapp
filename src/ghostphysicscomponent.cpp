#include "ghostphysicscomponent.h"

#include "direction.h"
#include "ghost.h"

void GhostPhysicsComponent::Update(GameObject& object, Maze& maze) {
  Ghost& ghostObject = static_cast<Ghost&>(object);

  QPoint pos = object.GetPos();
  eDirection direction = ghostObject.GetDirection();
  eDirection nextDirection = ghostObject.GetNextDirection();

  QPoint directionPoint = dir::ToPoint(direction);
  QPoint nextDirectionPoint = dir::ToPoint(ghostObject.GetNextDirection());

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
}
