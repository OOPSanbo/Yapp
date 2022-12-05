#include "pacmanfactory.h"

#include "direction.h"
#include "keyinputcomponent.h"
#include "pacman.h"
#include "pacmangraphicscomponent.h"
#include "pacmanphysicscomponent.h"

PacmanFactory::PacmanFactory(QGraphicsScene* scene) : scene(scene) {}

GameObject* PacmanFactory::CreateObject(QString name, QPointF cord) {
  Pacman* pacman =
      new Pacman(name, Point(cord * guiGridSize), Direction::RIGHT);

  KeyInputComponent* input = new KeyInputComponent();
  scene->installEventFilter(input);
  PacmanPhysicsComponent* physics = new PacmanPhysicsComponent();
  PacmanGraphicsComponent* graphics = new PacmanGraphicsComponent(*scene);

  pacman->AddInputComponent(input);
  pacman->AddPhysicsComponent(physics);
  pacman->AddGraphicsComponent(graphics);

  return pacman;
}
