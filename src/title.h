#ifndef TITLE_H
#define TITLE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QObject>

class Title : public QObject {
  Q_OBJECT
 public:
  Title(QGraphicsScene *scene);
  bool eventFilter(QObject *object, QEvent *event);
  QGraphicsScene *scene;

 signals:
  void OnKeyPress_test();

 private:
  QGraphicsPixmapItem titleshape;
};

#endif  // TITLE_H
