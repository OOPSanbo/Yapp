#include <QApplication>

#include "gameengine.h"
#include "graphicengine.h"
#include "mainwindow.h"
int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  // MainWindow w;
  //  w.show();

  GameEngine g;
  g.graphicEngine->show();
  g.StartGame();
  return a.exec();
}
