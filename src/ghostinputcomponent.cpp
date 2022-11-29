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
                                    dir::ToPoint(ghostObject.GetDirection())))
    return;

  switch (ghostObject.GetBehavior()) {
    case Chase:
      chase->Chase(ghostObject, maze);
      break;
    case Scatter:
      scatter->Scatter(ghostObject, maze);
      break;
    case Frightened:
      // chase->Chase(ghostObject, maze);
      frightened->Frightened(ghostObject);
      return;
      break;
    case Eaten:
      ghostObject.SetTarget(QPoint(280, 260));
      break;
  }

  ghostObject.SetNextDirection(PathFind(ghostObject, maze));
  /*
  int timecounter = 0;
  if (timecounter < 100) {
    timecounter += 1;
  } else {
    timecounter = 0;
    if (ghostObject.GetBehavior() == Chase)
      ghostObject.SetBehavior(Scatter);
    else
      ghostObject.SetBehavior(Chase);
  }*/
}

eDirection GhostInputComponent::PathFind(Ghost& ghostObject, Maze& maze) {
  QPoint currentPos = ghostObject.GetPos();
  QPoint currentDir = dir::ToPoint(ghostObject.GetDirection());
  QPoint target = ghostObject.GetTarget();
  QPoint leftDir, rightDir;
  QPoint leftPos, rightPos, nextdir;
  double distOnCurrentDir, distOnLeftDir, distOnRightDir, minDir;

  if (currentDir.y()) {
    leftDir = dir::ToPoint(eDirection::LEFT);
    rightDir = dir::ToPoint(eDirection::RIGHT);
    leftPos = currentPos + leftDir;
    rightPos = currentPos + rightDir;
  } else {
    leftDir = dir::ToPoint(eDirection::UP);
    rightDir = dir::ToPoint(eDirection::DOWN);
    leftPos = currentPos + leftDir;
    rightPos = currentPos + rightDir;
  }
  if (maze.CanFowardToDirection(currentPos, currentDir))
    distOnCurrentDir = (dir::GetDistance(currentPos, target));
  else
    distOnCurrentDir = 1000;
  if (maze.CanFowardToDirection(leftPos, leftDir))
    distOnLeftDir = (dir::GetDistance(leftPos, target));
  else
    distOnLeftDir = 1000;
  if (maze.CanFowardToDirection(rightPos, rightDir))
    distOnRightDir = (dir::GetDistance(rightPos, target));
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

  return dir::ToEnumDir(nextdir);
}
