#pragma once

#include <deque>

#include "raylib.h"

#include "layout/cell.h"

class Food {
  const Texture2D texture;
  Cell cell;

  public:
    Food();

    ~Food();

    void draw() const;

    Cell position() const;

    void respawn(const std::deque<Cell>& excludes);
};
