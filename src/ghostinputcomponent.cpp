#include "ghostinputcomponent.h"

#include "dynamicgameobject.h"
#include "ghost.h"

GhostInputComponent::GhostInputComponent() {
  chase = new AggressiveChaseBehavior();
  scatter = new ScatterBehavior();
  frightened = new FrightenedBehavior();
}

GhostInputComponent::GhostInputComponent(ChaseBehavior* chasebehavior) {
  chase = chasebehavior;
}

void GhostInputComponent::Update(GameObject& object, Maze& maze) {
  Ghost& ghostObject = static_cast<Ghost&>(object);
  if (!maze.IsEncounterIntersection(ghostObject.GetPos(),
                                    Direction::ToPoint(ghostObject.GetDirection())))
    return;

  switch (ghostObject.GetBehavior()) {
    case Chase:
      chase->Chase(ghostObject, maze);
      break;
    case Scatter:
      scatter->Scatter(ghostObject, maze);
      break;
    case Frightened:
      frightened->Frightened(ghostObject);
      return;
      break;
    case Eaten:
      ghostObject.SetTarget(QPoint(280, 260));
      break;
  }

  ghostObject.SetNextDirection(PathFind(ghostObject, maze));
}

Direction::eDirection GhostInputComponent::PathFind(Ghost& ghostObject, Maze& maze) {
  QPoint currentPos = ghostObject.GetPos();
  QPoint currentDir = Direction::ToPoint(ghostObject.GetDirection());
  QPoint target = ghostObject.GetTarget();
  QPoint leftDir, rightDir;
  QPoint leftPos, rightPos, nextdir;
  double distOnCurrentDir, distOnLeftDir, distOnRightDir, minDir;

  if (currentDir.y()) {
    leftDir = Direction::ToPoint(Direction::LEFT);
    rightDir = Direction::ToPoint(Direction::RIGHT);
    leftPos = currentPos + leftDir;
    rightPos = currentPos + rightDir;
  } else {
    leftDir = Direction::ToPoint(Direction::UP);
    rightDir = Direction::ToPoint(Direction::DOWN);
    leftPos = currentPos + leftDir;
    rightPos = currentPos + rightDir;
  }
  if (maze.CanFowardToDirection(currentPos, currentDir))
    distOnCurrentDir = (Direction::GetDistance(currentPos, target));
  else
    distOnCurrentDir = 1000;
  if (maze.CanFowardToDirection(leftPos, leftDir))
    distOnLeftDir = (Direction::GetDistance(leftPos, target));
  else
    distOnLeftDir = 1000;
  if (maze.CanFowardToDirection(rightPos, rightDir))
    distOnRightDir = (Direction::GetDistance(rightPos, target));
  else
    distOnRightDir = 1000;

  minDir = distOnCurrentDir;
  if (minDir > distOnLeftDir) minDir = distOnLeftDir;
  if (minDir > distOnRightDir) minDir = distOnRightDir;

  if (minDir == distOnCurrentDir)
    nextdir = currentPos - currentPos;
  else if (minDir == distOnLeftDir)
    nextdir = leftPos - currentPos;
  else if (minDir == distOnRightDir)
    nextdir = rightPos - currentPos;

  return Direction::ToEnumDir(nextdir);
}
