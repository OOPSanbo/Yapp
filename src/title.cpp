#include "title.h"

#include <QTimer>
Title::Title(QGraphicsScene *scene) : scene(scene) {
  int const GHOST_IMAGE_WIDTH = 4;
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
    images.append(IMAGE_GHOST_SRC + nicknames[index].toLower() +
                  QString("/4.png"));
    points.append(QPointF(GHOST_IMAGE_WIDTH, Height));
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
    makeImage(QString(":/res/img/pacman/0.png"), QPointF(14, 18), 40);
    int width = 16;
    foreach (QString name, nicknames) {
      makeImage(
          QString(":/res/img/ghost/") + name.toLower() + QString("/2.png"),
          QPointF(width, 18), 40);
      width += 2;
    }
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
  int const IMAGE_WIDTH = 11;
  int const TEXT_WIDTH = 13;
  int const UPPER_INSTANCE_HEIGHT = 23;
  int const LOWER_INSTANCE_HEIGHT = 25;
  makeImage(IMAGE_ITEM_SRC + QString("dot.png"),
            QPointF(IMAGE_WIDTH, UPPER_INSTANCE_HEIGHT), 20);
  makeText("10 pts", QPointF(TEXT_WIDTH, UPPER_INSTANCE_HEIGHT));
  makeImage(IMAGE_ITEM_SRC + QString("pellet.png"),
            QPointF(IMAGE_WIDTH, LOWER_INSTANCE_HEIGHT), 20);
  makeText("50 pts", QPointF(TEXT_WIDTH, LOWER_INSTANCE_HEIGHT));
}
void Title::printCredit() {
  makeText("㉿Industrial Security OOP Pac-Man", QPointF(1, 28));
}
void Title::makeImage(QString imageSrc, QPointF coordinate, int size) {
  QGraphicsPixmapItem *newImage = new QGraphicsPixmapItem();
  newImage->setPixmap(QPixmap(imageSrc).scaledToHeight(size));
  newImage->setPos(coordinate * GRID_SIZE);
  scene->addItem(newImage);
}
void Title::makeText(QString text, QPointF coordinate, QString color) {
  QGraphicsTextItem *newText = scene->addText(text);
  newText->setPos(coordinate * GRID_SIZE);
  newText->setDefaultTextColor(color);
}
