

const int bluePin = 2;
const int yellowPin = 3;
const int greenPin = 4;
const int redPin = 5;


void setup() 
{
  Serial.begin(9600);
  pinMode(bluePin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);


}

void loop() 
{
  digitalWrite(bluePin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, LOW);

  digitalWrite(bluePin, HIGH);
  delay(500);
  digitalWrite(bluePin, LOW);
  digitalWrite(yellowPin, HIGH);
  delay(500);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(500);
  digitalWrite(greenPin, LOW);
  digitalWrite(redPin, HIGH);
  delay(500);

}
