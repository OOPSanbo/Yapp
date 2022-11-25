#include "direction.h"

QPoint dir::ToPoint(eDirection enumDir) {
  QPoint directionPoint;
  switch (enumDir) {
    case UP:
      directionPoint = QPoint(0, -1);
      break;
    case DOWN:
      directionPoint = QPoint(0, 1);
      break;
    case LEFT:
      directionPoint = QPoint(-1, 0);
      break;
    case RIGHT:
      directionPoint = QPoint(1, 0);
      break;
    case STOP:
      directionPoint = QPoint(0, 0);
      break;
  }
  return directionPoint;
}

eDirection dir::ToEnumDir(QPoint point) {
  if (point == QPoint(1, 0))
    return eDirection::RIGHT;
  else if (point == QPoint(-1, 0))
    return eDirection::LEFT;
  else if (point == QPoint(0, 1))
    return eDirection::DOWN;
  else if (point == QPoint(0, -1))
    return eDirection::UP;
  else
    return eDirection::STOP;
}

double dir::GetDistance(QPoint A, QPoint B) {
  return sqrt(pow(A.x() - B.x(), 2) + pow(A.y() - B.y(), 2));
}
