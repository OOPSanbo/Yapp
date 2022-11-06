#include "pacman.h"
#include <QList>
#include <QPixmap>
#include <QTimer>

Pacman::Pacman() {
  // setOffset(QPoint(-7, -7));

  pos = QPointF(13.3, 22.6);
  index = 0;
  add = 1;

  for (int i = 0; i < 3; i++) {
    pic.append(QPixmap(":/res/img/pacman/" + QString::number(i) + ".png"));
    pic[i] = pic[i].scaledToHeight(30);
  }
  setPixmap(pic[0]);

  timer = new QTimer();
  connect(timer, SIGNAL(timeout()), this, SLOT(SwitchAnimate()));
  timer->setInterval(100);
  timer->start();
}

void Pacman::SwitchAnimate() {
  setPixmap(pic[index]);
  index += add;
  if (index >= 2 || index <= 0)
    add = -add;
}

Pacman::~Pacman() { delete timer; }
