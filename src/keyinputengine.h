#ifndef KEYINPUTENGINE_H
#define KEYINPUTENGINE_H

#include <QKeyEvent>
#include <QObject>

class KeyInputEngine : QObject {
  Q_OBJECT
public:
  KeyInputEngine();
  void keyPressEvent(QKeyEvent *event);
};

#endif // KEYINPUTENGINE_H
