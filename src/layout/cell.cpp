#include "cell.h"

#include <algorithm>
#include <deque>

#include "raylib.h"

#include "layout/grid.h"

Cell::Cell(const int& x, const int& y): x(x), y(y) {

}

Cell Cell::random() {
  const auto max = Grid::CELL_COUNT - 1;

  return Cell(GetRandomValue(0, max), GetRandomValue(0, max));
}

Cell Cell::random(const std::deque<Cell>& excludes) {
  const auto next = Cell::random();
  const auto isExcluded = std::any_of(
    excludes.begin(),
    excludes.end(),
    [&](const Cell& cell) { return next == cell; }
  );

  return isExcluded
    ? Cell::random(excludes)
    : next;
}

int Cell::ox() const {
  return x * Grid::CELL_SIZE;
}

int Cell::oy() const {
  return y * Grid::CELL_SIZE;
}

Rectangle Cell::toRect() const {
  return Rectangle {
    static_cast<float>(this->ox()),
    static_cast<float>(this->oy()),
    Grid::CELL_SIZE,
    Grid::CELL_SIZE,
  };
}

bool Cell::operator==(const Cell& other) const = default;
