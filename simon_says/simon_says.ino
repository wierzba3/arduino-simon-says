#include <StandardCplusplus.h>
#include "game.h"

/*
 * TODO
 */

using namespace std;

const int bluePin = 2;
const int yellowPin = 3;
const int greenPin = 4;
const int redPin = 5;

//The red LED indicating user-input failure
const int failPin = 6;
//The green LED indicating user-input success
const int successPin = 7;

const int redButton = 13;
const int greenButton = 12;
const int yellowButton = 11;
const int blueButton = 10;

//temporary variables to hold the state of the button presses
int redState, greenState, yellowState, blueState;

enum Mode
{
  USER_INPUT,
  DISPLAY_SERIES
};
Mode mode;


Game game;

void setup() 
{
  Serial.begin(9600);
  Serial.println("Begin1");
  
  pinMode(bluePin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(failPin, OUTPUT);
  pinMode(successPin, OUTPUT);
  pinMode(redButton, INPUT);

  digitalWrite(bluePin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, LOW);
  digitalWrite(failPin, LOW);
  digitalWrite(successPin, LOW);
  digitalWrite(redButton, HIGH);

  mode = DISPLAY_SERIES;
}

void gameOver()
{
  Serial.println("Game over!");
  game.resetGame();
  //blink the fail light 5 times
  for(int i = 0; i < 5; i++)
  {
    digitalWrite(failPin, HIGH);
    delay(200);
    digitalWrite(failPin, LOW);
    delay(200);
  }
  setAllLightsOn(false);
  mode = DISPLAY_SERIES;
}
void displaySuccess()
{
  //blink the success light 5 times
  for(int i = 0; i < 5; i++)
  {
    digitalWrite(successPin, HIGH);
    delay(200);
    digitalWrite(successPin, LOW);
    delay(200);
  }
}

void getUserInput()
{ 
  redState = digitalRead(redButton);
  greenState = digitalRead(greenButton);
  yellowState = digitalRead(yellowButton);
  blueState = digitalRead(blueButton);

  if(redState == HIGH)
  {
    Serial.println("Red pressed");
    //light the LED to indicate to the user the button is pressed
    digitalWrite(redPin, HIGH);
    //wait for the button to be depressed
    while(digitalRead(redButton) == HIGH) { delay(10); } 
    //turn the LED light off after the user stops pressing the button
    digitalWrite(redPin, LOW);
    
    //if the insert function returns false, this light that was pressed is incorrect
    if(!game.insertInput(RED))
    {
      gameOver();
      return;
    }

  }
  else if(greenState == HIGH)
  {
    Serial.println("Green pressed");
    //light the LED to indicate to the user the button is pressed
    digitalWrite(greenPin, HIGH);
    //wait for the button to be depressed
    while(digitalRead(greenButton) == HIGH) { delay(10); } 
    //turn the LED light off after the user stops pressing the button
    digitalWrite(greenPin, LOW);
    
    //if the insert function returns false, this light that was pressed is incorrect
    if(!game.insertInput(GREEN))
    {
      gameOver();
      return;
    }

  }
  else if(yellowState == HIGH)
  {
    Serial.println("Yellow pressed");
    //light the LED to indicate to the user the button is pressed
    digitalWrite(yellowPin, HIGH);
    //wait for the button to be depressed
    while(digitalRead(yellowButton) == HIGH) { delay(10); } 
    //turn the LED light off after the user stops pressing the button
    digitalWrite(yellowPin, LOW);
    
    //if the insert function returns false, this light that was pressed is incorrect
    if(!game.insertInput(YELLOW))
    {
      gameOver();
      return;
    }

  }
  else if(blueState == HIGH)
  {
    Serial.println("Blue pressed");
    
    //light the LED to indicate to the user the button is pressed
    digitalWrite(bluePin, HIGH);
    //wait for the button to be depressed
    while(digitalRead(blueButton) == HIGH) { delay(10); } 
    //turn the LED light off after the user stops pressing the button
    digitalWrite(bluePin, LOW);
    
    //if the insert function returns false, this light that was pressed is incorrect
    if(!game.insertInput(BLUE))
    {
      gameOver();
      return;
    }

  }

  //check if the input matches the current light series, if it does, display the success lights and switch to the next level
  if(game.isInputCorrect())
  {
    Serial.println("The input was correct!");
    displaySuccess();
    mode = DISPLAY_SERIES;
    delay(500);
  }
  
  delay(1);
}

/**
 * Display the randomly genereated series of lights (after adding one new random light to the series)
 */
void displayColorSeries()
{
  Serial.println("Display...");

  game.nextLevel();
  vector<Button> lightSeries = game.getLightSeries();
  
  for(int i = 0; i < lightSeries.size(); i++)
  {
    Serial.print("Light up: ");
    Serial.println(Game::buttonToString(lightSeries[i]));
    switch(lightSeries[i])
    {
      case RED: 
        digitalWrite(redPin, HIGH);
        break;
      case GREEN: 
        digitalWrite(greenPin, HIGH);
        break;
      case YELLOW: 
        digitalWrite(yellowPin, HIGH);
        break;
      case BLUE: 
        digitalWrite(bluePin, HIGH);
        break;
    }
    delay(600);
    setAllLightsOn(false);
    delay(600);
    
  }

  Serial.println("User input...");
  mode = USER_INPUT; 
  game.beginInput();
  delay(1);
}

void setAllLightsOn(bool on)
{
  digitalWrite(bluePin, on ? HIGH : LOW);
  digitalWrite(yellowPin, on ? HIGH : LOW);
  digitalWrite(greenPin, on ? HIGH : LOW);
  digitalWrite(redPin, on ? HIGH : LOW);
}


void loop() 
{
  switch(mode)
  {
    case USER_INPUT: 
      getUserInput();
      break;
    case DISPLAY_SERIES: 
      displayColorSeries();
      break;
  }

}

