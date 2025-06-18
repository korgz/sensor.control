#define REMOTE_PIN 2   // Input from switch, on PIN 2
#define MOTOR_IN1 8    // Motor direction control
#define MOTOR_IN2 9

bool doorOpen = false;
bool lastButtonState = LOW;
unsigned long debounceTime = 0;

void setup() {
  pinMode(REMOTE_PIN, INPUT);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);

  Serial.begin(9600);
  stopMotor();
}

void loop() {
  bool currentButton = digitalRead(REMOTE_PIN);

  if (currentButton == HIGH && lastButtonState == LOW && millis() - debounceTime > 500) {
    debounceTime = millis();
    Serial.println(doorOpen ? "Closing door..." : "Opening door...");

    if (doorOpen) {
      closeDoor();
    } else {
      openDoor();
    }

    doorOpen = !doorOpen;
  }

  lastButtonState = currentButton;
}

// Simulated open/close sequence
void openDoor() {
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
  delay(5000); // Time to open
  stopMotor();
}

void closeDoor() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, HIGH);
  delay(5000); // Time to close
  stopMotor();
}

void stopMotor() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
}