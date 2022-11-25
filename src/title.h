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
  void printGenerator();
  QGraphicsScene *scene;
  QTimer *timer;
  void printer(QPixmap image, QString character, QString nickname,
               QPoint point);
  void dotPrinter();
  void printCredit();
  void delay(int ms);
 signals:
  void OnKeyPress();

 private:
  QGraphicsPixmapItem titleshape;
};

#endif  // TITLE_H
