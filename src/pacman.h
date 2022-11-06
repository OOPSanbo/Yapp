#ifndef PACMAN_H
#define PACMAN_H

#include <QList>
#include <QObject>
#include <QPixmap>
#include <QWidget>

#include "character.h"

class Pacman : public Character {
  Q_OBJECT
private:
  int index;
  int add;
  QTimer *timer;

public:
  QList<QPixmap> pic;
  Pacman();
  ~Pacman();

public slots:
  void SwitchAnimate();
};
#endif // PACMAN_H
