#ifndef DIRECTION_H
#define DIRECTION_H

#include <math.h>

#include "point.h"

class Direction {
 public:
  enum eDirection { STOP = -1, UP, DOWN, LEFT, RIGHT = 3 };
  static Point ToPoint(eDirection enumDirection);
  static eDirection ToEnumDirection(Point point);
  static eDirection Reverse(eDirection enumDirection);
  static eDirection RotateClockwise(eDirection enumDirection);
  static eDirection RotateCounterClockwise(eDirection enumDirection);
};

#endif  // DIRECTION_H
