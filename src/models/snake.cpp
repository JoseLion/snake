#include "snake.h"

#include "raylib.h"

#include "layout/theme.h"

void Snake::draw() const {
  for (const auto cell : cells) {
    DrawRectangleRounded(cell.toRect(), 0.5f, 6, Theme::GREEN_900);
  }
}

void Snake::update() {
  timeout -= static_cast<int>(GetFrameTime() * 1000);

  if (timeout <= 0) {
    const auto [x, y] = cells.front();

    cells.pop_back();
    cells.push_front(Cell(x + vx, y + vy));
    timeout = pace;
  }

  if (vx == 0) {
    if (IsKeyPressed(KEY_LEFT)) {
      vx = -1;
      vy = 0;
    }
  
    if (IsKeyPressed(KEY_RIGHT)) {
      vx = 1;
      vy = 0;
    }
  }

  if (vy == 0) {
    if (IsKeyPressed(KEY_UP)) {
      vx = 0;
      vy = -1;
    }
  
    if (IsKeyPressed(KEY_DOWN)) {
      vx = 0;
      vy = 1;
    }
  }
}
