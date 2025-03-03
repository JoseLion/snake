#pragma once

#include <deque>

#include "helpers/functions.h"
#include "layout/cell.h"

class Snake {
  std::deque<Cell> cells = { Cell(6, 9), Cell(5, 9), Cell(4, 9) };
  int pace = 150;
  int timeout = pace;
  int vx = 1;
  int vy = 0;
  bool shouldGrow = false;

  Consumer<Cell> moved = Noop::consumer<Cell>;
  Runnable ateTail = Noop::runnable;

  public:
    const Cell& head() const;

    const std::deque<Cell>& body() const;

    void onMove(const Consumer<Cell>&& consumer);

    void onEatTail(const Runnable&& runnable);

    void grow();
    
    void respawn();

    void speedUp();

    void update();

    void draw() const;
    
    private:
      bool willEatTail(const int& nx, const int& ny) const;

      int wrap(const int& coord) const;
};
