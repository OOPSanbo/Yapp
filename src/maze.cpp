#include "maze.h"

Maze::Maze() {
  map = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
         {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
          0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
         {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
          0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
         {0, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
          0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 2, 0},
         {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
          0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
         {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
         {0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,
          0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0},
         {0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,
          0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0},
         {0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0,
          0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0},
         {0, 0,  0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -1, 0,
          0, -1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,  0},
         {-1, -1, -1, -1, -1, 0, 1, 0, 0, 0,  0,  0,  -1, 0,
          0,  -1, 0,  0,  0,  0, 0, 1, 0, -1, -1, -1, -1, -1},
         {-1, -1, -1, -1, -1, 0, 1, 0, 0, -1, -1, -1, -1, -1,
          -1, -1, -1, -1, -1, 0, 0, 1, 0, -1, -1, -1, -1, -1},
         {-1, -1, -1, -1, -1, 0, 1, 0, 0, -1, 0,  0,  0,  0,
          0,  0,  0,  0,  -1, 0, 0, 1, 0, -1, -1, -1, -1, -1},
         {0,  0,  0,  0, 0,  0, 1, 0, 0, -1, 0, -1, -1, -1,
          -1, -1, -1, 0, -1, 0, 0, 1, 0, 0,  0, 0,  0,  0},
         {-1, -1, -1, -1, -1, -1, 1,  -1, -1, -1, 0,  -1, -1, -1,
          -1, -1, -1, 0,  -1, -1, -1, 1,  -1, -1, -1, -1, -1, -1},
         {0,  0,  0,  0, 0,  0, 1, 0, 0, -1, 0, -1, -1, -1,
          -1, -1, -1, 0, -1, 0, 0, 1, 0, 0,  0, 0,  0,  0},
         {-1, -1, -1, -1, -1, 0, 1, 0, 0, -1, 0,  0,  0,  0,
          0,  0,  0,  0,  -1, 0, 0, 1, 0, -1, -1, -1, -1, -1},
         {-1, -1, -1, -1, -1, 0, 1, 0, 0, -1, -1, -1, -1, -1,
          -1, -1, -1, -1, -1, 0, 0, 1, 0, -1, -1, -1, -1, -1},
         {-1, -1, -1, -1, -1, 0, 1, 0, 0, -1, 0,  0,  0,  0,
          0,  0,  0,  0,  -1, 0, 0, 1, 0, -1, -1, -1, -1, -1},
         {0, 0, 0, 0, 0,  0, 1, 0, 0, -1, 0, 0, 0, 0,
          0, 0, 0, 0, -1, 0, 0, 1, 0, 0,  0, 0, 0, 0},
         {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
          0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
         {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
          0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
         {0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0,
          0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
         {0,  2, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, -1,
          -1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 2, 0},
         {0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,
          0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0},
         {0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0,
          0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0},
         {0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0,
          0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0},
         {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
          0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
         {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0,
          0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
         {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
          1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
          0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
}

QList<Point> Maze::WhereAreDots() {
  QList<Point> dots;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (map[y][x] == 1) {
        dots.append(Point(x, y));
      }
    }
  }
  return dots;
}

QList<Point> Maze::WhereArePellets() {
  QList<Point> pellets;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (map[y][x] == 2) {
        pellets.append(Point(x, y));
      }
    }
  }
  return pellets;
}

bool Maze::CheckBound(Point pos) {
  bool xBound = pos.x() >= 0 && pos.x() < (width);
  bool yBound = pos.y() >= 0 && pos.y() < (height - 1);

  return xBound && yBound;
}

int Maze::ReferMapOnCord(Point cord) {
  if (CheckBound(cord) == false) return 0;
  return map[cord.y()][cord.x()];
}

Point Maze::TranslateToMazeCord(Point pos) {
  int cordX, cordY;

  cordX = floor(pos.x()) / (double)guiGridSize;
  cordY = floor(pos.y()) / (double)guiGridSize;

  return Point(cordX, cordY);
}

bool Maze::CanFowardToDirection(Point pos, Direction::eDirection dir) {
  Point dirPoint = Direction::ToPoint(dir);
  Point center = pos + Point(guiGridSize);
  Point nextMazeCord = TranslateToMazeCord(center) + dirPoint;

  if (ReferMapOnCord(nextMazeCord) != 0) {
    return true;
  }

  Point nextPosCenter =
      nextMazeCord * guiGridSize + Point(guiGridSize / 2, guiGridSize / 2);
  int hitBound, wallBound;
  bool canForward;

  switch (dir) {
    case Direction::UP:
      hitBound = center.y() - guiGridSize;
      wallBound = nextPosCenter.y();
      canForward = hitBound > wallBound;
      break;
    case Direction::DOWN:
      hitBound = center.y() + guiGridSize;
      wallBound = nextPosCenter.y();
      canForward = hitBound < wallBound;
      break;
    case Direction::LEFT:
      hitBound = center.x() - guiGridSize;
      wallBound = nextPosCenter.x();
      canForward = hitBound > wallBound;
      break;
    case Direction::RIGHT:
      hitBound = center.x() + guiGridSize;
      wallBound = nextPosCenter.x();
      canForward = hitBound < wallBound;
      break;
    default:
      canForward = false;
  }
  return canForward;
}

bool Maze::CanTurnAroundToNextDirection(Point pos, Point dir, Point nextdir) {
  if (dir == nextdir) {
    return true;
  }
  if (dir + nextdir == Point(0, 0)) {
    return true;
  }
  bool isDividableWithTen = pos.x() % 10 == 0 && pos.y() % 10 == 0;
  if (!isDividableWithTen) return false;

  bool isMultipleWithOddTen =
      (pos.x() / 10) % 2 == 1 && (pos.y() / 10) % 2 == 1;  // 10, 30, 50, ...
  if (!isMultipleWithOddTen) return false;

  pos = pos + nextdir;

  Point center = pos + Point(guiGridSize, guiGridSize);
  Point nextMazeCord = TranslateToMazeCord(center) + nextdir;

  if (ReferMapOnCord(nextMazeCord) != 0) {
    return true;
  }
  return false;
}

bool Maze::IsEncounterIntersection(Point pos, Point dir) {
  Point center = pos + Point(guiGridSize, guiGridSize);
  Point currentMazeCord = TranslateToMazeCord(center);

  int numIntersection = 0;

  for (int i = 0; i < 4; i++) {
    Direction::eDirection enumDir = static_cast<Direction::eDirection>(i);
    if (enumDir == Direction::ToEnumDirection(dir)) continue;

    Point nextMazeCord =
        currentMazeCord +
        Direction::ToPoint(static_cast<Direction::eDirection>(i));

    if (ReferMapOnCord(nextMazeCord) != 0) {
      numIntersection++;
    }
  }

  return numIntersection >= 2;
}

bool Maze::CheckCollisionBlinky() {
  if (pacmanpos.x() > blinkypos.x() + 40) return false;
  if (pacmanpos.x() + 40 < blinkypos.x()) return false;
  if (pacmanpos.y() > blinkypos.y() + 40) return false;
  if (pacmanpos.y() + 40 < blinkypos.y()) return false;
  return true;
}

bool Maze::CheckCollisionClyde() {
  if (pacmanpos.x() > clydepos.x() + 40) return false;
  if (pacmanpos.x() + 40 < clydepos.x()) return false;
  if (pacmanpos.y() > clydepos.y() + 40) return false;
  if (pacmanpos.y() + 40 < clydepos.y()) return false;
  return true;
}

bool Maze::CheckCollisionInky() {
  if (pacmanpos.x() > inkypos.x() + 40) return false;
  if (pacmanpos.x() + 40 < inkypos.x()) return false;
  if (pacmanpos.y() > inkypos.y() + 40) return false;
  if (pacmanpos.y() + 40 < inkypos.y()) return false;
  return true;
}

bool Maze::CheckCollisionPinky() {
  if (pacmanpos.x() > pinkypos.x() + 40) return false;
  if (pacmanpos.x() + 40 < pinkypos.x()) return false;
  if (pacmanpos.y() > pinkypos.y() + 40) return false;
  if (pacmanpos.y() + 40 < pinkypos.y()) return false;
  return true;
}

bool Maze::CheckCollisionGhost() {
  return (CheckCollisionBlinky() || CheckCollisionClyde() ||
          CheckCollisionInky() || CheckCollisionPinky());
}

bool Maze::CheckCollisionDot(Point dotpoint) {
  if (pacmanpos.x() > dotpoint.x() + 10) return false;
  if (pacmanpos.x() + 20 < dotpoint.x()) return false;
  if (pacmanpos.y() > dotpoint.y() + 10) return false;
  if (pacmanpos.y() + 20 < dotpoint.y()) return false;
  return true;
}
