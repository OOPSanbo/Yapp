#include "score.h"

Score::Score(QGraphicsScene *scene) : scene(scene) {
  score_value = 0;
  QString score_str = "SCORE : ";
  score_str.append(QString::number(score_value));

  score_text = scene->addText(score_str);

  score_text->setPos(30, -30);
  score_text->setDefaultTextColor("white");
}

void Score::UpdateScore() {
  QString score_str = "SCORE : ";
  // score_value++;
  score_str.append(QString::number(score_value));
  score_text->setPlainText(score_str);
}

void Score::IncreaseDotScore() {
  score_value += 10;

  QString score_str = "SCORE : ";
  score_str.append(QString::number(score_value));

  score_text->setPlainText(score_str);
}

void Score::IncreasePelletScore() {
  score_value += 50;

  QString score_str = "SCORE : ";
  score_str.append(QString::number(score_value));

  score_text->setPlainText(score_str);
}
void Score::Delete() { scene->removeItem(score_text); }
