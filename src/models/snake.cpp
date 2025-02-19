#include "snake.h"

#include "raylib.h"

#include "layout/theme.h"

void Snake::draw() const {
  for (const auto cell : cells) {
    DrawRectangleRounded(cell.toRect(), 0.5f, 6, Theme::GREEN_900);
  }
}
