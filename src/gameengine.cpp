#include "gameengine.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>

#include "dot.h"
#include "ghost.h"
#include "pacman.h"
#include "pellet.h"

GameEngine::GameEngine() {
  graphicEngine = new GraphicEngine();
  // dotModel = DotModel();
  // pelletModel = PelletModel();
}

void GameEngine::StartGame() {
  InitMaze();
  InitItem();
  InitCharacter();
}

void GameEngine::EndGame() {
  delete pacman;
  delete blinky;
  delete clyde;
  delete inky;
  delete pinky;
}

GameEngine::~GameEngine() { delete graphicEngine; }

void GameEngine::InitMaze() { maze = new Maze(); }

void GameEngine::InitItem() {
  QList<QPoint> dotPoints = maze->WhereAreDots();
  QList<QPoint> pelletPoints = maze->WhereArePellets();

  QPoint point;
  Item *pItem;
  foreach (point, dotPoints) {
    pItem = new Dot(point * graphicEngine->GetGridSize() + QPoint(0, 0));
    graphicEngine->LoadItemUI(pItem);
    items.append(pItem);
  }

  foreach (point, pelletPoints) {
    pItem = new Pellet(point * graphicEngine->GetGridSize() + QPoint(0, 0));
    graphicEngine->LoadItemUI(pItem);
    items.append(pItem);
  }
}

void GameEngine::InitCharacter() {
  srand(time(0));

  QPoint pacmanPoint = QPoint(20 * graphicEngine->GetGridSize() - 10,
                              14 * graphicEngine->GetGridSize() - 10);
  pacman = new Pacman(pacmanPoint, Direction::Right);
  graphicEngine->LoadCharacterUI(pacman);
  pacmanMoveTimer = new QTimer(this);
  connect(pacmanMoveTimer, SIGNAL(timeout()), this, SLOT(PacManHandler()));
  pacmanMoveTimer->start(10);

  ghostMoveTimer = new QTimer(this);
  QPoint blinkyPoint = QPoint(14 * graphicEngine->GetGridSize() - 10,
                              11 * graphicEngine->GetGridSize() - 10);
  blinky = new Ghost(blinkyPoint, Direction::Left, "blinky");
  graphicEngine->LoadCharacterUI(blinky);
  connect(ghostMoveTimer, SIGNAL(timeout()), this, SLOT(BlinkyHandler()));

  QPoint clydePoint = QPoint(12 * graphicEngine->GetGridSize() - 10,
                             14 * graphicEngine->GetGridSize() - 10);
  clyde = new Ghost(clydePoint, Direction::Up, "clyde");
  graphicEngine->LoadCharacterUI(clyde);
  connect(ghostMoveTimer, SIGNAL(timeout()), this, SLOT(ClydeHandler()));

  QPoint inkyPoint = QPoint(14 * graphicEngine->GetGridSize() - 10,
                            14 * graphicEngine->GetGridSize() - 10);
  inky = new Ghost(inkyPoint, Direction::Down, "inky");
  graphicEngine->LoadCharacterUI(inky);
  connect(ghostMoveTimer, SIGNAL(timeout()), this, SLOT(InkyHandler()));

  QPoint pinkyPoint = QPoint(16 * graphicEngine->GetGridSize() - 10,
                             14 * graphicEngine->GetGridSize() - 10);
  pinky = new Ghost(pinkyPoint, Direction::Up, "pinky");
  graphicEngine->LoadCharacterUI(pinky);
  connect(ghostMoveTimer, SIGNAL(timeout()), this, SLOT(PinkyHandler()));

  ghostMoveTimer->start(10);
}

void GameEngine::PacManHandler() { pacman->Move(maze); }
void GameEngine::BlinkyHandler() { blinky->Move(maze); }
void GameEngine::ClydeHandler() { clyde->Move(maze); }
void GameEngine::InkyHandler() { inky->Move(maze); }
void GameEngine::PinkyHandler() { pinky->Move(maze); }
