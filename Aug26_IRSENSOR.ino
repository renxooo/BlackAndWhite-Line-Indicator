int irSensorRight = 2;
int irSensorLeft = 8;
int buzz = 10;

void setup() {
  Serial.begin(9600);
  pinMode(irSensorRight, INPUT);
  pinMode(irSensorLeft, INPUT);
  pinMode(buzz, OUTPUT);
}

void loop() {
  int sensorStatusLeft = digitalRead(irSensorLeft);
  int sensorStatusRight = digitalRead(irSensorRight);

  int colorState;
  int printed = 0;

  if (sensorStatusLeft == 1 && sensorStatusRight == 1) {
    noTone(buzz);
    colorState = 1; // WHITE LINE
  }
  else if (sensorStatusLeft == 0 && sensorStatusRight == 0) {
    noTone(buzz);
    colorState = 2; // BLACK LINE
  }

  switch(colorState) {
    case 1:
      Serial.println(colorState);
      //delay(3000);
      if (sensorStatusLeft == 0 && sensorStatusRight == 1 && colorState == 1) {
        tone(buzz, 1000);
        Serial.println("Left on White");
        delay(500);
      }
      else if (sensorStatusLeft == 1 && sensorStatusRight == 0 && colorState == 1) {
        tone(buzz, 1000);
        Serial.println("Right on White");
        delay(500);
      }
    case 2:
      Serial.println(colorState);
      //delay(3000);
      if (sensorStatusLeft == 1 && sensorStatusRight == 0 && colorState == 2) {
        tone(buzz, 1000);
        Serial.println("Left on Black");
        delay(500);
      }
      else if (sensorStatusLeft == 0 && sensorStatusRight == 1 && colorState == 2) {
        tone(buzz, 1000);
        Serial.println("Right on Black");
        delay(500);
      }
  }
}
