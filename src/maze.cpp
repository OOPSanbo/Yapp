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

QList<QPoint> Maze::WhereAreDots() {
  QList<QPoint> dots;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (map[y][x] == 1) {
        dots.append(QPoint(x, y));
      }
    }
  }
  return dots;
}

QList<QPoint> Maze::WhereArePellets() {
  QList<QPoint> pellets;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      if (map[y][x] == 2) {
        pellets.append(QPoint(x, y));
      }
    }
  }
  return pellets;
}

bool Maze::CheckBound(QPoint pos) {
  bool xBound = pos.x() >= 0 && pos.x() < (width);
  bool yBound = pos.y() >= 0 && pos.y() < (height - 1);

  return xBound && yBound;
}

int Maze::ReferMapOnCord(QPoint cord) {
  if (CheckBound(cord) == false) return 0;
  return map[cord.y()][cord.x()];
}

QPoint Maze::TranslateToMazeCord(QPoint pos) {
  int cordX, cordY;

  cordX = floor(pos.x()) / (double)guiGridSize;
  cordY = floor(pos.y()) / (double)guiGridSize;

  return QPoint(cordX, cordY);
}

bool Maze::CanFowardToDirection(QPoint pos, QPoint dir) {
  QPoint center = pos + QPoint(guiGridSize, guiGridSize);
  QPoint nextMazeCord = TranslateToMazeCord(center) + dir;

  if (ReferMapOnCord(nextMazeCord) != 0) {
    return true;
  }

  QPoint nextPosCenter =
      nextMazeCord * guiGridSize + QPoint(guiGridSize / 2, guiGridSize / 2);
  int hitBound, wallBound;
  bool canForward;

  switch (Direction::ToEnumDir(dir)) {
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

bool Maze::CanTurnAroundToNextDirection(QPoint pos, QPoint dir,
                                        QPoint nextdir) {
  if (dir == nextdir) {
    return true;
  }
  if (dir + nextdir == QPoint(0, 0)) {
    return true;
  }
  bool isDividableWithTen = pos.x() % 10 == 0 && pos.y() % 10 == 0;
  if (!isDividableWithTen) return false;

  bool isMultipleWithOddTen =
      (pos.x() / 10) % 2 == 1 && (pos.y() / 10) % 2 == 1;  // 10, 30, 50, ...
  if (!isMultipleWithOddTen) return false;

  pos = pos + nextdir;

  QPoint center = pos + QPoint(guiGridSize, guiGridSize);
  QPoint nextMazeCord = TranslateToMazeCord(center) + nextdir;

  if (ReferMapOnCord(nextMazeCord) != 0) {
    return true;
  }
  return false;
}

bool Maze::IsEncounterIntersection(QPoint pos, QPoint dir) {
  QPoint center = pos + QPoint(guiGridSize, guiGridSize);
  QPoint currentMazeCord = TranslateToMazeCord(center);

  int numIntersection = 0;

  for (int i = 0; i < 4; i++) {
    Direction::eDirection enumDir = static_cast<Direction::eDirection>(i);
    if (enumDir == Direction::ToEnumDir(dir)) continue;

    QPoint nextMazeCord =
        currentMazeCord + Direction::ToPoint(static_cast<Direction::eDirection>(i));

    if (ReferMapOnCord(nextMazeCord) != 0) {
      numIntersection++;
    }
  }

  return numIntersection >= 2;
}

bool Maze::CheckCollisionBlinky() {
  if (pacmanpos.x() > blinkypos.x() + 30) return false;
  if (pacmanpos.x() + 30 < blinkypos.x()) return false;
  if (pacmanpos.y() > blinkypos.y() + 30) return false;
  if (pacmanpos.y() + 30 < blinkypos.y()) return false;
  return true;
}

bool Maze::CheckCollisionClyde() {
  if (pacmanpos.x() > clydepos.x() + 30) return false;
  if (pacmanpos.x() + 30 < clydepos.x()) return false;
  if (pacmanpos.y() > clydepos.y() + 30) return false;
  if (pacmanpos.y() + 30 < clydepos.y()) return false;
  return true;
}

bool Maze::CheckCollisionInky() {
  if (pacmanpos.x() > inkypos.x() + 30) return false;
  if (pacmanpos.x() + 30 < inkypos.x()) return false;
  if (pacmanpos.y() > inkypos.y() + 30) return false;
  if (pacmanpos.y() + 30 < inkypos.y()) return false;
  return true;
}

bool Maze::CheckCollisionPinky() {
  if (pacmanpos.x() > pinkypos.x() + 30) return false;
  if (pacmanpos.x() + 30 < pinkypos.x()) return false;
  if (pacmanpos.y() > pinkypos.y() + 30) return false;
  if (pacmanpos.y() + 30 < pinkypos.y()) return false;
  return true;
}

bool Maze::CheckCollisionGhost() {
  return (CheckCollisionBlinky() || CheckCollisionClyde() ||
          CheckCollisionInky() || CheckCollisionPinky());
}

bool Maze::CheckCollisionDot(QPoint dotpoint) {
  if (pacmanpos.x() > dotpoint.x() + 10) return false;
  if (pacmanpos.x() + 20 < dotpoint.x()) return false;
  if (pacmanpos.y() > dotpoint.y() + 10) return false;
  if (pacmanpos.y() + 20 < dotpoint.y()) return false;
  return true;
}
