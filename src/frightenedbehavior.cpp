#include "frightenedbehavior.h"

FrightenedBehavior::FrightenedBehavior() {}

void FrightenedBehavior::Frightened(Ghost &ghostObject) {
  eDirection randomDirection = static_cast<eDirection>(rand() % 4);

  while (randomDirection == dir::Reverse(ghostObject.GetDirection())) {
    randomDirection = static_cast<eDirection>(rand() % 4);
  }

  ghostObject.SetNextDirection(randomDirection);
}
