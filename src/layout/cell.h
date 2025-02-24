#pragma once

#include <deque>

#include "raylib.h"

struct Cell {
  int x;
  int y;

  Cell(const int& x, const int& y);

  static Cell random();

  static Cell random(const std::deque<Cell>& exludes);

  int ox() const;

  int oy() const;

  Rectangle toRect() const;

  bool operator==(const Cell& other) const;
};
