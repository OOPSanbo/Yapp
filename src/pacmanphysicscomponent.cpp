#include "pacmanphysicscomponent.h"

#include "dynamicgameobject.h"
#include "pacman.h"
void PacmanPhysicsComponent::Update(GameObject& object, Maze& maze) {
  DynamicGameObject& dynamicObject = static_cast<DynamicGameObject&>(object);
  Pacman& pacmanObject = static_cast<Pacman&>(object);

  QPoint pos = object.GetPos();
  Direction::eDirection direction = dynamicObject.GetDirection();
  Direction::eDirection nextDirection = dynamicObject.GetNextDirection();
  QPoint directionPoint = Direction::ToPoint(direction);
  QPoint nextDirectionPoint =
      Direction::ToPoint(dynamicObject.GetNextDirection());
  if (pacmanObject.lifeStatus) {
    if (nextDirection != Direction::eDirection::STOP &&
        maze.CanTurnAroundToNextDirection(
            pos, directionPoint,
            nextDirectionPoint)) {  // check if pacman can change direction
      directionPoint = nextDirectionPoint;
      dynamicObject.SetDirection(nextDirection);
      dynamicObject.SetNextDirection(Direction::eDirection::STOP);
    }

    if (maze.CanFowardToDirection(
            pos,
            directionPoint)) {  // check if pacman can move
      QPoint nextPos = QPoint(pos.x() + directionPoint.x() * 5,
                              pos.y() + directionPoint.y() * 5);
      object.SetPos(nextPos);
    }

    if (pos == QPoint(26 * 20, 14 * 20 - 10)) {  // check tunnel
      object.SetPos(QPoint(10, 14 * 20 - 10));
    } else if (pos == QPoint(0, 14 * 20 - 10)) {
      object.SetPos(QPoint(26 * 20 - 10, 14 * 20 - 10));
    }

    maze.pacmanpos = object.GetPos();
    maze.pacmandir = Direction::ToPoint(direction);

    if (maze.CheckCollisionGhost() && pacmanObject.lifeStatus) {
      emit pacmanObject.Eaten();
    }
  }
}
