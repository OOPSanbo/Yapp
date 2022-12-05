#include "score.h"

#include <QApplication>
#include <QFile>
#include <QTextStream>

Score::Score(QGraphicsScene *scene) : scene(scene) {
  score_value = 0;
  QString score_str = "SCORE : ";
  score_str.append(QString::number(score_value));

  score_text = scene->addText(score_str);
  score_text->setPos(30, -30);
  score_text->setDefaultTextColor("white");

  QString ApplicationPath = QApplication::applicationDirPath();
  QFile File(ApplicationPath + "/highscore.txt");
  if (!File.open(QFile::ReadOnly | QFile::Text)) {
    if (!File.exists()) {
      highscore_value = 0;
    }
  } else {
    if (File.size() == 0) {
      highscore_value = 0;
      File.close();
    } else {
      QTextStream OpenFile(&File);
      highscore_value = OpenFile.readLine().toInt();
      File.close();
    }
  }

  QString highscore_str = "HIGHSCORE : ";
  highscore_str.append(QString::number(highscore_value));
  highscore_text = scene->addText(highscore_str);
  highscore_text->setPos(30, -50);
  highscore_text->setDefaultTextColor("white");
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

  if (score_value > highscore_value) {
    highscore_value = score_value;
    QString highscore_str = "HIGHSCORE : ";
    highscore_str.append(QString::number(highscore_value));
    highscore_text->setPlainText(highscore_str);
  }
}

void Score::IncreasePelletScore() {
  score_value += 50;

  QString score_str = "SCORE : ";
  score_str.append(QString::number(score_value));
  score_text->setPlainText(score_str);

  if (score_value > highscore_value) {
    highscore_value = score_value;
    QString highscore_str = "HIGHSCORE : ";
    highscore_str.append(QString::number(highscore_value));
    highscore_text->setPlainText(highscore_str);
  }
}

void Score::IncreaseGhostScore() {
  score_value += 200;

  QString score_str = "SCORE : ";
  score_str.append(QString::number(score_value));
  score_text->setPlainText(score_str);

  if (score_value > highscore_value) {
    highscore_value = score_value;
    QString highscore_str = "HIGHSCORE : ";
    highscore_str.append(QString::number(highscore_value));
    highscore_text->setPlainText(highscore_str);
  }
}

void Score::Delete() {
  scene->removeItem(score_text);
  scene->removeItem(highscore_text);
}

void Score::SaveHighscore() {
  if (highscore_value > score_value) return;

  QString ApplicationPath = QApplication::applicationDirPath();
  QFile File(ApplicationPath + "/highscore.txt");
  File.open(QFile::WriteOnly | QFile::Truncate | QFile::Text);
  QTextStream SaveFile(&File);
  SaveFile << highscore_value;
  File.close();
}
