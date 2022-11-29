#include "scatterbehavior.h"

ScatterBehavior::ScatterBehavior() {}

void ScatterBehavior::Scatter(Ghost &ghostObject, Maze &maze) {
  QString name = ghostObject.GetName();
  if (name == "blinky") {
    ghostObject.SetTarget(Point(500, -60));
  } else if (name == "inky") {
    ghostObject.SetTarget(Point(20, 780));
  } else if (name == "pinky") {
    ghostObject.SetTarget(Point(60, -60));
  } else if (name == "clyde") {
    ghostObject.SetTarget(Point(500, 780));
  }
}
