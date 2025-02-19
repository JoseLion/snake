#include "grid.h"

#include "raylib.h"

int Grid::randomCell() {
  return GetRandomValue(0, CELL_COUNT - 1);
}

int Grid::cellOrigin(const int& cell) {
  return cell * CELL_SIZE;
}
