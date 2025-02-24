#include "food.h"

#include <deque>

#include "raylib.h"

#include "layout/cell.h"

Food::Food():
  texture(LoadTexture("../assets/food.png")),
  cell(Cell::random())
{

}

Food::~Food() {
  UnloadTexture(this->texture);
}

void Food::draw() const {
  DrawTexture(texture, cell.ox(), cell.oy(), BLACK);
}

Cell Food::position() const {
  return cell;
}

void Food::respawn(const std::deque<Cell>& excludes) {
  cell = Cell::random(excludes);
}
