#include "game.h"

#include "demoinputcomponent.h"
#include "ghost.h"
#include "ghostgraphicscomponent.h"
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
    dot->Update(*maze);
    items.append(dot);
  }

  foreach (QPoint dotPos, maze->WhereArePellets()) {
    GameObject* pellet = dotFactory->CreateObject("pellet", dotPos);
    pellet->Update(*maze);
    items.append(pellet);
  }

  KeyInputComponent* key = new KeyInputComponent();
  pacman = new Pacman(QString("Pacman"), key, new PacmanPhysicsComponent(),
                      new PacmanGraphicsComponent(*scene));
  blinky = new Ghost(QString("blinky"), new DemoInputComponent(),
                     new GhostPhysicsComponent(),
                     new GhostGraphicsComponent(*scene, "blinky"));

  scene->installEventFilter(key);
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
