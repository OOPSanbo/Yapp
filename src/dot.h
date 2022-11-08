#ifndef DOT_H
#define DOT_H

#include "item.h"

class Dot : public Item {

signals:
  // void DotEaten();

public:
  Dot(QPoint pos);
  virtual void Eaten();
};

#endif // DOT_H
