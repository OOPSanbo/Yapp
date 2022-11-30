#include "game.h"

#include "demoinputcomponent.h"
#include "dot.h"
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
  life = 3;
  lifeLabel = new QGraphicsPixmapItem();
  scene->addItem(lifeLabel);
  lifeDisplay();
  foreach (Point dotPos, maze->WhereAreDots()) {
    GameObject* dot = dotFactory->CreateObject("dot", dotPos);
    connect(dot, SIGNAL(Eaten()), score, SLOT(IncreaseDotScore()));
    items.append(dot);
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

  connect(pacman, SIGNAL(Eaten()), this, SLOT(lifeDecrease()));
  Pacman& pacmanObject = static_cast<Pacman&>(*pacman);
  connect(&pacmanObject, SIGNAL(pacmanRevive()), this, SLOT(resume()));

  foreach (QPoint dotPos, maze->WhereArePellets()) {
    GameObject* pellet = dotFactory->CreateObject("pellet", dotPos);
    connect(pellet, SIGNAL(Eaten()), score, SLOT(IncreasePelletScore()));
    connect(pellet, SIGNAL(Eaten()), blinky, SLOT(PelletEaten()));
    connect(pellet, SIGNAL(Eaten()), pinky, SLOT(PelletEaten()));
    connect(pellet, SIGNAL(Eaten()), inky, SLOT(PelletEaten()));
    connect(pellet, SIGNAL(Eaten()), clyde, SLOT(PelletEaten()));
    items.append(pellet);
  }

  scene->installEventFilter(key);
}

void Game::GameLoop() {
  QTimer* loopTimer = new QTimer(this);
  updateTimer = connect(loopTimer, SIGNAL(timeout()), this, SLOT(Update()));
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

void Game::lifeDisplay() {
  lifeLabel->setPixmap(QPixmap(QString(":/res/img/lives_") +
                               QString::number(life) + QString(".png"))
                           .scaledToHeight(40));
  lifeLabel->setPos(0, 31 * 20);
}
void Game::lifeDecrease() {
  Ghost* blinkyGhost = &static_cast<Ghost&>(*blinky);
  Ghost* clydeGhost = &static_cast<Ghost&>(*clyde);
  Ghost* inkyGhost = &static_cast<Ghost&>(*inky);
  Ghost* pinkyGhost = &static_cast<Ghost&>(*pinky);
  QList<Ghost*> ghosts;
  ghosts << blinkyGhost << clydeGhost << inkyGhost << pinkyGhost;
  foreach (Ghost* g, ghosts) {
    if (g->GetBehavior() != Frightened && g->GetBehavior() != Eaten) {
      static_cast<Pacman&>(*pacman).lifeStatus = false;
      foreach (Ghost* gho, ghosts) { gho->SetBehavior(Stop); }
    }
  }
}
void Game::resume() {
  life -= 1;
  lifeDisplay();
  if (life == 0) {
    gameEnd();
    return;
  }

  Ghost* blinkyGhost = &static_cast<Ghost&>(*blinky);
  Ghost* clydeGhost = &static_cast<Ghost&>(*clyde);
  Ghost* inkyGhost = &static_cast<Ghost&>(*inky);
  Ghost* pinkyGhost = &static_cast<Ghost&>(*pinky);
  blinkyGhost->SetPos(QPoint(20 * 4.5, 20 * 4.5));
  clydeGhost->SetPos(QPoint(20 * 24.5, 20 * 4.5));
  inkyGhost->SetPos(QPoint(20 * 4.5, 20 * 24.5));
  pinkyGhost->SetPos(QPoint(20 * 24.5, 20 * 24.5));
  blinkyGhost->SetBehavior(Chase);
  clydeGhost->SetBehavior(Chase);
  inkyGhost->SetBehavior(Chase);
  pinkyGhost->SetBehavior(Chase);
}
void Game::gameEnd() {
  blinky->Delete();
  clyde->Delete();
  pinky->Delete();
  inky->Delete();
  pacman->Delete();
  score->Delete();
  disconnect(updateTimer);
  gameOver = scene->addText("Game Over");
  gameOver->setPos(QPoint(10, 17) * 20);
  gameOver->setDefaultTextColor("red");
  scene->installEventFilter(this);
}

bool Game::eventFilter(QObject* object, QEvent* event) {
  if (event->type() == QEvent::KeyPress) {
    scene->removeItem(gameOver);
    delete pacman;
    delete pinky;
    delete inky;
    delete blinky;
    delete clyde;
    scene->removeEventFilter(this);
    Init();
    GameLoop();
  }
  return false;
}
