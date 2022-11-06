#ifndef ITEM_H
#define ITEM_H

#include <QGraphicsPixmapItem>>
#include <QObject>
#include <QPoint>

class Item : public QObject, public QGraphicsPixmapItem {
  Q_OBJECT
protected:
  QPixmap *pic;
  QPoint pos;

public:
  Item(QPoint pos);
  QPoint getPos();
};

#endif // ITEM_H
