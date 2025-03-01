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
  DrawTexture(this->texture, this->cell.ox(), this->cell.oy(), BLACK);
}

Cell Food::position() const {
  return this->cell;
}

void Food::respawn(const std::deque<Cell>& excludes) {
  this->cell = Cell::random(excludes);
}
