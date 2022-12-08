#include <QApplication>
#include <QFontDatabase>

#include "QLabel"
#include "mainwindow.h"
int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  a.setWindowIcon(QIcon(":/res/img/pacman/1.png"));
  MainWindow w;
  int id = QFontDatabase::addApplicationFont(":/res/font/emulogic.ttf");
  QString family = QFontDatabase::applicationFontFamilies(id).at(0);
  QFont SerifFont(family);
  a.setFont(SerifFont);
  w.show();
  w.Intro();
  return a.exec();
}
