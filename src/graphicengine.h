#ifndef GRAPHICENGINE_H
#define GRAPHICENGINE_H

#include "character.h"
#include "item.h"
#include "pacman.h"

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>

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
  Character *pacman;
  ~GraphicEngine();
  void LoadCharacterUI(Character *character);
  void LoadItemUI(Item *item);
  void DrawDebugGrid();

private:
  Ui::MainWindow *ui;
  QGraphicsScene *scene;
  const int sceneWidth = 560;
  const int sceneHeight = 705;
  const int sceneStartX = 0; // maybe never used
  const int sceneStartY = 42;
  const int gridSize = 20;
};

#endif // GRAPHICENGINE_H
