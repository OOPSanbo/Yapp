#include "graphicengine.h"
#include "ghost.h"
#include "pacman.h"
#include "ui_mainwindow.h"
#include <QGraphicsGridLayout>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QPixmap>

GraphicEngine::GraphicEngine(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  scene = new QGraphicsScene(0, 0, sceneWidth, sceneHeight);
  scene->setBackgroundBrush(Qt::black);
  scene->setSceneRect(0, -42, sceneWidth, sceneHeight);
  scene->addPixmap(QPixmap(":/res/img/maze.png").scaledToWidth(sceneWidth));
  ui->graphicsView->setScene(scene);

  // DrawDebugGrid();
}

void GraphicEngine::LoadCharacterUI(Character *character) {

  scene->addItem(character);
}

void GraphicEngine::LoadItemUI(Item *item) { scene->addItem(item); }

void GraphicEngine::DrawDebugGrid() {
  // vertical lines
  for (int x = sceneStartX; x <= sceneWidth - sceneStartX; x += gridSize)
    scene->addLine(x, 0, x, sceneHeight - sceneStartY * 2, QPen(Qt::red));

  // horizontal lines
  for (int y = 0; y <= sceneHeight - sceneStartY * 2; y += gridSize)
    scene->addLine(sceneStartX, y, sceneWidth - sceneStartX, y, QPen(Qt::red));
}

int GraphicEngine::GetGridSize() { return gridSize; }

GraphicEngine::~GraphicEngine() { delete ui; }
