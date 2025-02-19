#pragma once

#include "raylib.h"

class Food {
  const int x;
  const int y;
  const Texture2D texture;

  public:
    Food();

    ~Food();

    void draw() const;
};
