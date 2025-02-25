#include "snake.h"

#include <deque>

#include "layout/grid.h"
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

  const auto [x, y] = head();
  const auto prev = cells.at(1);

  if (timeout <= 0) {
    const auto nx = wrap(x + vx);
    const auto ny = wrap(y + vy);

    cells.emplace_front(nx, ny);

    if (foodPosition.x != nx || foodPosition.y != ny) {
      cells.pop_back();
    }

    timeout = pace;
  }

  if (IsKeyPressed(KEY_LEFT) && prev.x != wrap(x - 1)) {
    vx = -1;
    vy = 0;
  }

  if (IsKeyPressed(KEY_RIGHT) && prev.x != wrap(x + 1)) {
    vx = 1;
    vy = 0;
  }

  if (IsKeyPressed(KEY_UP) && prev.y != wrap(y - 1)) {
    vx = 0;
    vy = -1;
  }

  if (IsKeyPressed(KEY_DOWN) && prev.y != wrap(y + 1)) {
    vx = 0;
    vy = 1;
  }
}

int Snake::wrap(const int& coord) const {
  const auto max = Grid::CELL_COUNT - 1;

  if (coord < 0) {
    return max;
  }

  if (coord > max) {
    return 0;
  }

  return coord;
}
