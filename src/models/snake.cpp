#include "snake.h"

#include <deque>

#include "raylib.h"

#include "layout/theme.h"

const Cell& Snake::head() const {
  return cells.front();
}

const std::deque<Cell>& Snake::body() const {
  return cells;
}

void Snake::draw() const {
  for (const auto cell : cells) {
    DrawRectangleRounded(cell.toRect(), 0.5f, 6, Theme::GREEN_900);
  }
}

void Snake::update(const Cell& foodPosition) {
  timeout -= static_cast<int>(GetFrameTime() * 1000);

  const auto [x, y] = cells.front();
  const auto prev = cells.at(1);

  if (timeout <= 0) {
    const auto nx = x + vx;
    const auto ny = y + vy;

    cells.emplace_front(nx, ny);

    if (foodPosition.x != nx || foodPosition.y != ny) {
      cells.pop_back();
    }

    timeout = pace;
  }

  if (IsKeyPressed(KEY_LEFT) && prev.x != x - 1) {
    vx = -1;
    vy = 0;
  }

  if (IsKeyPressed(KEY_RIGHT) && prev.x != x + 1) {
    vx = 1;
    vy = 0;
  }

  if (IsKeyPressed(KEY_UP) && prev.y != y - 1) {
    vx = 0;
    vy = -1;
  }

  if (IsKeyPressed(KEY_DOWN) && prev.y != y + 1) {
    vx = 0;
    vy = 1;
  }
}
