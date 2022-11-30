#include "pacmanphysicscomponent.h"

#include "dynamicgameobject.h"
#include "pacman.h"
void PacmanPhysicsComponent::Update(GameObject& object, Maze& maze) {
  DynamicGameObject& dynamicObject = static_cast<DynamicGameObject&>(object);
  Pacman& pacmanObject = static_cast<Pacman&>(object);

  Point pos = object.GetPos();
  Direction::eDirection direction = dynamicObject.GetDirection();
  Direction::eDirection nextDirection = dynamicObject.GetNextDirection();
  Point directionPoint = Direction::ToPoint(direction);
  Point nextDirectionPoint =
      Direction::ToPoint(dynamicObject.GetNextDirection());

  if (nextDirection != Direction::STOP &&
      maze.CanTurnAroundToNextDirection(
          pos, directionPoint,
          nextDirectionPoint)) {  // check if pacman can change direction
    directionPoint = nextDirectionPoint;
    dynamicObject.SetDirection(nextDirection);
    dynamicObject.SetNextDirection(Direction::STOP);
  }

  if (maze.CanFowardToDirection(pos,
                                direction)) {  // check if pacman can move
    Point nextPos = Point(pos.x() + directionPoint.x() * 5,
                          pos.y() + directionPoint.y() * 5);
    object.SetPos(nextPos);
  }

  if (pos == Point(26 * 20, 14 * 20 - 10)) {  // check tunnel
    object.SetPos(Point(10, 14 * 20 - 10));
  } else if (pos == Point(0, 14 * 20 - 10)) {
    object.SetPos(Point(26 * 20 - 10, 14 * 20 - 10));
  }

  maze.pacmanpos = object.GetPos();
  maze.pacmandir = Direction::ToPoint(direction);

  if (maze.CheckCollisionGhost()) {
    pacmanObject.lifeStatus = false;
    emit pacmanObject.Eaten();
  }
}
