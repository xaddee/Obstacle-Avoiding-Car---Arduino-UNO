const int leftForward = 5;
const int leftBackward = 4;
const int rightForward = 2;
const int rightBackward = 3;

const int echoPinForwardSensor = 10;
const int trigPinForwardSensor = 9;
const int echoPinLeftSensor = 6;
const int trigPinLeftSensor = 11;

int fastSpeed = 205, balanceValue = 50;
int distanceForwardSensor, distanceLeftSensor, durationLeftSensor, durationForwardSensor, distanceWhenStops = 35, distanceToGoBackwards = 15;

bool stopped = false;

uint32_t durationToTurn = 1200;

void setup () 
{
  pinMode(leftForward, OUTPUT);
  pinMode(leftBackward, OUTPUT);
  pinMode(rightForward, OUTPUT);
  pinMode(rightBackward, OUTPUT);

  pinMode(trigPinForwardSensor, OUTPUT);
  pinMode(echoPinForwardSensor, INPUT);
  pinMode(trigPinLeftSensor, OUTPUT);
  pinMode(echoPinLeftSensor, INPUT);

  Serial.begin(9600);
}

void loop () 
{
  //Calculates the distance given by the front sensonr
  digitalWrite(trigPinForwardSensor, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPinForwardSensor, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinForwardSensor, LOW);

  durationForwardSensor = pulseIn(echoPinForwardSensor, HIGH);
  distanceForwardSensor = durationForwardSensor * 0.034 / 2; 

  //Calculates the distance given by the left side sensor
  digitalWrite(trigPinLeftSensor, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPinLeftSensor, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinLeftSensor, LOW);

  durationLeftSensor = pulseIn(echoPinLeftSensor, HIGH);
  distanceLeftSensor = durationLeftSensor * 0.034 / 2;

  if (distanceForwardSensor <= distanceToGoBackwards && distanceForwardSensor > 0)
  {
    goBackwards();
  }
  else if (distanceForwardSensor > distanceWhenStops) 
  {
    goForward();
  }
  else if (distanceForwardSensor <= distanceWhenStops && stopped == false)
  {
    stopCar();
    delay(300);
    stopped = true;
  }
  if (stopped ==  true)
  {
    if (distanceLeftSensor <= distanceWhenStops && distanceLeftSensor > 0)
    {
      //the following for moves the car for the amount of miliseconds given by the 'durationToTurn' variable
      for (uint32_t timeStart = millis(); (millis() - timeStart) < durationToTurn; )
      {
        turnRight();  
      }
    }
    else
    {
      for (uint32_t timeStart = millis(); (millis() - timeStart) < durationToTurn; )
      {
        turnLeft();  
      }
    }
    
    stopped = false;
  }
}

void goForward ()
{
  analogWrite(leftForward, fastSpeed +  balanceValue);
  digitalWrite(leftBackward, LOW);
  analogWrite(rightForward, fastSpeed);
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
  digitalWrite(rightForward, fastSpeed);
  digitalWrite(rightBackward, LOW);
}
void turnRight ()
{
  digitalWrite(leftForward, fastSpeed);
  digitalWrite(leftBackward, LOW);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, LOW);
}

void goBackwards ()
{
  digitalWrite(leftForward, LOW);
  digitalWrite(leftBackward, fastSpeed);
  digitalWrite(rightForward, LOW);
  digitalWrite(rightBackward, fastSpeed);
}
