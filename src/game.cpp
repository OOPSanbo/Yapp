#include "game.h"

#include <QDebug>

#include "ghost.h"
#include "ghostfactory.h"
#include "itemfactory.h"
#include "pacman.h"
#include "pacmanfactory.h"
Game::Game(QGraphicsScene* scene) : scene(scene) {}

void Game::Init() {
  soundengine = new SoundEngine();
  maze = new Maze();
  score = new Score(scene);
  dotnum = 0;
  qDebug() << dotnum;
  lifeLabel = new QGraphicsPixmapItem();
  scene->addItem(lifeLabel);
  lifeDisplay();

  ItemFactory itemFactory(scene);
  foreach (Point dotCord, maze->WhereAreDots()) {
    GameObject* dot = itemFactory.CreateObject("dot", dotCord);
    connect(dot, SIGNAL(Eaten()), score, SLOT(IncreaseDotScore()));
    connect(dot, SIGNAL(Eaten()), this, SLOT(DotCount()));
    connect(dot, SIGNAL(Eaten()), soundengine, SLOT(EatDotsSound()));
    dotnum += 1;
    items.append(dot);
  }

  PacmanFactory pacmanFactory(scene);
  pacman = pacmanFactory.CreateObject("pacman", QPointF(13, 16.5));

  GhostFactory ghostFactory(scene);
  blinky = ghostFactory.CreateObject("blinky", QPointF(13, 10.5));
  pinky = ghostFactory.CreateObject("pinky", QPointF(13, 13.5));
  inky = ghostFactory.CreateObject("inky", QPointF(11, 13.5));
  clyde = ghostFactory.CreateObject("clyde", QPointF(15, 13.5));

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

  foreach (QPoint pelletCord, maze->WhereArePellets()) {
    GameObject* pellet = itemFactory.CreateObject("pellet", pelletCord);
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
}

void Game::GameLoop() {
  QTimer* loopTimer = new QTimer(this);
  updateTimer = connect(loopTimer, SIGNAL(timeout()), this, SLOT(Update()));
  loopTimer->start(70);
}

void Game::Update() {
  pacman->Update(*maze);
  blinky->Update(*maze);
  pinky->Update(*maze);
  inky->Update(*maze);
  clyde->Update(*maze);
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
  Ghost* pinkyGhost = &static_cast<Ghost&>(*pinky);
  Ghost* inkyGhost = &static_cast<Ghost&>(*inky);
  Ghost* clydeGhost = &static_cast<Ghost&>(*clyde);

  blinkyGhost->SetPos(Point(260, 210));
  blinkyGhost->starttimer = 1;
  pinkyGhost->SetPos(Point(260, 270));
  pinkyGhost->starttimer = 10;
  inkyGhost->SetPos(Point(220, 270));
  inkyGhost->starttimer = 50;
  clydeGhost->SetPos(Point(300, 270));
  clydeGhost->starttimer = 100;

  blinkyGhost->SetBehavior(GoOutGate);
  blinkyGhost->SetDirection(Direction::RIGHT);
  pinkyGhost->SetBehavior(GoOutGate);
  pinkyGhost->SetDirection(Direction::RIGHT);
  inkyGhost->SetBehavior(GoOutGate);
  inkyGhost->SetDirection(Direction::RIGHT);
  clydeGhost->SetBehavior(GoOutGate);
  clydeGhost->SetDirection(Direction::LEFT);
}

void Game::DotCount() {
  dotnum -= 1;
  if (dotnum == 0) GameClear();
}

void Game::gameEnd() {
  score->SaveHighscore();
  blinky->Delete();
  pinky->Delete();
  inky->Delete();
  clyde->Delete();
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
  pinky->Delete();
  inky->Delete();
  clyde->Delete();
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
    delete blinky;
    delete pinky;
    delete inky;
    delete clyde;
    qDeleteAll(items);
    items.clear();
    scene->removeEventFilter(this);
    life = 3;
    Init();
    GameLoop();
  }
  return false;
}
