#ifndef DIRECTION_H
#define DIRECTION_H

#include <math.h>

#include <QPoint>

enum eDirection { STOP = -1, UP, DOWN, LEFT, RIGHT = 3 };

class dir {
 public:
  static QPoint ToPoint(eDirection enumDir);
  static eDirection ToEnumDir(QPoint point);
  static double GetDistance(QPoint A, QPoint B);
};

#endif  // DIRECTION_H
