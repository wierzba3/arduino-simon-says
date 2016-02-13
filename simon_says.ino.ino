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
  redState = digitalRead(redButton);
  greenState = digitalRead(greenButton);
  yellowState = digitalRead(yellowButton);
  blueState = digitalRead(blueButton);
  
  if(redState == HIGH) Serial.println("Red pressed");
  if(greenState == HIGH) Serial.println("Green pressed");
  if(yellowState == HIGH) Serial.println("Yellow pressed");
  if(blueState == HIGH) Serial.println("Blue pressed");
  delay(100);
}

void displayColorSeries()
{
  Serial.print("Display...");
  //TODO display the randomly generated series of lights
  mode = USER_INPUT;
  delay(1);
}
