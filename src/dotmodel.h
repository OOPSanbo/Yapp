#ifndef DOTMODEL_H
#define DOTMODEL_H
#include <QPixmap>

class DotModel {
private:
  int size;
  QPixmap shape;

public:
  DotModel();
  ~DotModel();
};

#endif // DOTMODEL_H
