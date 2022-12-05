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
  soundengine = new SoundEngine();
  maze = new Maze();
  score = new Score(scene);
  dotnum = 0;
  lifeLabel = new QGraphicsPixmapItem();
  scene->addItem(lifeLabel);
  lifeDisplay();
  foreach (Point dotPos, maze->WhereAreDots()) {
    GameObject* dot = dotFactory->CreateObject("dot", dotPos);
    connect(dot, SIGNAL(Eaten()), score, SLOT(IncreaseDotScore()));
    connect(dot, SIGNAL(Eaten()), this, SLOT(DotCount()));
    connect(dot, SIGNAL(Eaten()), soundengine, SLOT(EatDotsSound()));
    dotnum += 1;
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

  connect(blinky, SIGNAL(Eaten()), soundengine, SLOT(EatGhostSound()));
  connect(pinky, SIGNAL(Eaten()), soundengine, SLOT(EatGhostSound()));
  connect(inky, SIGNAL(Eaten()), soundengine, SLOT(EatGhostSound()));
  connect(clyde, SIGNAL(Eaten()), soundengine, SLOT(EatGhostSound()));
  connect(blinky, SIGNAL(Eaten()), score, SLOT(IncreaseGhostScore()));
  connect(pinky, SIGNAL(Eaten()), score, SLOT(IncreaseGhostScore()));
  connect(inky, SIGNAL(Eaten()), score, SLOT(IncreaseGhostScore()));
  connect(clyde, SIGNAL(Eaten()), score, SLOT(IncreaseGhostScore()));

  connect(pacman, SIGNAL(Eaten()), this, SLOT(lifeDecrease()));
  Pacman& pacmanObject = static_cast<Pacman&>(*pacman);
  connect(&pacmanObject, SIGNAL(pacmanRevive()), this, SLOT(resume()));

  foreach (QPoint dotPos, maze->WhereArePellets()) {
    GameObject* pellet = dotFactory->CreateObject("pellet", dotPos);
    dotnum += 1;
    connect(pellet, SIGNAL(Eaten()), pacman, SLOT(Energize()));
    connect(pellet, SIGNAL(Eaten()), soundengine, SLOT(EatDotsSound()));
    connect(pellet, SIGNAL(Eaten()), this, SLOT(DotCount()));
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
  static_cast<Pacman&>(*pacman).lifeStatus = false;
  soundengine->DeathSound();
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
  blinkyGhost->SetPos(Point(260, 210));
  blinkyGhost->starttimer = 1;
  clydeGhost->SetPos(Point(300, 270));
  clydeGhost->starttimer = 100;
  inkyGhost->SetPos(Point(220, 270));
  inkyGhost->starttimer = 50;
  pinkyGhost->SetPos(Point(260, 270));
  pinkyGhost->starttimer = 10;
  blinkyGhost->SetBehavior(GoOutGate);
  blinkyGhost->SetDirection(Direction::RIGHT);
  clydeGhost->SetBehavior(GoOutGate);
  clydeGhost->SetDirection(Direction::LEFT);
  inkyGhost->SetBehavior(GoOutGate);
  inkyGhost->SetDirection(Direction::RIGHT);
  pinkyGhost->SetBehavior(GoOutGate);
  pinkyGhost->SetDirection(Direction::RIGHT);
}

void Game::DotCount() {
  dotnum -= 1;
  if (dotnum == 0) GameClear();
}

void Game::gameEnd() {
  score->SaveHighscore();
  blinky->Delete();
  clyde->Delete();
  pinky->Delete();
  inky->Delete();
  pacman->Delete();
  score->Delete();
  foreach (GameObject* item, items) { item->Delete(); }
  disconnect(updateTimer);
  gameOver = scene->addText("Game Over");
  gameOver->setPos(QPoint(10, 17) * 20);
  gameOver->setDefaultTextColor("red");
  soundengine->EndSound();
  scene->installEventFilter(this);
}

void Game::GameClear() {
  score->SaveHighscore();
  blinky->Delete();
  clyde->Delete();
  pinky->Delete();
  inky->Delete();
  pacman->Delete();
  score->Delete();
  foreach (GameObject* item, items) { item->Delete(); }
  disconnect(updateTimer);
  gameOver = scene->addText("Game Clear!");
  gameOver->setPos(QPoint(10, 17) * 20);
  gameOver->setDefaultTextColor("yellow");
  soundengine->EndSound();
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
    life = 3;
    Init();
    GameLoop();
  }
  return false;
}
