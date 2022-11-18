#include "graphicengine.h"

#include <QGraphicsGridLayout>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QPixmap>

#include "ghost.h"
#include "pacman.h"
#include "ui_mainwindow.h"

GraphicEngine::GraphicEngine(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  scene = new QGraphicsScene(0, 0, sceneWidth, sceneHeight);
  scene->setBackgroundBrush(Qt::black);
  scene->setSceneRect(0, -60, sceneWidth, sceneHeight);
  scene->addPixmap(QPixmap(":/res/img/maze.png").scaledToWidth(sceneWidth));
  ui->graphicsView->setScene(scene);

  //DrawDebugGrid();
}

void GraphicEngine::LoadCharacterUI(Character *character) {
  scene->addItem(character);
}

void GraphicEngine::LoadItemUI(Item *item) { scene->addItem(item); }

void GraphicEngine::DrawDebugGrid() {
  // vertical lines
  for (int x = sceneStartX; x <= sceneWidth; x += gridSize)
    scene->addLine(x, -sceneStartY, x, sceneHeight, QPen(Qt::gray));

  // horizontal lines
  for (int y = -sceneStartY; y <= sceneHeight; y += gridSize)
    scene->addLine(sceneStartX, y, sceneWidth - sceneStartX, y, QPen(Qt::gray));
}

int GraphicEngine::GetGridSize() { return gridSize; }

GraphicEngine::~GraphicEngine() { delete ui; }
