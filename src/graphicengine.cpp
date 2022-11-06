#include "graphicengine.h"
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

  // int sceneWidth = ui->graphicsView->width() - 2;
  // int sceneHeight = ui->graphicsView->height() - 2;

  scene = new QGraphicsScene(0, 0, sceneWidth - 2, sceneHeight - 2);
  scene->setBackgroundBrush(
      QPixmap(":/res/map.png").scaledToWidth(sceneWidth - 2));
  ui->graphicsView->setScene(scene);

  DrawDebugGrid();
}

void GraphicEngine::LoadCharacterUI(Character *character) {
  scene->addItem(character);
  QPointF pos = character->getPos();
  character->setPos(pos.x() * gridSize, sceneStartY + pos.y() * gridSize);
}

void GraphicEngine::LoadItemUI(Item *item) {
  scene->addItem(item);
  QPoint pos = item->getPos();
  item->setPos(pos.x() * gridSize + 6, sceneStartY + pos.y() * gridSize + 6);
}

void GraphicEngine::DrawDebugGrid() {
  // vertical lines
  for (int x = sceneStartX; x <= sceneWidth; x += gridSize)
    scene->addLine(x, sceneStartY, x, sceneHeight - sceneStartY, QPen(Qt::red));

  // horizontal lines
  for (int y = sceneStartY; y <= sceneHeight - sceneStartY; y += gridSize)
    scene->addLine(sceneStartX, y, sceneWidth - sceneStartX, y, QPen(Qt::red));
}

GraphicEngine::~GraphicEngine() { delete ui; }
