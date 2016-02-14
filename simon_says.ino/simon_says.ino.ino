#include <StandardCplusplus.h>

#include "game.h"

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



void loop() 
{
  switch(mode)
  {
    case USER_INPUT: getUserInput();
    case DISPLAY_SERIES: displayColorSeries();
  }

}

void getUserInput()
{
  Serial.println("User input...");
  redState = digitalRead(redButton);
  greenState = digitalRead(greenButton);
  yellowState = digitalRead(yellowButton);
  blueState = digitalRead(blueButton);
  
  if(redState == HIGH) Serial.println("Red pressed");
  if(greenState == HIGH) Serial.println("Green pressed");
  if(yellowState == HIGH) Serial.println("Yellow pressed");
  if(blueState == HIGH) Serial.println("Blue pressed");

  //for now, lets assume the input is correct, light success button, and chnage state to DISPLAY_SERIES;

  //blink the success light 5 times
  for(int i = 0; i < 5; i++)
  {
    digitalWrite(successPin, HIGH);
    delay(200);
    digitalWrite(successPin, LOW);
    delay(200);
  }
  
  
  delay(1);
}

void displayColorSeries()
{
  Serial.print("Display...");
  //TODO display the randomly generated series of lights

  game.nextLevel();
  vector<Button> lightSeries = game.getLightSeries();

  Serial.print("Randomly generated series: ");
  for(int i = 0; i < lightSeries.size(); i++)
  {
    Serial.print(lightSeries[i]);
    Serial.print(", ");
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
    digitalWrite(bluePin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, LOW);
    delay(600);
  }
  Serial.println("");
  


  
  mode = USER_INPUT; 
  delay(1);
}



