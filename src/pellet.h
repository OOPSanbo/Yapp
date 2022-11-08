#ifndef PELLET_H
#define PELLET_H

#include "item.h"

class Pellet : public Item {

signals:
  // void PelletEaten();

public:
  Pellet(QPoint pos);
  virtual void Eaten();
};

#endif // PELLET_H
