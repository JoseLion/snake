#pragma once

#include <deque>
#include <functional>

#include "layout/cell.h"

class Snake {
  using Callback = std::function<void()>;

  std::deque<Cell> cells = { Cell(6, 9), Cell(5, 9), Cell(4, 9) };
  int pace = 150;
  int timeout = pace;
  int vx = 1;
  int vy = 0;

  const Callback onSelfEat;

  public:
    explicit Snake(const Callback& onSelfEat);

    const Cell& head() const;

    const std::deque<Cell>& body() const;

    void draw() const;

    void update(const Cell& foodPosition);
    
    void respawn();
    
    private:
      bool willSelfEat(const int& nx, const int& ny) const;

      int wrap(const int& coord) const;
};
