#include "scatterbehavior.h"

ScatterBehavior::ScatterBehavior() {}

void ScatterBehavior::Scatter(Ghost &ghostObject, Maze &maze) {
  QString name = ghostObject.GetName();
  if (name == "blinky") {
    ghostObject.SetTarget(QPoint(500, -60));
  } else if (name == "inky") {
    ghostObject.SetTarget(QPoint(20, 780));
  } else if (name == "pinky") {
    ghostObject.SetTarget(QPoint(60, -60));
  } else if (name == "clyde") {
    ghostObject.SetTarget(QPoint(500, 780));
  }
}
