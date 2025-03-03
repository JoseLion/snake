#include "game.h"

#include "raylib.h"

#include "layout/grid.h"
#include "layout/theme.h"

Game::~Game() {
  UnloadSound(this->scoreFx);
  UnloadSound(this->levelUpFx);
}

bool Game::isOver() const {
  return this->gameOver;
}

void Game::onRestart(const Runnable&& runnable) {
  this->restart = runnable;
}

void Game::onLevelUp(const Runnable&& runnable) {
  this->levelUp = runnable;
}

void Game::addScore(const int& value) {
  PlaySound(this->scoreFx);
  this->score += value;

  if (this->score % 500 == 0) {
    PlaySound(this->levelUpFx);
    this->levelUp();
  }
}

void Game::stop() {
  this->gameOver = true;
}

void Game::update() {
  if (this->gameOver && IsKeyPressed(KEY_SPACE)) {
    this->score = 0;
    this->gameOver = false;
    this->restart();
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

void Game::drawScore() const {
  const auto scoreText = TextFormat("Score: %i", this->score);
  const auto size = 30;
  const auto x = Grid::SIZE - MeasureText(scoreText, size) - 10;

  DrawText(scoreText, x, 10, size, Theme::GREEN_50);
}
