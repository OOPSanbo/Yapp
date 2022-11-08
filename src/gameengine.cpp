#include "gameengine.h"

#include <QGraphicsScene>
#include <QGraphicsView>

#include "dot.h"
#include "pacman.h"
#include "pellet.h"

#include <QTimer>

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

void GameEngine::EndGame() { delete pacman; }

GameEngine::~GameEngine() { delete graphicEngine; }

void GameEngine::InitMaze() { maze = new Maze(); }

void GameEngine::InitItem() {
  QList<QPoint> dotPoints = maze->WhereAreDots();
  QList<QPoint> pelletPoints = maze->WhereArePellets();

  QPoint point;
  Item *pItem;
  foreach (point, dotPoints) {
    pItem = new Dot(point * graphicEngine->GetGridSize() + QPoint(6, 48));
    graphicEngine->LoadItemUI(pItem);
    items.append(pItem);
  }

  foreach (point, pelletPoints) {
    pItem = new Pellet(point * graphicEngine->GetGridSize() + QPoint(6, 48));
    graphicEngine->LoadItemUI(pItem);
    items.append(pItem);
  }
}

void GameEngine::InitCharacter() {
  QPoint pacmanPoint =
      QPoint(13 * graphicEngine->GetGridSize(),
             23 * graphicEngine->GetGridSize() + graphicEngine->sceneStartY);
  pacman = new Pacman(pacmanPoint, Direction::Right);

  graphicEngine->LoadCharacterUI(pacman);
  pacmanMoveTimer = new QTimer(this);
  connect(pacmanMoveTimer, SIGNAL(timeout()), this, SLOT(PacManHandler()));
  pacmanMoveTimer->start(10);
}

void GameEngine::PacManHandler() { pacman->Move(maze); }
