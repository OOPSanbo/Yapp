#include "ghostfactory.h"

#include "ghost.h"
#include "ghostgraphicscomponent.h"
#include "ghostinputcomponent.h"
#include "ghostphysicscomponent.h"

GhostFactory::GhostFactory(QGraphicsScene* scene) : scene(scene) {}

GameObject* GhostFactory::CreateObject(QString name, Point pos) {
  Ghost* ghost = new Ghost(name, pos * 20);

  ChaseBehavior* chaseBehavior;
  int timeLimit;
  if (name == "blinky") {
    chaseBehavior = new AggressiveChaseBehavior();
    timeLimit = 1;
  }
  if (name == "pinky") {
    chaseBehavior = new AmbushChaseBehavior();
    timeLimit = 10;
  }
  if (name == "inky") {
    chaseBehavior = new PatrollChaseBehavior();
    timeLimit = 50;
  }
  if (name == "clyde") {
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
