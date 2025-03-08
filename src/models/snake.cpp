#include "snake.h"

#include <algorithm>
#include <deque>

#include "raylib.h"

#include "layout/grid.h"
#include "layout/theme.h"

Snake::~Snake() {
  UnloadSound(this->eatTailFx);
}

const Cell& Snake::head() const {
  return this->cells.front();
}

const std::deque<Cell>& Snake::body() const {
  return this->cells;
}

void Snake::onMove(const Consumer<Cell>&& consumer) {
  this->moved = consumer;
}

void Snake::onEatTail(const Runnable&& runnable) {
  this->ateTail = runnable;
}

void Snake::grow() {
  this->shouldGrow = true;
}

void Snake::respawn() {
  this->cells = { Cell(6, 9), Cell(5, 9), Cell(4, 9) };
  this->pace = 150;
  this->timeout = pace;
  this->vx = 1;
  this->vy = 0;
}

void Snake::speedUp() {
  this->pace = static_cast<int>(this->pace * 0.9);
  this->timeout = pace;
}

void Snake::handleInput() {
  const auto [x, y] = this->head();
  const auto prev = this->cells.at(1);

  switch (GetKeyPressed()) {
    case KEY_LEFT:
      if (prev.x != this->wrap(x - 1)) {
        this->vx = -1;
        this->vy = 0;
      }
      break;

    case KEY_RIGHT:
      if (prev.x != this->wrap(x + 1)) {
        this->vx = 1;
        this->vy = 0;
      }
      break;

    case KEY_UP:
      if (prev.y != this->wrap(y - 1)) {
        this->vx = 0;
        this->vy = -1;
      }
      break;

    case KEY_DOWN:
      if (prev.y != this->wrap(y + 1)) {
        this->vx = 0;
        this->vy = 1;
      }
      break;

    default:
      break;
  }
}

void Snake::update() {
  this->timeout -= static_cast<int>(GetFrameTime() * 1000);

  const auto [x, y] = this->head();

  if (this->timeout <= 0) {
    const auto nx = this->wrap(x + this->vx);
    const auto ny = this->wrap(y + this->vy);

    if (this->willEatTail(nx, ny)) {
      PlaySound(this->eatTailFx);
      this->ateTail();
      return;
    }

    if (this->shouldGrow) {
      this->shouldGrow = false;
    } else {
      this->cells.pop_back();
    }

    this->cells.emplace_front(nx, ny);
    this->moved(this->head());
    this->timeout = this->pace;
  }
}

void Snake::draw() const {
  for (const auto cell : this->cells) {
    DrawRectangleRounded(cell.toRect(), 0.5f, 6, Theme::GREEN_900);
  }
}

bool Snake::willEatTail(const int& nx, const int& ny) const {
  return std::any_of(
    this->cells.begin() + 1,
    this->cells.end(),
    [&](const Cell& cell) { return cell.x == nx && cell.y == ny; }
  );
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
