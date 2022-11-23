#include "game.h"

#include "demoinputcomponent.h"
#include "dotgraphicscomponent.h"
#include "dotphysicscomponent.h"
#include "ghost.h"
#include "ghostgraphicscomponent.h"
#include "ghostinputcomponent.h"
#include "ghostphysicscomponent.h"
#include "keyinputcomponent.h"
#include "pacman.h"
#include "pacmangraphicscomponent.h"
#include "pacmanphysicscomponent.h"

Game::Game(QGraphicsScene* scene) : scene(scene) {
  // dotFactory = new DotFactory(new DotPhysicsComponent(),
  //                             new DotGraphicsComponent("dot", *scene));
}

void Game::Init() {
  maze = new Maze();

  foreach (QPoint dotPos, maze->WhereAreDots()) {
    // dotfactory는 qpixmapitem을 받아서 등록해주는 역할을 해야 함
    // 따라서 shapes는 object에서 들고 있어야 함
    DotFactory* lDotFactory = new DotFactory(
        new DotPhysicsComponent(), new DotGraphicsComponent("dot", *scene));

    GameObject* dot = lDotFactory->CreateObject("dot", dotPos);
    dot->Update(*maze);
    items.append(dot);
  }

  KeyInputComponent* key = new KeyInputComponent();
  pacman = new Pacman(QString("Pacman"), key, new PacmanPhysicsComponent(),
                      new PacmanGraphicsComponent(*scene));
  /*
    blinky = new Ghost(new GhostInputComponent(), new GhostPhysicsComponent(),
                       new GhostGraphicsComponent(*scene, "blinky"), "blinky");
    clyde = new Ghost(new GhostInputComponent(), new GhostPhysicsComponent(),
                      new GhostGraphicsComponent(*scene, "clyde"), "clyde");
    inky = new Ghost(new GhostInputComponent(), new GhostPhysicsComponent(),
                     new GhostGraphicsComponent(*scene, "inky"), "inky");
    pinky = new Ghost(new GhostInputComponent(), new GhostPhysicsComponent(),
                      new GhostGraphicsComponent(*scene, "pinky"), "pinky");
    scene->installEventFilter(pacman->input);
  */
  blinky = new Ghost(QString("blinky"), new DemoInputComponent(),
                     new GhostPhysicsComponent(),
                     new GhostGraphicsComponent(*scene, "blinky"));

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
  // clyde->Update(*maze);
  // inky->Update(*maze);
  // pinky->Update(*maze);
}
