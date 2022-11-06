#include "mainwindow.h"

#include <QGraphicsScene>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  this->setWindowTitle("Yet Another Pacman Project!");
  this->setWindowIcon(QPixmap(":/res/1.png"));

  QGraphicsScene *scene = new QGraphicsScene(ui->graphicsView);
  scene->setBackgroundBrush(QPixmap(":/res/map.png").scaledToHeight(565));
}

MainWindow::~MainWindow() { delete ui; }
