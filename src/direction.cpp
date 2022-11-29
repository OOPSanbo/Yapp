#include "direction.h"

Point Direction::ToPoint(eDirection enumDir) {
  Point directionPoint;
  switch (enumDir) {
    case UP:
      directionPoint = Point(0, -1);
      break;
    case DOWN:
      directionPoint = Point(0, 1);
      break;
    case LEFT:
      directionPoint = Point(-1, 0);
      break;
    case RIGHT:
      directionPoint = Point(1, 0);
      break;
    case STOP:
      directionPoint = Point(0, 0);
      break;
  }
  return directionPoint;
}

Direction::eDirection Direction::ToEnumDir(Point point) {
  if (point == Point(1, 0))
    return eDirection::RIGHT;
  else if (point == Point(-1, 0))
    return eDirection::LEFT;
  else if (point == Point(0, 1))
    return eDirection::DOWN;
  else if (point == Point(0, -1))
    return eDirection::UP;
  else
    return eDirection::STOP;
}

Direction::eDirection Direction::Reverse(eDirection enumDir) {
  switch (enumDir) {
    case UP:
      return DOWN;
    case DOWN:
      return UP;
    case LEFT:
      return RIGHT;
    case RIGHT:
      return LEFT;
    default:
      return STOP;
  }
}
