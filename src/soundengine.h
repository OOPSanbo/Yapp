#ifndef SOUNDENGINE_H
#define SOUNDENGINE_H

#include <QAudioOutput>
#include <QMediaPlayer>
#include <QObject>

class SoundEngine : public QObject {
  Q_OBJECT
 private:
  QMediaPlayer* player;
  QAudioOutput* audio;

 public:
  SoundEngine();
  void BeginSound();

 public slots:
  void EatDotsSound();
  void DeathSound();
  void EatGhostSound();
  void EndSound();
};

#endif  // SOUNDENGINE_H
