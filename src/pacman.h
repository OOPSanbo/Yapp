#ifndef PACMAN_H
#define PACMAN_H

#include <QList>
#include <QObject>
#include <QPixmap>
#include <QWidget>

#include "character.h"
#include "maze.h"

class Pacman : public Character {
  Q_OBJECT
private:
  int index;
  int add;
  QTimer *timer;

public:
  QList<QPixmap> pic;
  Pacman(QPoint pos, QPoint direction);
  ~Pacman();

public slots:
  void Animate();
  void Move(Maze *maze);
};
#endif // PACMAN_H
