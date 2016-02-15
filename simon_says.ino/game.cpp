#include "game.h"

void Game::nextLevel()
{
  Button randomButton = static_cast<Button>(rand() % DUMMY);
  lightSeries.push_back(randomButton);
}

void Game::beginInput()
{
  buttonInputSeries.clear();
}

bool Game::insertInput(Button pressed)
{
  buttonInputSeries.push_back(pressed);
  int i = buttonInputSeries.size() - 1;
  return (buttonInputSeries[i] == lightSeries[i]);
}

void Game::resetGame()
{
  buttonInputSeries.clear();
  lightSeries.clear();
}

bool Game::isInputCorrect()
{
  if(buttonInputSeries.size() != lightSeries.size()) return false;
  for(int i = 0; i < lightSeries.size(); i++)
  {
    if(buttonInputSeries[i] != lightSeries[i]) return false;
  }
  return true;
}

