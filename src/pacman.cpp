#include "pacman.h"

#include <QList>
#include <QPixmap>
#include <QTimer>

Pacman::Pacman(InputComponent* input, PhysicsComponent* physics,
               GraphicsComponent* graphics)
    : GameObject(input, physics, graphics) {
  x = 20 * 13;
  y = 20 * 22.5;
  dir = eDirection::RIGHT;
  nextDir = eDirection::DOWN;
}
/*

                                    void Pacman::Animate() {
                                  setPixmap(pic[index]);
                                  index += add;
                                  if (index >= 2 || index <= 0) add =
   -add;
                                }

                                void Pacman::Move(Maze *maze) {
                                  grabKeyboard();
                                  if (!(maze->CanMove(pos + QPoint(10,
   10), direction))) { direction = QPoint(0, 0);
                                  }
                                  pos += direction;
                                  setPos(pos);
                                  if (pos.x() == 26 * 20 && pos.y() == 14
   * 20 - 10) { pos = QPoint(20, 14 * 20 - 10); setPos(pos); } else if
   (pos.x() == 10 && pos.y() == 14 * 20
                                - 10) { pos = QPoint(26 * 20, 14 * 20 -
   10); setPos(pos);
                                  }
                                }

                                void Pacman::keyPressEvent(QKeyEvent *e) {
                                  switch (e->key()) {
                                    case Qt::Key_W:
                                      direction = (Direction::Up);
                                      setRotation(270);
                                      break;
                                    case Qt::Key_A:
                                      direction = (Direction::Left);
                                      setRotation(180);
                                      break;
                                    case Qt::Key_S:
                                      direction = (Direction::Down);
                                      setRotation(90);
                                      break;
                                    case Qt::Key_D:
                                      direction = (Direction::Right);
                                      setRotation(0);
                                      break;
                                  }
                                }

                                Pacman::~Pacman() { delete timer; }
                                */
;
