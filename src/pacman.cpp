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

                                    void Pacman::Animate() {
                      a            setPixmap(pic[index]);
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
