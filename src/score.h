#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QObject>

class Score : public QObject {
  Q_OBJECT
 public:
  Score(QGraphicsScene *scene);
  QGraphicsScene *scene;
  void UpdateScore();
  void Delete();
  void SaveHighscore();

 public slots:
  void IncreaseDotScore();
  void IncreasePelletScore();

 private:
  int score_value;
  int highscore_value;
  QGraphicsTextItem *score_text;
  QGraphicsTextItem *highscore_text;
  QGraphicsPixmapItem scoreshape;
};

#endif  // SCORE_H
