const uint8_t bobTheButton = 12;
const uint8_t bobTheLED = 10;

uint8_t lastClick = 0;
bool lastLED = 0;

void setup() {
  pinMode(bobTheButton,INPUT);
  pinMode(bobTheLED,OUTPUT);
}

void loop() {
  bool buttonState = digitalRead(bobTheButton);

  if (lastClick != buttonState) {
    lastClick = buttonState;
    if (buttonState) lastLED = !lastLED;
  }
  
  if (lastClick < buttonState) {
    lastClick = 1;
    lastLED = (lastLED + 1) % 2;
  }
  if (lastClick > buttonState) {
    lastClick = 0;
  }
  if (lastLED == 0) {
    digitalWrite(bobTheLED, LOW);
  } else {
    digitalWrite(bobTheLED,HIGH);
  }
}