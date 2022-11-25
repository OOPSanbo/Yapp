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
  void printer(QPixmap image, QString character, QString nickname,
               QPoint point);

  QGraphicsScene *scene;
  QTimer *timer;
  QMetaObject::Connection connectSignal;

  void dotPrinter();
  void printCredit();
 signals:
  void OnKeyPress();
  void timeout();
 private slots:
  void printGenerator();

 private:
  QGraphicsPixmapItem titleshape;
  QStringList characters;
  QStringList nicknames;
  QList<QPoint> points;
  QList<QPixmap> images;
  int index;
};

#endif  // TITLE_H
