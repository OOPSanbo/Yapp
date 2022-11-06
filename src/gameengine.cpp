#include "gameengine.h"

#include <QGraphicsScene>
#include <QGraphicsView>

#include "dot.h"
#include "pacman.h"
#include "pellet.h"

GameEngine::GameEngine() {
  graphicEngine = new GraphicEngine();
  dotModel = DotModel();
}

void GameEngine::StartGame() {
  pacman = new Pacman();
  graphicEngine->LoadCharacterUI(pacman);
  InitMaze();
}

void GameEngine::EndGame() { delete pacman; }

GameEngine::~GameEngine() { delete graphicEngine; }

void GameEngine::InitMaze() {
  maze = new Maze();
  QList<QPoint> dot_points = maze->WhereAreDots();
  QList<QPoint> pellet_points = maze->WhereArePellets();

  QPoint pos;
  Item *pItem;
  foreach (pos, dot_points) {
    pItem = new Dot(pos);

    graphicEngine->LoadItemUI(pItem);
    items.append(pItem);
  }

  foreach (pos, pellet_points) {
    pItem = new Pellet(pos);

    graphicEngine->LoadItemUI(pItem);
    items.append(pItem);
  }
}
