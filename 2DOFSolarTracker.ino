#include <Servo.h>
Servo Vservo;
int vertical = 90;

#include <Stepper.h>
int stepsPerRevolution = 32;
Stepper Hstepper(stepsPerRevolution, 8, 10, 9, 11);

int deadband = 50; /* An uncertainty for analog readings from the photoresistors as they fluctuate between a certain value based on the location of the light source */
int right = A0;
int left = A1;
int r = 0;
int l = 0;
int maxintensity = 0;
int intensity = 0;
int rotation = 0;
int deadzone = 0; /* Used as a detection for whether the light source is fixed or moving */
boolean search = false;

void setup()
{
  Serial.begin(9600);
  Vservo.attach(6);
  Vservo.write(vertical);
}

void loop()
{
  delay(50);
  r = analogRead(right);
  l = analogRead(left);

  if (r > l + deadband)
  {
    Hstepper.setSpeed(400);
    Hstepper.step(20);
    Serial.print("Searching: ");
    data();
    deadzone = 0; /* If light source is not held in place, the solar tracker is moving horizontally */
    search = true;
  }

  if (l > r + deadband)
  {
    Hstepper.setSpeed(400);
    Hstepper.step(-20);
    Serial.print("Searching: ");
    data();
    deadzone = 0; /* If light source is not held in place, the solar tracker is moving horizontally */
    search = true;
  }

  if (search == true && r < l + deadband && l < r + deadband)
  {
    deadzone++;
    Serial.print("Deadzone: ");
    Serial.println(deadzone);
    if (deadzone > 20) /* If light source is held in place for 21 iterations within a certain range (deadband) the vertical sweep can be performed */
    {
      Serial.println("Found");
      verticalsweep();
      search = false;
      deadzone = 0;
    }
  }
}

void data()
{
  Serial.print("r = ");
  Serial.print(r);
  Serial.print(", l = ");
  Serial.println(l);
}

int verticalsweep()
{
  maxintensity = 0;
  for (vertical = 110; vertical >= 70; vertical = vertical - 1)
  {
    Vservo.write(vertical);
    intensity = (analogRead(right) + analogRead(left)) / 2;
    if (maxintensity < intensity)
    {
      maxintensity = intensity;
      rotation = vertical;
    }
    delay(25);
  }
  Vservo.write(rotation);
  delay(100);
}
