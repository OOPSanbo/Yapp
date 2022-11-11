#ifndef GHOST_H
#define GHOST_H

#include <QList>
#include <QObject>
#include <QPixmap>
#include <QWidget>

#include "character.h"
#include "maze.h"

class Ghost : public Character {
  Q_OBJECT
private:
  int index;
  int add;
  QTimer *timer;

public:
  QList<QPixmap> pic;
  Ghost(QPoint pos, QPoint direction, QString ghostname);
  ~Ghost();

public slots:
  void Animate();
  void Move(Maze *maze);
};

#endif // GHOST_H
