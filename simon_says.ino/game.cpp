#include "game.h"

void Game::nextLevel()
{
  Button randomButton = static_cast<Button>(rand() % DUMMY);
  lightSeries.push_back(randomButton);
}

