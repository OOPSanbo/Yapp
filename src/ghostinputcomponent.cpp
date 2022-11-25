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
  // if not intersection, return
  Ghost& ghostObject = static_cast<Ghost&>(object);

  switch (ghostObject.GetBehavior()) {
    case Chase:
      chase->Chase(ghostObject, maze);
      break;
    case Scatter:
      // scatter->Scatter(ghostObject, maze);
      break;
    case Frightened:
      // frightened->Frightened(ghostObject, maze);
      break;
  }

  ghostObject.SetNextDirection(PathFind(ghostObject, maze));
}

eDirection GhostInputComponent::PathFind(Ghost& ghostObject, Maze& maze) {
  QPoint pos = ghostObject.GetPos();
  QPoint dir = dir::ToPoint(ghostObject.GetDirection());
  QPoint target = ghostObject.GetTarget();
  QPoint posA, posB, posC, nextdir;
  double distA, distB, distC, min;
  if (dir.x() == 0) {
    posB = pos + QPoint(1, 0);
    posC = pos + QPoint(-1, 0);
  } else {
    posB = pos + QPoint(0, 1);
    posC = pos + QPoint(0, -1);
  }
  if (maze.CheckWall(posA, QPoint(0, 0)))
    distA = (dir::GetDistance(posA, target));
  else
    distA = 1000;
  if (maze.CheckWall(posB, QPoint(0, 0)))
    distB = (dir::GetDistance(posB, target));
  else
    distB = 1000;
  if (maze.CheckWall(posC, QPoint(0, 0)))
    distC = (dir::GetDistance(posC, target));
  else
    distC = 1000;

  min = distA;
  if (min > distB) min = distB;
  if (min > distC) min = distC;

  if (min == distA)
    nextdir = posA - pos;
  else if (min == distB)
    nextdir = posB - pos;
  else if (min == distC)
    nextdir = posC - pos;

  return dir::ToEnumDir(nextdir);
}
