const int leftForward = 2;
const int leftBackward = 3;
const int rightForward = 5;
const int rightBackward = 4;

const int echoPin = 10;
const int trigPin = 9;

int fastSpeed = 130, slowSpeed = 50, balanceValue = 125;
int distance, duration, distanceWhenStops = 30, randomNumber;

bool stopped = false;

uint32_t durationToTurn = 300;

void setup() {
  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);
  pinMode(rightForward, OUTPUT);
  pinMode(rightBackward, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //randomSeed(analogRead(0));
  //Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2; 

  //Serial.print("Distanta: ");
  //Serial.println(distance);

  if (distance > distanceWhenStops) 
  {
    goForward();
  }
  else if (distance <= distanceWhenStops && stopped == false)
  {
    stopCar();
    delay(500);
    stopped = true;
  }
  if (stopped ==  true)
  {
    for (uint32_t timeStart = millis(); (millis() - timeStart) < durationToTurn; )
    {
      turnLeft();  
    }
    stopped = false;
  }
}

void goForward ()
{
  analogWrite(leftForward, fastSpeed);
  digitalWrite(leftBackward, LOW);
  analogWrite(rightForward, fastSpeed + balanceValue);
  digitalWrite(rightBackward, LOW);
}

void stopCar ()
{
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, LOW);
}

void turnLeft ()
{
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, fastSpeed + balanceValue);
  digitalWrite(rightBackward, LOW);
}
void turnRight ()
{
  digitalWrite(leftForward, fastSpeed + balanceValue);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, LOW);
  
}
