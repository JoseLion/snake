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
  auto snake = Snake();

  snake.onMove([&food, &game, &snake](const Cell& head) {
    if (food.position() == head) {
      snake.grow();
      game.addScore(100);
      food.respawn(snake.body());
    }
  });

  snake.onEatTail([&game]() {
    game.stop();
  });

  game.onLevelUp([&snake]() {
    snake.speedUp();
  });

  game.onRestart([&snake, &food]() {
    snake.respawn();
    food.respawn(snake.body());
  });

  while (!WindowShouldClose()) {
    BeginDrawing();

    game.update();

    if (!game.isOver()) {
      snake.update();
    }

    ClearBackground(Theme::GREEN_500);
    food.draw();
    snake.draw();
    game.drawScore();
    game.drawGameOver();

    DrawFPS(10, 10);

    EndDrawing();
  }

  return 0;
}
