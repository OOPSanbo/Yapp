#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QMainWindow>

#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);

  void Title();
  void StartGame();
  void Score();

  ~MainWindow();

 private slots:

 private:
  Ui::MainWindow *ui;
  QGraphicsScene *scene;

  Game *game;

  const int sceneWidth = 560;
  const int sceneHeight = 720;
  const int sceneGridScale = 20;
  const int sceneMazeOffset = 60;

  void DrawDebugGrid();
};
#endif  // MAINWINDOW_H
