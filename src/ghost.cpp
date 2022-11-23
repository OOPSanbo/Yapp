#include "ghost.h"

#include <QList>
#include <QPixmap>
#include <QTimer>

Ghost::Ghost(InputComponent* input, PhysicsComponent* physics,
             GraphicsComponent* graphics, QString ghostname)
    : GameObject(input, physics, graphics) {
  x = 20 * 13.5;
  y = 20 * 11.5;
  dir = eDirection::DOWN;
  nextDir = eDirection::UP;
  name = ghostname;
}

/*index = 0;
  add = 1;
  this->pos = pos;

  setPos(this->pos);

  this->setTransformOriginPoint(20, 20);

  for (int i = 0; i < 8; i++) {
    pic.append(QPixmap(":/res/img/ghost/" + ghostname + "/" + QString::number(i)
+ ".png")); pic[i] = pic[i].scaledToHeight(40);
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
  if (!(maze->CanMove(pos+QPoint(10,10), direction))) {
    QList<QPoint> directions = {QPoint(1, 0), QPoint(0, 1), QPoint(-1, 0),
                                QPoint(0, -1)}; // Right, Down, Left, Up

    if (int(pos.y()) % 10 == 0 && pos.x() % 10 == 0) {
      int randomDirection = rand() % 4;
      direction = directions[randomDirection];
    }

    return;
  }

  pos += direction;
  setPos(pos);
}

Ghost::~Ghost() { delete timer; }*/
