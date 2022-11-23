#include "pacman.h"

#include <QList>
#include <QPixmap>
#include <QTimer>

Pacman::Pacman(QString name, InputComponent* input, PhysicsComponent* physics,
               GraphicsComponent* graphics)
    : DynamicGameObject(name, input, physics, graphics) {
  // TODO: Replace hardcoded positon & direction set
  x = 14 * 20 - 10;
  y = 23 * 20 - 10;
  direction = eDirection::RIGHT;
  nextDirection = eDirection::DOWN;
}

/*

                                  if (pos.x() == 26 * 20 && pos.y() == 14
   * 20 - 10) { pos = QPoint(20, 14 * 20 - 10); setPos(pos); } else if
   (pos.x() == 10 && pos.y() == 14 * 20
                                - 10) { pos = QPoint(26 * 20, 14 * 20 -
   10); setPos(pos);
*/
