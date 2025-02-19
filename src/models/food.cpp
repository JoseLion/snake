#include "food.h"

#include "raylib.h"

#include "layout/cell.h"

Food::Food():
  cell(Cell::random()),
  texture(LoadTexture("../assets/food.png"))
{

}

Food::~Food() {
  UnloadTexture(this->texture);
}

void Food::draw() const {
  DrawTexture(texture, cell.ox(), cell.oy(), BLACK);
}
