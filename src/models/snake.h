#pragma once

#include <deque>

#include "layout/cell.h"

class Snake {
  std::deque<Cell> cells = { Cell(6, 9), Cell(5, 9), Cell(4, 9) };
  int timeout = 200;
  int pace = 200;
  int vx = 1;
  int vy = 0;

  public:
    const Cell& head() const;

    const std::deque<Cell>& body() const;

    void draw() const;

    void update();
};
