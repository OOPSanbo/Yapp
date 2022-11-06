#ifndef CHARACTER_H
#define CHARACTER_H

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QString>

enum eDirection { Up, Down, Left, Right };

class Character : public QObject, public QGraphicsPixmapItem {
protected:
  const QString name;
  QPointF pos;
  eDirection direction;

public:
  Character();
  QPointF getPos();
  // virtual void SetDirection() = 0;
public slots:
  virtual void SwitchAnimate() = 0;
  // virtual void NextSprite() = 0;
};

#endif // CHARACTER_H
