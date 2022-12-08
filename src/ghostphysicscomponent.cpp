#include "ghostphysicscomponent.h"

#include "direction.h"
#include "ghost.h"

void GhostPhysicsComponent::Update(GameObject& object, Maze& maze) {
  Ghost& ghostObject = static_cast<Ghost&>(object);
  if (ghostObject.starttimer != 0) {
    return;
  }

  if (ghostObject.GetBehavior() == GoOutGate) {
    if (ghostObject.GetPos().x() > 260) {
      ghostObject.SetDirection(Direction::LEFT);

    } else if (ghostObject.GetPos().x() < 260) {
      ghostObject.SetDirection(Direction::RIGHT);
    } else if (ghostObject.GetPos().x() == 260 &&
               ghostObject.GetPos().y() >= 210 &&
               ghostObject.GetPos().y() <= 270) {
      ghostObject.SetPos(ghostObject.GetPos() + Point(0, -5));
      return;
    }
  }

  if (ghostObject.GetBehavior() != Stop) {
    Point pos = object.GetPos();
    Direction::eDirection direction = ghostObject.GetDirection();
    Direction::eDirection nextDirection = ghostObject.GetNextDirection();

    Point directionPoint = Direction::ToPoint(direction);
    Point nextDirectionPoint = Direction::ToPoint(nextDirection);

    if (nextDirection != Direction::STOP &&
        maze.CanTurnAroundToNextDirection(pos, direction, nextDirection)) {
      if (ghostObject.reversepreventer) {
        ghostObject.reversepreventer = false;
      } else {
        directionPoint = nextDirectionPoint;
        ghostObject.SetDirection(nextDirection);
        ghostObject.SetNextDirection(Direction::STOP);
        ghostObject.reversepreventer = true;
      }
    }
    int i;
    for (i = 0; i < ghostObject.speed; i++) {
      if (maze.CanFowardToDirection(pos, direction)) {
        pos = pos + directionPoint * 5;
        object.SetPos(pos);
      }
      if (ghostObject.GetBehavior() == Dead &&
          Point(260, 210) == ghostObject.GetPos()) {
        ghostObject.SetBehavior(Chase);
      }
      if (ghostObject.GetBehavior() != Dead) ghostObject.speed = 1;
      if (maze.IsEncounterIntersection(pos, ghostObject.GetDirection())) break;
    }
    if (pos == Point(26 * 20, 14 * 20 - 10)) {
      object.SetPos(Point(10, 14 * 20 - 10));
    } else if (pos == Point(0, 14 * 20 - 10)) {
      object.SetPos(Point(26 * 20 - 10, 14 * 20 - 10));
    }

    if (ghostObject.GetName() == "blinky") {
      if (ghostObject.GetBehavior() == Dead) {
        maze.blinkypos = Point(260, 270);
        return;
      }
      maze.blinkypos = pos;
      if (maze.CheckCollisionBlinky() &&
          (ghostObject.GetBehavior() == Frightened)) {
        emit ghostObject.Eaten();
        ghostObject.SetBehavior(Dead);
        ghostObject.speed = 4;
      }
    } else if (ghostObject.GetName() == "clyde") {
      if (ghostObject.GetBehavior() == Dead) {
        maze.clydepos = Point(260, 270);
        return;
      }
      maze.clydepos = pos;
      if (maze.CheckCollisionClyde() &&
          (ghostObject.GetBehavior() == Frightened)) {
        emit ghostObject.Eaten();
        ghostObject.SetBehavior(Dead);
        ghostObject.speed = 4;
      }
    } else if (ghostObject.GetName() == "inky") {
      if (ghostObject.GetBehavior() == Dead) {
        maze.inkypos = Point(260, 270);
        return;
      }
      maze.inkypos = pos;
      if (maze.CheckCollisionInky() &&
          (ghostObject.GetBehavior() == Frightened)) {
        emit ghostObject.Eaten();
        ghostObject.SetBehavior(Dead);
        ghostObject.speed = 4;
      }
    } else if (ghostObject.GetName() == "pinky") {
      if (ghostObject.GetBehavior() == Dead) {
        maze.pinkypos = Point(260, 270);
        return;
      }
      maze.pinkypos = pos;
      if (maze.CheckCollisionPinky() &&
          (ghostObject.GetBehavior() == Frightened)) {
        emit ghostObject.Eaten();
        ghostObject.SetBehavior(Dead);
        ghostObject.speed = 4;
      }
    }

    if (ghostObject.GetBehavior() != Frightened)
      ghostObject.frightenedtimer = 0;
    else
      ghostObject.frightenedtimer += 1;
    if (ghostObject.frightenedtimer >= 100) ghostObject.SetBehavior(Chase);

    if (ghostObject.GetBehavior() == Chase) {
      ghostObject.modetimer += 1;
      if (ghostObject.modetimer >= 100) {
        ghostObject.modetimer = 0;
        ghostObject.SetBehavior(Scatter);
      }
    } else if (ghostObject.GetBehavior() == Scatter) {
      ghostObject.modetimer += 1;
      if (ghostObject.modetimer >= 100) {
        ghostObject.modetimer = 0;
        ghostObject.SetBehavior(Chase);
      }
    } else {
      ghostObject.modetimer = 0;
    }
  }
}
