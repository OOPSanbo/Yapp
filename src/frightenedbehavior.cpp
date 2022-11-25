#include "frightenedbehavior.h"

FrightenedBehavior::FrightenedBehavior() {}

void FrightenedBehavior::Frightened(Ghost &ghostObject) {
  ghostObject.SetNextDirection(static_cast<eDirection>(rand() % 4));
}
