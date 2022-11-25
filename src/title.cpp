#include "title.h"

#include <QTimer>
Title::Title(QGraphicsScene *scene) : scene(scene) {
  QPixmap titleLogo = QPixmap(":/res/img/title.png").scaled(366, 89);
  titleshape.setPixmap(titleLogo);
  titleshape.setPos(97, -60);
  scene->addItem(&titleshape);
  QGraphicsTextItem *header = scene->addText("CHARACTER / NICKNAME");
  header->setDefaultTextColor("white");
  header->setPos(QPoint(115, 30));
  index = 0;
  characters << "SHADOM"
             << "SPEEDY"
             << "BASHFUL"
             << "POKEY";
  nicknames << "BLINKY"
            << "PINKY"
            << "INKY"
            << "CLYDE";
  int Height = 100;
  for (int index = 0; index < 4; index++) {
    images.append(QPixmap(QString(":/res/img/ghost/") +
                          nicknames[index].toLower() + QString("/4.png"))
                      .scaledToHeight(40));

    points.append(QPoint(30, Height));
    Height = Height + 60;
  }
  timer = new QTimer();
  connectSignal =
      connect(timer, SIGNAL(timeout()), this, SLOT(printGenerator()));
  timer->start(1000);
}

bool Title::eventFilter(QObject *object, QEvent *event) {
  if (event->type() == QEvent::KeyPress) {
    scene->removeItem(&titleshape);
    OnKeyPress();
  }
  return false;
}
void Title::printGenerator() {
  qDebug() << index;
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

void Title::printer(QPixmap image, QString character, QString nickname,
                    QPoint point) {
  QGraphicsPixmapItem *characterImage = new QGraphicsPixmapItem();
  characterImage->setPixmap(image);
  characterImage->setPos(point);
  scene->addItem(characterImage);

  QGraphicsTextItem *charecterText = scene->addText(QString('-') + character);
  charecterText->setPos(point + QPoint(90, 0));

  QGraphicsTextItem *nicknameText =
      scene->addText(QString('"') + nickname + QString('"'));
  nicknameText->setPos(point + QPoint(290, 0));

  if (character == QString("SHADOM")) {
    charecterText->setDefaultTextColor("red");

    nicknameText->setDefaultTextColor("red");
  } else if (character == QString("SPEEDY")) {
    charecterText->setDefaultTextColor("pink");

    nicknameText->setDefaultTextColor("pink");
  } else if (character == QString("BASHFUL")) {
    charecterText->setDefaultTextColor("skyblue");

    nicknameText->setDefaultTextColor("skyblue");
  } else if (character == QString("POKEY")) {
    charecterText->setDefaultTextColor("orange");

    nicknameText->setDefaultTextColor("orange");
  } else {
    charecterText->setDefaultTextColor("white");

    nicknameText->setDefaultTextColor("white");
  }
}
void Title::dotPrinter() {
  QGraphicsPixmapItem *dot = new QGraphicsPixmapItem();
  QGraphicsPixmapItem *pellet = new QGraphicsPixmapItem();
  dot->setPixmap(QPixmap(":/res/img/item/dot.png"));
  dot->setPos(225, 500);
  scene->addItem(dot);
  QGraphicsTextItem *dotText = scene->addText("10 pts");
  dotText->setPos(240, 490);
  dotText->setDefaultTextColor("white");

  pellet->setPixmap(QPixmap(":/res/img/item/pellet.png"));
  pellet->setPos(225, 520);
  scene->addItem(pellet);

  QGraphicsTextItem *pelletText = scene->addText("50 pts");
  pelletText->setPos(243, 510);
  pelletText->setDefaultTextColor("white");
}
void Title::printCredit() {
  QGraphicsTextItem *sanbo =
      scene->addText("㉿Industrial Security OOP Pac-Man");
  sanbo->setDefaultTextColor("white");
  sanbo->setPos(20, 580);
}
