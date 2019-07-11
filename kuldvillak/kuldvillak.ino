const byte RGB[] = {9, 5, 11};
const byte button[] = {12, 10, 8, 6};
const byte colors[4][3] = {
  {0,0, 255},
  {255, 0, 0},
  {255, 255, 0},
  {255, 255, 255}
};
const byte dead[] = {0, 0, 0};

void setRGB(byte arr[]) {
  for (byte i = 0; i < 3; i++) {
    analogWrite(RGB[i], 255 - arr[i]);
  }
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  detachInterrupt(digitalPinToInterrupt(6));
  for (byte i = 0; i < 4; i++) {
    setRGB(colors[i]);
    delay(500);
    setRGB(dead);
    delay(100);
  }
  setRGB(dead);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (byte i = 0; i < 4; i++) {
    if (digitalRead(button[i])) {
      setRGB(colors[i]);
      while (digitalRead(button[i]));
    }
  }
  setRGB(dead);
}
