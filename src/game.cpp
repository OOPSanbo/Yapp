#include "game.h"

#include "demoinputcomponent.h"
#include "ghost.h"
#include "ghostgraphicscomponent.h"
#include "ghostphysicscomponent.h"
#include "keyinputcomponent.h"
#include "pacman.h"
#include "pacmangraphicscomponent.h"
#include "pacmanphysicscomponent.h"

Game::Game(QGraphicsScene* scene) : scene(scene) {}

void Game::Init() {
  maze = new Maze();

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
  ((DynamicGameObject*)pacman)->Update(*maze);
  ((DynamicGameObject*)blinky)->Update(*maze);
}
