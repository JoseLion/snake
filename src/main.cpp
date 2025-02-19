#include "raylib.h"

#include "layout/grid.h"
#include "layout/theme.h"
#include "models/food.h"

int main() {
  TraceLog(LOG_INFO, "Starting game...");

  InitWindow(Grid::SIZE, Grid::SIZE, "Snake");
  SetTargetFPS(120);

  const auto food = Food();

  while (!WindowShouldClose()) {
    BeginDrawing();

    ClearBackground(Theme::GREEN_500);
    food.draw();

    EndDrawing();
  }

  return 0;
}
