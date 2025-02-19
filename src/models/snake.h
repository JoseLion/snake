#pragma once

#include <deque>

#include "layout/cell.h"

class Snake {
  std::deque<Cell> cells = { Cell(8, 12), Cell(9, 12), Cell(10, 12) };

  public:
    void draw() const;
};
