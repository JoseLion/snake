#pragma once

#include "raylib.h"

#include "helpers/functions.h"

class Game {
  const Sound scoreFx = LoadSound("../assets/sound/score.wav");
  const Sound levelUpFx = LoadSound("../assets/sound/level-up.wav");

  bool gameOver = true;
  int score = 0;

  Runnable restart = Noop::runnable;
  Runnable levelUp = Noop::runnable;

  public:
    ~Game();

    bool isOver() const;

    void onRestart(const Runnable&& runnable);

    void onLevelUp(const Runnable&& runnable);

    void addScore(const int& value);

    void stop();

    void update();

    void drawGameOver() const;

    void drawScore() const;
};
