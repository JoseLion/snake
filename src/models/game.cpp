#include "game.h"

#include "raylib.h"

#include "layout/grid.h"
#include "layout/theme.h"

bool Game::isGameOver() const {
  return this->gameOver;
}

void Game::onRestart(const Callback& callback) {
  this->doRestart = callback;
}

void Game::stop() {
  this->gameOver = true;
}

void Game::update() {
  if (this->gameOver && IsKeyPressed(KEY_SPACE)) {
    this->doRestart();
    this->gameOver = false;
  }
}

void Game::drawGameOver() const {
  if (this->gameOver) {
    const auto halfSize = Grid::SIZE / 2;
  
    const auto title = "Game Over";
    const auto titleSize = 80;
    const auto titleX = halfSize - (MeasureText(title, titleSize) / 2);
    const auto titleY = halfSize - 40;
  
    const auto info = "Press [SPACE] to restart";
    const auto infoSize = 30;
    const auto infoX = halfSize - MeasureText(info, infoSize) / 2;
    const auto infoY = titleY + titleSize;

    DrawText(title, titleX, titleY, titleSize, Theme::GREEN_50);
    DrawText(info, infoX, infoY, infoSize, Theme::GREEN_50);
  }
}
