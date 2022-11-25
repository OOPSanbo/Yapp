#include "game.h"

#include "demoinputcomponent.h"
#include "ghost.h"
#include "ghostgraphicscomponent.h"
#include "ghostinputcomponent.h"
#include "ghostphysicscomponent.h"
#include "keyinputcomponent.h"
#include "pacman.h"
#include "pacmangraphicscomponent.h"
#include "pacmanphysicscomponent.h"

Game::Game(QGraphicsScene* scene) : scene(scene) {
  dotFactory = new DotFactory(scene);
}

void Game::Init() {
  maze = new Maze();

  foreach (QPoint dotPos, maze->WhereAreDots()) {
    GameObject* dot = dotFactory->CreateObject("dot", dotPos);
    items.append(dot);
  }

  foreach (QPoint dotPos, maze->WhereArePellets()) {
    GameObject* pellet = dotFactory->CreateObject("pellet", dotPos);
    items.append(pellet);
  }

  KeyInputComponent* key = new KeyInputComponent();
  pacman = new Pacman(QString("Pacman"), key, new PacmanPhysicsComponent(),
                      new PacmanGraphicsComponent(*scene));
  blinky = new Ghost(QString("blinky"),
                     new GhostInputComponent(new AggressiveChaseBehavior()),
                     new GhostPhysicsComponent(),
                     new GhostGraphicsComponent(*scene, "blinky"));
  pinky = new Ghost(
      QString("pinky"), new GhostInputComponent(new AmbushChaseBehavior()),
      new GhostPhysicsComponent(), new GhostGraphicsComponent(*scene, "pinky"));
  inky = new Ghost(
      QString("inky"), new GhostInputComponent(new PatrollChaseBehavior()),
      new GhostPhysicsComponent(), new GhostGraphicsComponent(*scene, "inky"));

  clyde = new Ghost(
      QString("clyde"), new GhostInputComponent(new RandomChaseBehavior()),
      new GhostPhysicsComponent(), new GhostGraphicsComponent(*scene, "clyde"));

  scene->installEventFilter(key);
}

void Game::GameLoop() {
  QTimer* loopTimer = new QTimer(this);
  connect(loopTimer, SIGNAL(timeout()), this, SLOT(Update()));
  loopTimer->start(70);
  // loopTimer->setInterval(20);
}

void Game::Update() {
  pacman->Update(*maze);
  blinky->Update(*maze);
  clyde->Update(*maze);
  inky->Update(*maze);
  pinky->Update(*maze);
  foreach (GameObject* item, items) { item->Update(*maze); }
}
