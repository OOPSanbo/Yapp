#ifndef CHASEBEHAVIOR_H
#define CHASEBEHAVIOR_H

#include "ghost.h"
#include "maze.h"

class ChaseBehavior {
 private:
 public:
  ChaseBehavior();
  virtual void Chase(Ghost&, Maze&) = 0;
};

class AggressiveChaseBehavior : public ChaseBehavior {
 public:
  virtual void Chase(Ghost& ghostObject, Maze& maze);
};

class AmbushChaseBehavior : public ChaseBehavior {
 public:
  virtual void Chase(Ghost& ghostObject, Maze& maze);
};

class PatrollChaseBehavior : public ChaseBehavior {
 public:
  virtual void Chase(Ghost& ghostObject, Maze& maze);
};

class RandomChaseBehavior : public ChaseBehavior {
 public:
  virtual void Chase(Ghost& ghostObject, Maze& maze);
};

#endif  // CHASEBEHAVIOR_H
