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
  Point centerPos = pos + Point(guiGridSize, guiGridSize);

  cordX = floor(centerPos.x()) / (double)guiGridSize;
  cordY = floor(centerPos.y()) / (double)guiGridSize;

  return Point(cordX, cordY);
}

bool Maze::CanFowardToDirection(Point pos, Direction::eDirection dir) {
  Point dirPoint = Direction::ToPoint(dir);
  Point center = pos + Point(guiGridSize);
  Point nextMazeCord = TranslateToMazeCord(pos) + dirPoint;

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

bool Maze::CanTurnAroundToNextDirection(Point pos, Direction::eDirection dir,
                                        Direction::eDirection nextDir) {
  if (dir == nextDir || Direction::Reverse(dir) == nextDir) {
    return true;
  }

  bool isDividableWithTen = pos.x() % 10 == 0 && pos.y() % 10 == 0;
  if (!isDividableWithTen) return false;

  bool isMultipleWithOddTen =
      (pos.x() / 10) % 2 == 1 && (pos.y() / 10) % 2 == 1;  // 10, 30, 50, ...
  if (!isMultipleWithOddTen) return false;

  Point nextPos = pos + Direction::ToPoint(nextDir);

  Point nextMazeCord =
      TranslateToMazeCord(nextPos) + Direction::ToPoint(nextDir);

  if (ReferMapOnCord(nextMazeCord) != 0) {
    return true;
  } else
    return false;
}

bool Maze::IsEncounterIntersection(Point pos, Direction::eDirection dir) {
  Point currentMazeCord = TranslateToMazeCord(pos);

  int numIntersection = 0;

  for (int i = 0; i < 4; i++) {
    Direction::eDirection enumDir = static_cast<Direction::eDirection>(i);
    if (enumDir == dir) continue;

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
  Point pacmanCord = TranslateToMazeCord(pacmanpos);
  Point blinkyCord = TranslateToMazeCord(blinkypos);

  return pacmanCord == blinkyCord;
}

bool Maze::CheckCollisionClyde() {
  Point pacmanCord = TranslateToMazeCord(pacmanpos);
  Point clydeCord = TranslateToMazeCord(clydepos);

  return pacmanCord == clydeCord;
}

bool Maze::CheckCollisionInky() {
  Point pacmanCord = TranslateToMazeCord(pacmanpos);
  Point inkyCord = TranslateToMazeCord(inkypos);

  return pacmanCord == inkyCord;
}

bool Maze::CheckCollisionPinky() {
  Point pacmanCord = TranslateToMazeCord(pacmanpos);
  Point pinkyCord = TranslateToMazeCord(pinkypos);

  return pacmanCord == pinkyCord;
}

bool Maze::CheckCollisionGhost() {
  return (CheckCollisionBlinky() || CheckCollisionClyde() ||
          CheckCollisionInky() || CheckCollisionPinky());
}

bool Maze::CheckCollisionDot(Point dotpoint) {
  Point pacmanCord = TranslateToMazeCord(pacmanpos);
  Point dotCord = TranslateToMazeCord(dotpoint - Point(10, 10));

  return pacmanCord == dotCord;
  if (pacmanpos.x() > dotpoint.x() + 10) return false;
  if (pacmanpos.x() + 20 < dotpoint.x()) return false;
  if (pacmanpos.y() > dotpoint.y() + 10) return false;
  if (pacmanpos.y() + 20 < dotpoint.y()) return false;
  return true;
}
