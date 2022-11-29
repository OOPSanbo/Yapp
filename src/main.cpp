#include <QApplication>
#include <QFontDatabase>

#include "QLabel"
#include "mainwindow.h"
int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  int id = QFontDatabase::addApplicationFont(":/res/font/emulogic.ttf");
  QString family = QFontDatabase::applicationFontFamilies(id).at(0);
  QFont SerifFont(family);
  a.setFont(SerifFont);
  a.setWindowIcon(QIcon(":/res/img/pacman/1.png"));
  w.show();
  w.HandleStartGame();
  return a.exec();
}
