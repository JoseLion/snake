#pragma once

#include <functional>

class Game {
  using Callback = std::function<void()>;

  Callback doRestart = []() { /* do nothing */};
  bool gameOver = true;

  public:
    bool isGameOver() const;

    void onRestart(const Callback& doRestart);

    void stop();

    void update();

    void drawGameOver() const;
};
