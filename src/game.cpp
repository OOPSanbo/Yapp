#include "game.h"

#include "demoinputcomponent.h"
#include "pacman.h"
#include "pacmangraphicscomponent.h"
#include "pacmanphysicscomponent.h"

Game::Game(QGraphicsScene* scene) : scene(scene) {}

void Game::Init() {
  maze = new Maze();
  pacman = new Pacman(new DemoInputComponent(), new PacmanPhysicsComponent(),
                      new PacmanGraphicsComponent(*scene));
}

void Game::GameLoop() {
  QTimer* loopTimer = new QTimer(this);
  connect(loopTimer, SIGNAL(timeout()), this, SLOT(Update()));
  loopTimer->start(70);
}

void Game::Update() { pacman->Update(*maze); }
