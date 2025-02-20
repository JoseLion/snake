#pragma once

#include "raylib.h"

struct Cell {
  const int x;
  const int y;

  Cell(const int& x, const int& y);

  static Cell random();

  int ox() const;

  int oy() const;

  Rectangle toRect() const;
};
