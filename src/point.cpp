#include "point.h"

#include "math.h"

Point::Point() {}

Point::Point(int x) : QPoint(x, x) {}

Point::Point(int x, int y) : QPoint(x, y) {}

Point::Point(QPoint point) : QPoint(point) {}

Point::Point(QPointF fPoint) : QPoint(int(fPoint.x()), int(fPoint.y())) {}

Point::Point(const Point &point) : QPoint(point.x(), point.y()) {}

Point &Point::operator=(const Point &point) {
  this->setX(point.x());
  this->setY(point.y());
  return *this;
}

Point &Point::operator=(const QPoint &qPoint) {
  this->setX(qPoint.x());
  this->setY(qPoint.y());
  return *this;
}

Point Point::operator+(const Point &point) const {
  return QPoint(*this) + QPoint(point);
}

Point Point::operator*(int factor) const { return QPoint(*this) * factor; }

double Point::distanceWith(const Point &point) const {
  return sqrt(pow(this->x() - point.x(), 2) + pow(this->y() - point.y(), 2));
}
