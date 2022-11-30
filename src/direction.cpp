#include "direction.h"

Point Direction::ToPoint(eDirection enumDirection) {
  Point directionPoint;
  switch (enumDirection) {
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

Direction::eDirection Direction::ToEnumDirection(Point point) {
  if (point == Point(0, -1))
    return UP;
  else if (point == Point(0, 1))
    return DOWN;
  else if (point == Point(-1, 0))
    return LEFT;
  else if (point == Point(1, 0))
    return RIGHT;
  else
    return eDirection::STOP;
}

Direction::eDirection Direction::Reverse(eDirection enumDirection) {
  switch (enumDirection) {
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

Direction::eDirection Direction::RotateClockwise(eDirection enumDirection) {
  switch (enumDirection) {
    case UP:
      return RIGHT;
    case DOWN:
      return LEFT;
    case LEFT:
      return UP;
    case RIGHT:
      return DOWN;
    default:
      return STOP;
  }
}

Direction::eDirection Direction::RotateCounterClockwise(
    eDirection enumDirection) {
  return Reverse(RotateClockwise(enumDirection));
}
