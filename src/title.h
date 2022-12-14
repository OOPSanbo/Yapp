#ifndef TITLE_H
#define TITLE_H
#include <QCoreApplication>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QObject>
#include <QTime>
class Title : public QObject {
  Q_OBJECT
 public:
  Title(QGraphicsScene *scene);
  bool eventFilter(QObject *object, QEvent *event);
  void printer(QString image, QString character, QString nickname,
               QPointF point);
  const QString IMAGE_GHOST_SRC = ":/res/img/ghost/";
  const QString IMAGE_ITEM_SRC = ":/res/img/item/";
  const int GRID_SIZE = 20;
  const int MARGIN = 3;
  const int GHOST_SIZE = 40;

  QGraphicsScene *scene;
  QTimer *timer;
  QMetaObject::Connection connectSignal;

  void dotPrinter();
  void printCredit();
  void makeImage(QString imageSrc, QPointF coordinate, int size);
  void makeText(QString text, QPointF coordinate, QString color = "white");

 signals:
  void OnKeyPress();
  void timeout();
 private slots:
  void printGenerator();

 private:
  QGraphicsPixmapItem titleshape;
  QStringList characters;
  QStringList nicknames;
  QList<QPointF> points;
  QStringList images;
  int index;
};

#endif  // TITLE_H
