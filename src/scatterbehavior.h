#ifndef SCATTERBEHAVIOR_H
#define SCATTERBEHAVIOR_H

#include "ghost.h"
#include "maze.h"

class ScatterBehavior {
 public:
  ScatterBehavior();
  void Scatter(Ghost&, Maze&);
};

#endif  // SCATTERBEHAVIOR_H
