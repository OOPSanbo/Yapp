#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QImage>
#include <QLabel>
#include <QMainWindow>
#include <QObject>
#include <QPixmap>

#include "game.h"
#include "title.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);

  void Intro();
  void Score();
  ~MainWindow();

 public slots:
  void HandleStartGame();

 private:
  Ui::MainWindow *ui;
  QGraphicsScene *scene;

  Game *game;
  Title *title;
  QMetaObject::Connection connectSignal;

  const int sceneWidth = 560;
  const int sceneHeight = 720;
  const int sceneGridScale = 20;
  const int sceneMazeOffset = 60;

  void DrawDebugGrid();
};
#endif  // MAINWINDOW_H
