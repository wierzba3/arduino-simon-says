#include <vector>
#include <string>
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
    /**
     * Clear the buttonInputSeries vector to record a new series of user input
     */
    void beginInput();
    
    /**
     * Insert a newly pressed button into the buttonInputSeries vector
     * 
     * returns True if it was a correct input, false if it was not
     */
    bool insertInput(Button pressed);

    /**
     * Compare the user input series to the light series
     */
    bool isInputCorrect();

    /**
     * Reset the game
     */
    void resetGame();

    vector<Button> getLightSeries()
    {
      return this->lightSeries;
    }
    vector<Button> getButtonInputSeries()
    {
      return this->buttonInputSeries;
    }

    static char* buttonToString(Button btn)
    {
      switch(btn)
      {
        case RED: return "RED";
        case GREEN: return "GREEN";
        case YELLOW: return "YELLOW";
        case BLUE: return "BLUE";
      }
      return "null";
    }

};





