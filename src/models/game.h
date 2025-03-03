#pragma once

#include "helpers/functions.h"

class Game {
  bool gameOver = true;
  int score = 0;

  Runnable restart = Noop::runnable;
  Runnable levelUp = Noop::runnable;

  public:
    bool isOver() const;

    void onRestart(const Runnable&& runnable);

    void onLevelUp(const Runnable&& runnable);

    void addScore(const int& value);

    void stop();

    void update();

    void drawGameOver() const;

    void drawScore() const;
};
