#include "frightenedbehavior.h"

FrightenedBehavior::FrightenedBehavior() {}

void FrightenedBehavior::Frightened(Ghost &ghostObject) {
  Direction::eDirection randomDirection = static_cast<Direction::eDirection>(rand() % 4);

  while (randomDirection == Direction::Reverse(ghostObject.GetDirection())) {
    randomDirection = static_cast<Direction::eDirection>(rand() % 4);
  }

  ghostObject.SetNextDirection(randomDirection);
}
