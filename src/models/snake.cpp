#include "snake.h"

#include <algorithm>
#include <deque>

#include "raylib.h"

#include "layout/grid.h"
#include "layout/theme.h"

Snake::Snake(const Callback& onSelfEat): onSelfEat(onSelfEat) {

}

const Cell& Snake::head() const {
  return this->cells.front();
}

const std::deque<Cell>& Snake::body() const {
  return this->cells;
}

void Snake::draw() const {
  for (const auto cell : this->cells) {
    DrawRectangleRounded(cell.toRect(), 0.5f, 6, Theme::GREEN_900);
  }
}

void Snake::update(const Cell& foodPosition) {
  this->timeout -= static_cast<int>(GetFrameTime() * 1000);

  const auto [x, y] = this->head();
  const auto prev = this->cells.at(1);

  if (this->timeout <= 0) {
    const auto nx = this->wrap(x + this->vx);
    const auto ny = this->wrap(y + this->vy);

    if (this->willSelfEat(nx, ny)) {
      this->onSelfEat();
      return;
    }

    this->cells.emplace_front(nx, ny);

    if (foodPosition.x != nx || foodPosition.y != ny) {
      this->cells.pop_back();
    }

    this->timeout = this->pace;
  }

  if (IsKeyPressed(KEY_LEFT) && prev.x != this->wrap(x - 1)) {
    this->vx = -1;
    this->vy = 0;
  }

  if (IsKeyPressed(KEY_RIGHT) && prev.x != this->wrap(x + 1)) {
    this->vx = 1;
    this->vy = 0;
  }

  if (IsKeyPressed(KEY_UP) && prev.y != this->wrap(y - 1)) {
    this->vx = 0;
    this->vy = -1;
  }

  if (IsKeyPressed(KEY_DOWN) && prev.y != this->wrap(y + 1)) {
    this->vx = 0;
    this->vy = 1;
  }
}

bool Snake::willSelfEat(const int& nx, const int& ny) const {
  return std::any_of(
    this->cells.begin() + 1,
    this->cells.end(),
    [&](const Cell& cell) { return cell.x == nx && cell.y == ny; }
  );
}

void Snake::respawn() {
  this->cells = { Cell(6, 9), Cell(5, 9), Cell(4, 9) };
  this->pace = 150;
  this->timeout = pace;
  this->vx = 1;
  this->vy = 0;
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
