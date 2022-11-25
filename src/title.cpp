#include "title.h"
#define GHOST_SIZE 40
#define MARGIN 3
#define GRID_SIZE 20
#include <QTimer>
Title::Title(QGraphicsScene *scene) : scene(scene) {
  QPixmap titleLogo = QPixmap(":/res/img/title.png").scaled(390, 89);
  titleshape.setPixmap(titleLogo);
  titleshape.setPos(97, -60);
  scene->addItem(&titleshape);

  makeText("CHARACTER / NICKNAME", QPointF(7, 2.5));
  index = 0;
  characters << "SHADOM"
             << "SPEEDY"
             << "BASHFUL"
             << "POKEY";
  nicknames << "BLINKY"
            << "PINKY"
            << "INKY"
            << "CLYDE";
  int Height = 4;
  for (int index = 0; index < 4; index++) {
    images.append(QString(":/res/img/ghost/") + nicknames[index].toLower() +
                  QString("/4.png"));
    points.append(QPointF(4, Height));
    Height = Height + MARGIN;
  }

  timer = new QTimer();
  connectSignal =
      connect(timer, SIGNAL(timeout()), this, SLOT(printGenerator()));
  timer->start(1000);
}

bool Title::eventFilter(QObject *object, QEvent *event) {
  if (event->type() == QEvent::KeyPress) {
    disconnect(connectSignal);
    OnKeyPress();
  }
  return false;
}

void Title::printGenerator() {
  if (index < 4) {
    printer(images[index], characters[index], nicknames[index], points[index]);
  } else if (index == 4) {
    dotPrinter();
  } else if (index == 5) {
    printCredit();
  } else {
    disconnect(connectSignal);
  }
  index++;
}

void Title::printer(QString image, QString character, QString nickname,
                    QPointF point) {
  QString color = "white";
  makeImage(image, point, GHOST_SIZE);
  if (character == QString("SHADOM")) {
    color = QString("red");
  } else if (character == QString("SPEEDY")) {
    color = QString("pink");
  } else if (character == QString("BASHFUL")) {
    color = QString("skyblue");
  } else if (character == QString("POKEY")) {
    color = QString("orange");
  }
  makeText(QString('-') + character, point + QPointF(3, 0), color);
  makeText(QString('"') + nickname + QString('"'), point + QPointF(13, 0),
           color);
}
void Title::dotPrinter() {
  makeImage(":/res/img/item/dot.png", QPointF(11, 23), 20);
  makeText("10 pts", QPointF(13, 23));
  makeImage(":/res/img/item/pellet.png", QPointF(11, 25), 20);
  makeText("50 pts", QPointF(13, 25));
}
void Title::printCredit() {
  makeText("㉿Industrial Security OOP Pac-Man", QPointF(1, 28));
}
void Title::makeImage(QString imageSrc, QPointF coordinate, int size) {
  QGraphicsPixmapItem *newImage = new QGraphicsPixmapItem();
  newImage->setPixmap(QPixmap(imageSrc).scaledToHeight(size));
  newImage->setPos(coordinate * 20);
  scene->addItem(newImage);
}
void Title::makeText(QString text, QPointF coordinate, QString color) {
  QGraphicsTextItem *newText = scene->addText(text);
  newText->setPos(coordinate * 20);
  newText->setDefaultTextColor(color);
}
