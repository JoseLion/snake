#include "cell.h"

#include "raylib.h"

#include "layout/grid.h"

Cell::Cell(const int& x, const int& y): x(x), y(y) {

}

Cell Cell::random() {
  const auto max = Grid::CELL_COUNT - 1;

  return Cell(GetRandomValue(0, max), GetRandomValue(0, max));
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
