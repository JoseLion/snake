#pragma once

#include "raylib.h"

class Cell {
  const int x;
  const int y;

  public:
    Cell(const int& x, const int& y);

    static Cell random();

    int ox() const;

    int oy() const;

    Rectangle toRect() const;
};
