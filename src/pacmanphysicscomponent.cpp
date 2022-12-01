#include "pacmanphysicscomponent.h"

#include "dynamicgameobject.h"
#include "pacman.h"
void PacmanPhysicsComponent::Update(GameObject& object, Maze& maze) {
  Pacman& pacmanObject = static_cast<Pacman&>(object);

  Point pos = object.GetPos();
  Direction::eDirection direction = pacmanObject.GetDirection();
  Direction::eDirection nextDirection = pacmanObject.GetNextDirection();

  if (pacmanObject.lifeStatus) {
    if (nextDirection != Direction::eDirection::STOP &&
        maze.CanTurnAroundToNextDirection(
            pos, direction,
            nextDirection)) {  // check if pacman can change direction
      pacmanObject.SetDirection(nextDirection);
      pacmanObject.SetNextDirection(Direction::eDirection::STOP);
    }

    // check if pacman can move
    if (maze.CanFowardToDirection(pos, pacmanObject.GetDirection())) {
      pacmanObject.MoveToDirection();
    }

    // check tunnel
    if (pos == Point(26 * 20, 14 * 20 - 10)) {
      object.SetPos(Point(10, 14 * 20 - 10));
    } else if (pos == Point(0, 14 * 20 - 10)) {
      object.SetPos(Point(26 * 20 - 10, 14 * 20 - 10));
    }

    maze.pacmanpos = pos;
    maze.pacmandir = Direction::ToPoint(direction);

    if (maze.CheckCollisionGhost() && pacmanObject.lifeStatus) {
      emit pacmanObject.Eaten();
    }
  }
}
