#pragma once

#include "raylib.h"

#include "layout/cell.h"

class Food {
  const Cell cell;
  const Texture2D texture;

  public:
    Food();

    ~Food();

    void draw() const;
};
