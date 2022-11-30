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

  // check if encounter intersection at next position
  Point nextPos =
      ghostObject.GetPos() + Direction::ToPoint(ghostObject.GetDirection()) * 5;
  if (!maze.IsEncounterIntersection(nextPos, ghostObject.GetDirection()))
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
      break;
    case Eaten:
      ghostObject.SetTarget(Point(280, 210));
      break;
  }

  ghostObject.SetNextDirection(FindNextDirection(ghostObject, maze));
}

Direction::eDirection GhostInputComponent::FindNextDirection(Ghost& ghostObject,
                                                             Maze& maze) {
  Direction::eDirection nextDir = Direction::STOP;

  Direction::eDirection currentDir = ghostObject.GetDirection();
  Direction::eDirection clockwiseDir = Direction::RotateClockwise(currentDir);
  Direction::eDirection counterClockwiseDir =
      Direction::RotateCounterClockwise(currentDir);

  Point currentPos = ghostObject.GetPos();

  Point currentCord = maze.TranslateToMazeCord(currentPos);
  Point nextCord = currentCord + Direction::ToPoint(currentDir);
  Point clockwiseCord = currentCord + Direction::ToPoint(clockwiseDir);
  Point counterClockwiseCord =
      currentCord + Direction::ToPoint(counterClockwiseDir);

  double distWithCurrentDir = 1000;
  double distWithClockwiseDir = 1000;
  double distWithCounterClockwiseDir = 1000;

  Point targetCord = maze.TranslateToMazeCord(ghostObject.GetTarget());

  if (maze.CanFowardToDirection(currentPos, currentDir)) {
    distWithCurrentDir = nextCord.distanceWith(targetCord);
  }

  if (maze.CanFowardToDirection(currentPos, clockwiseDir)) {
    distWithClockwiseDir = clockwiseCord.distanceWith(targetCord);
  }

  if (maze.CanFowardToDirection(currentPos, counterClockwiseDir)) {
    distWithCounterClockwiseDir = counterClockwiseCord.distanceWith(targetCord);
  }

  double minDist = qMin(distWithCurrentDir, distWithClockwiseDir);
  minDist = qMin(minDist, distWithCounterClockwiseDir);

  if (minDist == distWithCurrentDir)
    nextDir = currentDir;
  else if (minDist == distWithClockwiseDir)
    nextDir = clockwiseDir;
  else if (minDist == distWithCounterClockwiseDir)
    nextDir = counterClockwiseDir;

  return nextDir;
}
