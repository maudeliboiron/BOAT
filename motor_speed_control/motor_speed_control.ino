//Setup for motor connections
const int in1 = 8;
const int in2 = 9;
const int enable = 10;

// Setup for direction
const int STOP = 0;
const int LEFT = 1;
const int RIGHT = 2;

void setup() {
  // Setup pin modes for motor
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enable, OUTPUT);

  // Setup initial values
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void loop() {
  for(int dir = STOP; dir <= RIGHT; dir++) {
    if(dir == LEFT) {
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
    } else if (dir == RIGHT) {
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
    } else if (dir == STOP) {
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
    }
    for (int i = 0; i <= 255; i++) {
      analogWrite(enable, i);
      delay(100);
    }
  }
}
