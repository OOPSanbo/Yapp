#ifndef POINT_H
#define POINT_H

#include <QPoint>

class Point : public QPoint {
 public:
  Point();
  Point(int x);
  Point(int x, int y);
  Point(QPoint point);
  Point(const Point& point);

  Point& operator=(const Point& point);
  Point& operator=(const QPoint& qPoint);
  Point operator+(const Point& point) const;
  Point operator*(int factor) const;

  double distanceWith(const Point& point) const;
};

#endif  // POINT_H
