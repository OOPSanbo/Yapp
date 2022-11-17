#include "keyinputengine.h"

#include <QDebug>

KeyInputEngine::KeyInputEngine() { qDebug() << "init"; }

void KeyInputEngine::keyPressEvent(QKeyEvent *event) {
  if (event->key() == Qt::Key_W) {
    qDebug() << "W";
  }
}
