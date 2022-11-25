#include "title.h"

Title::Title(QGraphicsScene *scene) : scene(scene) {
  QPixmap titleLogo = QPixmap(":/res/img/title.png").scaled(366, 89);
  titleshape.setPixmap(titleLogo);
  titleshape.setPos(97, -60);
  scene->addItem(&titleshape);
}

bool Title::eventFilter(QObject *object, QEvent *event) {
  if (event->type() == QEvent::KeyPress) {
    scene->removeItem(&titleshape);
    OnKeyPress();
  }
  return false;
}
