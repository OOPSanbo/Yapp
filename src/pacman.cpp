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

  this->setTransformOriginPoint(20, 20);

  for (int i = 0; i < 3; i++) {
    pic.append(QPixmap(":/res/img/pacman/" + QString::number(i) + ".png"));
    pic[i] = pic[i].scaledToHeight(40);
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
    grabKeyboard();
    if (!(maze->CanMove(pos+QPoint(10,10), direction))) {
        direction = QPoint(0,0);
  }
  pos += direction;
  setPos(pos);
  if (pos.x() == 26*20 && pos.y() == 14 * 20-10){
      pos = QPoint(20,14*20-10);
      setPos(pos);
  }
  else if (pos.x() == 10 && pos.y() == 14 * 20-10){
      pos = QPoint(26*20,14*20-10);
      setPos(pos);
  }

}

void Pacman::keyPressEvent(QKeyEvent *e) {

    switch (e->key()) {
    case Qt::Key_W:
        direction = (Direction::Up);
        setRotation(270);
        break;
    case Qt::Key_A:
        direction = (Direction::Left);
        setRotation(180);
        break;
    case Qt::Key_S:
        direction = (Direction::Down);
        setRotation(90);
        break;
    case Qt::Key_D:
        direction = (Direction::Right);
        setRotation(0);
        break;
    }
}

Pacman::~Pacman() { delete timer; }
