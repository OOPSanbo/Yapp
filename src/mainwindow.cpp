#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  scene = new QGraphicsScene(0, 0, sceneWidth, sceneHeight);
  scene->setBackgroundBrush(Qt::black);
  scene->setSceneRect(0, -sceneMazeOffset, sceneWidth, sceneHeight);
  ui->graphicsView->setScene(scene);
}

void MainWindow::StartGame() {
  scene->addPixmap(QPixmap(":/res/img/maze.png").scaledToWidth(sceneWidth));
  DrawDebugGrid();

  game = new Game(scene);
  game->Init();
  game->GameLoop();
}

void MainWindow::DrawDebugGrid() {
  // vertical lines
  for (int x = 0; x <= sceneWidth; x += sceneGridScale)
    scene->addLine(x, -sceneMazeOffset, x, sceneHeight, QPen(Qt::gray));

  // horizontal lines
  for (int y = -sceneMazeOffset; y <= sceneHeight; y += sceneGridScale)
    scene->addLine(0, y, sceneWidth, y, QPen(Qt::gray));
}

MainWindow::~MainWindow() { delete ui; }
