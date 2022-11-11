#ifndef PELLET_H
#define PELLET_H

#include "item.h"
#include <QPixmap>

class Pellet : public Item {

signals:
  // void PelletEaten();

public:
  QPixmap shape;
  Pellet(QPoint pos);
  virtual void Eaten();
};

#endif // PELLET_H
