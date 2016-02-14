#include <vector>

using namespace std;

enum Button
{
  RED,
  GREEN,
  YELLOW,
  BLUE,
  DUMMY //for generating random Button via rand()
};


class Game
{


  private:

    //The current sequence of user input button presses
    vector<Button> buttonInputSeries;

    //The current state of the game, the correct sequence of button presses
    vector<Button> lightSeries;

  public:

    Game()
    {

    }

    ~Game()
    {

    }

    /**
     * Advance the game to the "next level" i.e. add a random color to the series
     */
    void nextLevel();

    vector<Button> getLightSeries()
    {
      return this->lightSeries;
    }



};





