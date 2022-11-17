#ifndef GRAPHICENGINE_H
#define GRAPHICENGINE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>

#include "character.h"
#include "ghost.h"
#include "item.h"
#include "pacman.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class GraphicEngine : public QMainWindow

{
  Q_OBJECT

 public:
  GraphicEngine(QWidget *parent = nullptr);
  ~GraphicEngine();
  void LoadCharacterUI(Character *character);
  void LoadItemUI(Item *item);
  void DrawDebugGrid();
  int GetGridSize();

 private:
  Ui::MainWindow *ui;
  QGraphicsScene *scene;
  const int sceneWidth = 560;
  const int sceneHeight = 720;
  const int sceneStartX = 0;  // maybe never used
 public:
  const int sceneStartY = 60;
  const int gridSize = 20;
};

#endif  // GRAPHICENGINE_H
