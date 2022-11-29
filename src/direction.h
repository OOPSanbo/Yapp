#ifndef DIRECTION_H
#define DIRECTION_H

#include <math.h>

#include <QPoint>

class Direction {
 public:
  enum eDirection { STOP = -1, UP, DOWN, LEFT, RIGHT = 3 };
  static QPoint ToPoint(eDirection enumDir);
  static eDirection ToEnumDir(QPoint point);
  static double GetDistance(QPoint A, QPoint B);
  static eDirection Reverse(eDirection enumDir);
};

#endif  // DIRECTION_H
