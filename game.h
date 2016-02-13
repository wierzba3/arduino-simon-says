#include <vector>

using namespace std;

enum Button
{
  RED,
  GREEN,
  YELLOW,
  BLUE
};

class Game
{

  public:

    Game()
    {

    }

    ~Game()
    {

    }


  private:

    //The current sequence of user input button presses
    vector<Button> input;

    //The current state of the game, the correct sequence of button presses
    vector<Button> correct;

};





