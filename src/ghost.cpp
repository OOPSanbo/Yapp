#include "maze.h"
#include "ghost.h"

#include <QList>
#include <QPixmap>
#include <QTimer>

Ghost::Ghost(QPoint pos, QPoint direction, QString ghostname)
    : Character(pos, direction) { // TODO add size on param
  index = 0;
  add = 1;
  this->pos = pos;

  setPos(this->pos);

  this->setTransformOriginPoint(10, 10);

  for (int i = 0; i < 8; i++) {
    pic.append(QPixmap(":/res/img/ghost/" + ghostname + "/" + QString::number(i) + ".png"));
    pic[i] = pic[i].scaledToHeight(20);
  }
  setPixmap(pic[0]);

  timer = new QTimer();
  connect(timer, SIGNAL(timeout()), this, SLOT(Animate()));
  timer->setInterval(100);
  timer->start();
}

void Ghost::Animate() {
  setPixmap(pic[index]);
  if (direction.x()==0) {
    if (direction.y()==1){
        setPixmap(pic[index]);

    }
    else {
        setPixmap(pic[index+6]);
    }
  }
  else if (direction.x()==1){
      setPixmap(pic[index+4]);
  }
  else {
      setPixmap(pic[index+2]);
  }
  if (index == 0){
      index += add;
  }
  else {
      index -= add;
  }
}

void Ghost::Move(Maze *maze) {
  if (!(maze->CanMove(pos, direction))) {
    QList<QPoint> directions = {QPoint(1, 0), QPoint(0, 1), QPoint(-1, 0),
                                QPoint(0, -1)}; // Right, Down, Left, Up

    if (int(pos.y()) % 20 == 0 && pos.x() % 20 == 0) {
      int randomDirection = rand() % 4;
      direction = directions[randomDirection];
    }

    return;
  }

  pos += direction;
  setPos(pos);
}

Ghost::~Ghost() { delete timer; }
