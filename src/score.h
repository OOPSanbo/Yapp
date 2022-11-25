#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QObject>

class Score : public QObject{
  Q_OBJECT
  public:
    Score(QGraphicsScene *scene);
    QGraphicsScene *scene;
    void UpdateScore();

  public slots:
    void HandleIncreaseScore();

  private:
    int score_value;
    QGraphicsTextItem* score_text;
    QGraphicsPixmapItem scoreshape;
};

#endif // SCORE_H