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
  bool xBound = pos.x() >= 0 && pos.x() < (width - 1);
  bool yBound = pos.y() >= 0 && pos.y() < (height - 1);

  return xBound && yBound;
}

bool Maze::CheckWall(QPoint pos, QPoint dir) {
  pos = pos + dir;
  if (dir.x() == -1 || dir.y() == -1) {
    return map[floor((pos.y() + 10) / (double)20)]
              [floor((pos.x() + 10) / (double)20)] != 0;
  } else {
    return map[ceil((pos.y() + 10) / (double)20)]
              [ceil((pos.x() + 10) / (double)20)] != 0;
  }
}

bool Maze::CanChangeDir(QPoint pos, QPoint dir, QPoint nextdir) {
  if (dir == nextdir) {
    return true;
  } else if (dir + nextdir == QPoint(0, 0)) {
    return true;
  }
  pos = pos + nextdir;

  if (dir == QPoint(-1, 0) && nextdir == QPoint(0, 1)) {  // left > down
    return map[ceil((pos.y() + 10) / (double)20)]
              [ceil((pos.x() + 10) / (double)20)] != 0;
  } else if (dir == QPoint(1, 0) && nextdir == QPoint(0, 1)) {  // right > down
    return map[ceil((pos.y() + 10) / (double)20)]
              [ceil((pos.x()) / (double)20)] != 0;
  } else if (dir == QPoint(0, 1) && nextdir == QPoint(1, 0)) {  // down > right
    return map[ceil((pos.y()) / (double)20)]
              [ceil((pos.x() + 10) / (double)20)] != 0;
  } else if (dir == QPoint(0, -1) && nextdir == QPoint(1, 0)) {  // up > right
    return map[ceil((pos.y() + 10) / (double)20)]
              [ceil((pos.x() + 10) / (double)20)] != 0;
  } else if (dir == QPoint(-1, 0) && nextdir == QPoint(0, -1)) {  // left > up
    return map[floor((pos.y() + 10) / (double)20)]
              [floor((pos.x() + 20) / (double)20)] != 0;
  } else if (dir == QPoint(1, 0) && nextdir == QPoint(0, -1)) {  // right > up
    return map[floor((pos.y() + 10) / (double)20)]
              [floor((pos.x() + 10) / (double)20)] != 0;
  } else if (dir == QPoint(0, 1) && nextdir == QPoint(-1, 0)) {  // down > left
    return map[floor((pos.y() + 10) / (double)20)]
              [floor((pos.x() + 10) / (double)20)] != 0;
  } else if (dir == QPoint(0, -1) && nextdir == QPoint(-1, 0)) {  // up > left
    return map[floor((pos.y() + 20) / (double)20)]
              [floor((pos.x() + 10) / (double)20)] != 0;
  } else
    return false;
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

bool Maze::CheckCollisionDot(QPoint dotpoint) {
  if (pacmanpos.x() > dotpoint.x() + 10) return false;
  if (pacmanpos.x() + 20 < dotpoint.x()) return false;
  if (pacmanpos.y() > dotpoint.y() + 10) return false;
  if (pacmanpos.y() + 20 < dotpoint.y()) return false;
  return true;
}
