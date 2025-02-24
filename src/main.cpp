#include "raylib.h"

#include "layout/grid.h"
#include "layout/theme.h"
#include "models/food.h"
#include "models/snake.h"

int main() {
  TraceLog(LOG_INFO, "Starting game...");

  InitWindow(Grid::SIZE, Grid::SIZE, "Snake");
  SetTargetFPS(120);

  auto food = Food();
  auto snake = Snake();

  while (!WindowShouldClose()) {
    BeginDrawing();

    snake.update();

    if (snake.head() == food.position()) {
      food.respawn(snake.body());
    }

    ClearBackground(Theme::GREEN_500);
    food.draw();
    snake.draw();

    EndDrawing();
  }

  return 0;
}
