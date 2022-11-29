#include "chasebehavior.h"

ChaseBehavior::ChaseBehavior() {}

void AggressiveChaseBehavior::Chase(Ghost &ghostObject, Maze &maze) {
  ghostObject.SetTarget(maze.pacmanpos);
}

void AmbushChaseBehavior::Chase(Ghost &ghostObject, Maze &maze) {
  ghostObject.SetTarget(maze.pacmanpos + maze.pacmandir * 4);
}

void PatrollChaseBehavior::Chase(Ghost &ghostObject, Maze &maze) {
  ghostObject.SetTarget(2 * (maze.pacmanpos + maze.pacmandir * 2) -
                        maze.blinkypos);
}

void RandomChaseBehavior::Chase(Ghost &ghostObject, Maze &maze) {
  if (ghostObject.GetPos().distanceWith(maze.pacmanpos) >= 160)
    ghostObject.SetTarget(maze.pacmanpos);
  else
    ghostObject.SetTarget(Point(480, 1000));
}
