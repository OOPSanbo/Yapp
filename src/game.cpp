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
  score = new Score(scene);

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
  blinky = new Ghost(QString("blinky"), new GhostInputComponent(),
                     new GhostPhysicsComponent(),
                     new GhostGraphicsComponent(*scene, "blinky"));
  clyde = new Ghost(QString("clyde"), new GhostInputComponent(),
                    new GhostPhysicsComponent(),
                    new GhostGraphicsComponent(*scene, "clyde"));
  inky = new Ghost(QString("inky"), new GhostInputComponent(),
                   new GhostPhysicsComponent(),
                   new GhostGraphicsComponent(*scene, "inky"));
  pinky = new Ghost(QString("pinky"), new GhostInputComponent(),
                    new GhostPhysicsComponent(),
                    new GhostGraphicsComponent(*scene, "pinky"));

  scene->installEventFilter(key);
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
  foreach (GameObject* item, items) { item->Update(*maze); }
}
