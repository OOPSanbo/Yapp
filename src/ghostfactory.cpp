#include "ghostfactory.h"

#include "ghost.h"
#include "ghostgraphicscomponent.h"
#include "ghostinputcomponent.h"
#include "ghostphysicscomponent.h"

GhostFactory::GhostFactory(QGraphicsScene* scene) : scene(scene) {}

GameObject* GhostFactory::CreateObject(QString name, QPointF cord) {
  Ghost* ghost;
  ChaseBehavior* chaseBehavior;
  int timeLimit;

  if (name == "blinky") {
    ghost = new Ghost(name, Point(cord * guiGridSize), Direction::RIGHT);
    chaseBehavior = new AggressiveChaseBehavior();
    timeLimit = 1;
  } else if (name == "pinky") {
    ghost = new Ghost(name, Point(cord * guiGridSize), Direction::RIGHT);
    chaseBehavior = new AmbushChaseBehavior();
    timeLimit = 10;
  } else if (name == "inky") {
    ghost = new Ghost(name, Point(cord * guiGridSize), Direction::RIGHT);
    chaseBehavior = new PatrollChaseBehavior();
    timeLimit = 50;
  } else {  // clyde
    ghost = new Ghost(name, Point(cord * guiGridSize), Direction::LEFT);
    chaseBehavior = new RandomChaseBehavior();
    timeLimit = 100;
  }

  GhostInputComponent* input = new GhostInputComponent(chaseBehavior);
  GhostPhysicsComponent* physics = new GhostPhysicsComponent();
  GhostGraphicsComponent* graphics = new GhostGraphicsComponent(*scene, name);

  ghost->AddInputComponent(input);
  ghost->AddPhysicsComponent(physics);
  ghost->AddGraphicsComponent(graphics);
  ghost->SetStartTimer(timeLimit);

  return ghost;
}
