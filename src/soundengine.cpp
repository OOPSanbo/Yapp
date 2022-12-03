#include "soundengine.h"

#include <QUrl>

SoundEngine::SoundEngine() {
  player = new QMediaPlayer();
  audio = new QAudioOutput();
  player->setAudioOutput(audio);
  audio->setVolume(50);
}

void SoundEngine::BeginSound() {
  player->setSource(QUrl("qrc:/res/sound/pacman_beginning.wav"));
  player->play();
}

void SoundEngine::EatDotsSound() {
  player->setSource(QUrl::fromLocalFile("qrc:/res/sound/pacman_chomp.wav"));
  player->play();
}

void SoundEngine::DeathSound() {
  player->setSource(QUrl::fromLocalFile("qrc:/res/sound/pacman_death.wav"));
  player->play();
}

void SoundEngine::EatGhostSound() {
  player->setSource(QUrl::fromLocalFile("qrc:/res/sound/pacman_eatghost.wav"));
  player->play();
}

void SoundEngine::EndSound() {
  player->setSource(
      QUrl::fromLocalFile("qrc:/res/sound/pacman_intermission.wav"));
  player->play();
}
