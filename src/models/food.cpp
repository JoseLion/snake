#include "food.h"

#include "raylib.h"

#include "layout/grid.h"

Food::Food():
  x(Grid::randomCell()),
  y(Grid::randomCell()),
  texture(LoadTexture("../assets/food.png"))
{

}

Food::~Food() {
  UnloadTexture(this->texture);
}

void Food::draw() const {
  DrawTexture(texture, Grid::cellOrigin(x), Grid::cellOrigin(y), BLACK);
}
