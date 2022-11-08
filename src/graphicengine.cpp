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

  scene = new QGraphicsScene(0, 0, sceneWidth, sceneHeight);
  //  QTransform old_transform = ui->graphicsView->transform();

  //  ui->graphicsView->setTransformationAnchor(QGraphicsView::NoAnchor);
  //  old_transform.translate(0, sceneStartY);
  //  ui->graphicsView->translate(0, sceneStartY);
  //  ui->graphicsView->setTransform(old_transform);

  //  QRectF scene_rect = scene->sceneRect();
  //  QRectF new_scene_rect(scene_rect.x() - 0, scene_rect.y() - 42,
  //                        scene_rect.width(), scene_rect.height());
  //  scene->setSceneRect(new_scene_rect);

  //  ui->graphicsView->setTransform(old_transform);

  scene->setBackgroundBrush(
      QPixmap(":/res/img/maze.png").scaledToWidth(sceneWidth));
  ui->graphicsView->setScene(scene);

  DrawDebugGrid();
}

void GraphicEngine::LoadCharacterUI(Character *character) {
  scene->addItem(character);
}

void GraphicEngine::LoadItemUI(Item *item) { scene->addItem(item); }

void GraphicEngine::DrawDebugGrid() {
  // vertical lines
  for (int x = sceneStartX; x <= sceneWidth; x += gridSize)
    scene->addLine(x, sceneStartY, x, sceneHeight - sceneStartY, QPen(Qt::red));

  // horizontal lines
  for (int y = sceneStartY; y <= sceneHeight - sceneStartY; y += gridSize)
    scene->addLine(sceneStartX, y, sceneWidth - sceneStartX, y, QPen(Qt::red));
}

int GraphicEngine::GetGridSize() { return gridSize; }

GraphicEngine::~GraphicEngine() { delete ui; }
