#include "game.h"

#include "demoinputcomponent.h"
#include "keyinputcomponent.h"
#include "pacman.h"
#include "ghost.h"
#include "pacmangraphicscomponent.h"
#include "pacmanphysicscomponent.h"
#include "ghostgraphicscomponent.h"
#include "ghostphysicscomponent.h"

Game::Game(QGraphicsScene* scene) : scene(scene) {}

void Game::Init() {
  maze = new Maze();
  pacman = new Pacman(new KeyInputComponent(), new PacmanPhysicsComponent(),
                      new PacmanGraphicsComponent(*scene));
  blinky = new Ghost(new DemoInputComponent(), new GhostPhysicsComponent(),
                     new GhostGraphicsComponent(*scene, "blinky"),"blinky");
  scene->installEventFilter(pacman->input);
}

void Game::GameLoop() {
  QTimer* loopTimer = new QTimer(this);
  connect(loopTimer, SIGNAL(timeout()), this, SLOT(Update()));
  loopTimer->start(70);
}

void Game::Update() {
    pacman->Update(*maze);
    blinky->Update(*maze);
}
