#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QPoint>

class Item : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
protected:

  QPoint pos;

public:
  Item(QPoint pos);
  QPoint getPos();
  virtual void Eaten() = 0;
};

#endif // ITEM_H
