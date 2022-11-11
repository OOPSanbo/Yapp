#ifndef DOT_H
#define DOT_H

#include "item.h"
#include <QPixmap>

class Dot : public Item {

signals:
  // void DotEaten();

public:
  QPixmap shape;
  Dot(QPoint pos);
  virtual void Eaten();
};

#endif // DOT_H
