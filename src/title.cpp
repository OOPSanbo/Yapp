#include "title.h"

#include <QThread>
Title::Title(QGraphicsScene *scene) : scene(scene) {
  QPixmap titleLogo = QPixmap(":/res/img/title.png").scaled(366, 89);
  titleshape.setPixmap(titleLogo);
  titleshape.setPos(97, -60);
  scene->addItem(&titleshape);
  printGenerator();
}

bool Title::eventFilter(QObject *object, QEvent *event) {
  if (event->type() == QEvent::KeyPress) {
    scene->removeItem(&titleshape);
    OnKeyPress();
  }
  return false;
}
void Title::printGenerator() {
  QGraphicsTextItem *header = scene->addText("CHARACTER / NICKNAME");
  header->setDefaultTextColor("white");
  header->setPos(QPoint(115, 30));
  delay();
  QStringList characters;
  QStringList nicknames;
  QList<QPoint> points;
  QList<QPixmap> images;
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
  for (int index = 0; index < characters.length(); index++) {
    printer(images[index], characters[index], nicknames[index], points[index]);
  }
}

void Title::printer(QPixmap image, QString character, QString nickname,
                    QPoint point) {
  QGraphicsPixmapItem *characterImage = new QGraphicsPixmapItem();
  characterImage->setPixmap(image);
  characterImage->setPos(point);
  scene->addItem(characterImage);
  delay();
  QGraphicsTextItem *charecterText = scene->addText(QString('-') + character);
  charecterText->setPos(point + QPoint(90, 0));

  QGraphicsTextItem *nicknameText =
      scene->addText(QString('"') + nickname + QString('"'));
  nicknameText->setPos(point + QPoint(290, 0));

  if (character == QString("SHADOM")) {
    charecterText->setDefaultTextColor("red");
    delay();
    nicknameText->setDefaultTextColor("red");
  } else if (character == QString("SPEEDY")) {
    charecterText->setDefaultTextColor("pink");
    delay();
    nicknameText->setDefaultTextColor("pink");
  } else if (character == QString("BASHFUL")) {
    charecterText->setDefaultTextColor("skyblue");
    delay();
    nicknameText->setDefaultTextColor("skyblue");
  } else if (character == QString("POKEY")) {
    charecterText->setDefaultTextColor("orange");
    delay();
    nicknameText->setDefaultTextColor("orange");
  } else {
    charecterText->setDefaultTextColor("white");
    delay();
    nicknameText->setDefaultTextColor("white");
  }
  delay();
}
void Title::delay() {
  QTime dieTime = QTime::currentTime().addSecs(1);
  while (QTime::currentTime() < dieTime)
    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
