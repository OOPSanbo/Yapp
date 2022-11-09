#include "pacman.h"
#include "maze.h"

#include <QList>
#include <QPixmap>
#include <QTimer>

Pacman::Pacman(QPoint pos, QPoint direction)
    : Character(pos, direction) { // TODO add size on param
  index = 0;
  add = 1;
  this->pos = pos;

  setPos(this->pos);

  this->setTransformOriginPoint(10, 10);

  for (int i = 0; i < 3; i++) {
    pic.append(QPixmap(":/res/img/pacman/" + QString::number(i) + ".png"));
    pic[i] = pic[i].scaledToHeight(20);
  }
  setPixmap(pic[0]);

  timer = new QTimer();
  connect(timer, SIGNAL(timeout()), this, SLOT(Animate()));
  timer->setInterval(100);
  timer->start();
}

void Pacman::Animate() {
  setPixmap(pic[index]);
  index += add;
  if (index >= 2 || index <= 0)
    add = -add;
}

void Pacman::Move(Maze *maze) {
  if (!(maze->CanMove(pos, direction))) {
    QList<QPoint> directions = {QPoint(1, 0), QPoint(0, 1), QPoint(-1, 0),
                                QPoint(0, -1)}; // Right, Down, Left, Up

    if (int(pos.y()) % 20 == 0 && pos.x() % 20 == 0) {
      int randomDirection = rand() % 4;
      direction = directions[randomDirection];
      switch (randomDirection) {
      case 0:
        setRotation(0);
        break;
      case 1:
        setRotation(90);
        break;
      case 2:
        setRotation(180);
        break;
      case 3:
        setRotation(270);
        break;
      default:
        break;
      }
    }

    return;
  }

  pos += direction;
  setPos(pos);
}

Pacman::~Pacman() { delete timer; }
