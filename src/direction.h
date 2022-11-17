#ifndef DIRECTION_H
#define DIRECTION_H

#include <QPoint>
namespace Direction {
const QPoint Up = QPoint(0, -1);
const QPoint Down = QPoint(0, 1);
const QPoint Left = QPoint(-1, 0);
const QPoint Right = QPoint(1, 0);
};  // namespace Direction

enum eDirection { STOP = -1, UP, DOWN, LEFT, RIGHT = 3 };

#endif  // DIRECTION_H
