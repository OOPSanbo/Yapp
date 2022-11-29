#include "ghostphysicscomponent.h"

#include "direction.h"
#include "ghost.h"

void GhostPhysicsComponent::Update(GameObject& object, Maze& maze) {
  Ghost& ghostObject = static_cast<Ghost&>(object);
  if (ghostObject.GetBehavior() != Stop) {
    Point pos = object.GetPos();
    Direction::eDirection direction = ghostObject.GetDirection();
    Direction::eDirection nextDirection = ghostObject.GetNextDirection();

  Point directionPoint = Direction::ToPoint(direction);
  Point nextDirectionPoint = Direction::ToPoint(ghostObject.GetNextDirection());

    if (nextDirection != Direction::STOP &&
        maze.CanTurnAroundToNextDirection(
            pos, directionPoint,
            nextDirectionPoint)) {  // check if pacman can change direction
      directionPoint = nextDirectionPoint;
      ghostObject.SetDirection(nextDirection);
      ghostObject.SetNextDirection(Direction::eDirection::STOP);
    }
    int i;
    for (i = 0; i < ghostObject.speed; i++) {
      if (maze.CanFowardToDirection(pos, directionPoint)) {
        pos = pos + directionPoint * 5;
        object.SetPos(pos);
      }
      if (ghostObject.GetBehavior() == Eaten &&
          Point(280, 210) == ghostObject.GetPos()) {
        ghostObject.SetBehavior(Chase);
        ghostObject.speed = 1;
      }
    }
    if (pos == Point(26 * 20, 14 * 20 - 10)) {
      object.SetPos(Point(10, 14 * 20 - 10));
    } else if (pos == Point(0, 14 * 20 - 10)) {
      object.SetPos(Point(26 * 20 - 10, 14 * 20 - 10));
    }

    if (ghostObject.GetName() == "blinky") {
      maze.blinkypos = pos;
      if (maze.CheckCollisionBlinky() &&
          (ghostObject.GetBehavior() == Frightened)) {
        ghostObject.SetBehavior(Eaten);
        ghostObject.speed = 4;
      }
    } else if (ghostObject.GetName() == "clyde") {
      maze.clydepos = pos;
      if (maze.CheckCollisionClyde() &&
          (ghostObject.GetBehavior() == Frightened)) {
        ghostObject.SetBehavior(Eaten);
        ghostObject.speed = 4;
      }
    } else if (ghostObject.GetName() == "inky") {
      maze.inkypos = pos;
      if (maze.CheckCollisionInky() &&
          (ghostObject.GetBehavior() == Frightened)) {
        ghostObject.SetBehavior(Eaten);
        ghostObject.speed = 4;
      }
    } else if (ghostObject.GetName() == "pinky") {
      maze.pinkypos = pos;
      if (maze.CheckCollisionPinky() &&
          (ghostObject.GetBehavior() == Frightened)) {
        ghostObject.SetBehavior(Eaten);
        ghostObject.speed = 4;
      }
    }

    if (ghostObject.GetBehavior() != Frightened)
      ghostObject.timer = 0;
    else
      ghostObject.timer += 1;
    if (ghostObject.timer >= 100) ghostObject.SetBehavior(Chase);
  }
}
