#include "raylib.h"

#include "layout/grid.h"
#include "layout/theme.h"
#include "models/game.h"
#include "models/food.h"
#include "models/snake.h"

int main() {
  TraceLog(LOG_INFO, "Starting game...");

  InitWindow(Grid::SIZE, Grid::SIZE, "Snake");
  SetTargetFPS(120);

  auto game = Game();
  auto food = Food();
  auto snake = Snake([&game]() { game.stop(); });

  game.onRestart([&snake, &food]() {
    snake.respawn();
    food.respawn(snake.body());
  });

  while (!WindowShouldClose()) {
    BeginDrawing();

    game.update();

    if (!game.isGameOver()) {
      snake.update(food.position());
  
      if (snake.head() == food.position()) {
        food.respawn(snake.body());
      }
    }

    ClearBackground(Theme::GREEN_500);
    food.draw();
    snake.draw();
    game.drawGameOver();

    EndDrawing();
  }

  return 0;
}
