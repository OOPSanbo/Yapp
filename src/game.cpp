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

Game::Game(QGraphicsScene* scene) : scene(scene) {}

void Game::Init() {
  maze = new Maze();
  pacman = new Pacman(new KeyInputComponent(), new PacmanPhysicsComponent(),
                      new PacmanGraphicsComponent(*scene));
  blinky = new Ghost(new GhostInputComponent(), new GhostPhysicsComponent(),
                     new GhostGraphicsComponent(*scene, "blinky"), "blinky");
  clyde = new Ghost(new GhostInputComponent(), new GhostPhysicsComponent(),
                    new GhostGraphicsComponent(*scene, "clyde"), "clyde");
  inky = new Ghost(new GhostInputComponent(), new GhostPhysicsComponent(),
                   new GhostGraphicsComponent(*scene, "inky"), "inky");
  pinky = new Ghost(new GhostInputComponent(), new GhostPhysicsComponent(),
                    new GhostGraphicsComponent(*scene, "pinky"), "pinky");
  scene->installEventFilter(pacman->input);
}

void Game::GameLoop() {
  QTimer* loopTimer = new QTimer(this);
  connect(loopTimer, SIGNAL(timeout()), this, SLOT(Update()));
  loopTimer->start(70);
  // loopTimer->setInterval(100);
}

void Game::Update() {
  pacman->Update(*maze);
  blinky->Update(*maze);
  clyde->Update(*maze);
  inky->Update(*maze);
  pinky->Update(*maze);
}
