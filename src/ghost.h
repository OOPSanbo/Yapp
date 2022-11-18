#ifndef GHOST_H
#define GHOST_H

#include <QList>
#include <QObject>
#include <QPixmap>
#include <QWidget>

#include "gameobject.h"

class Ghost : public GameObject {
  Q_OBJECT
public:
  Ghost(InputComponent* input, PhysicsComponent* physics,
        GraphicsComponent* graphics, QString ghostname);
};
#endif // GHOST_H
