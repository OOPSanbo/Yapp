#ifndef DIRECTION_H
#define DIRECTION_H

#include <math.h>

#include "point.h"

class Direction {
 public:
  enum eDirection { STOP = -1, UP, DOWN, LEFT, RIGHT = 3 };
  static Point ToPoint(eDirection enumDir);
  static eDirection ToEnumDir(Point point);
  static eDirection Reverse(eDirection enumDir);
};

#endif  // DIRECTION_H
