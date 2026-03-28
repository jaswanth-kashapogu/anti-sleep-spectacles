const int EYE_BLINK_SENSOR_PIN = 2; // Connect the eye blink sensor output to digital pin 2
const int BUZZER_PIN = 8;            // Buzzer pin connected to digital pin 8

bool buzzerState = false;
bool blinkDetected = false;
unsigned long blinkStartTime = 0;

void setup() {
  pinMode(EYE_BLINK_SENSOR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read the state of the eye blink sensor
  bool currentBlinkState = digitalRead(EYE_BLINK_SENSOR_PIN) == HIGH;

  if (currentBlinkState && !blinkDetected) {
    // Start the timer if blink is detected for the first time
    blinkDetected = true;
    blinkStartTime = millis();
    Serial.println("Blink detected");
  } else if (!currentBlinkState && blinkDetected) {
    // Reset the timer if the blink is no longer detected
    blinkDetected = false;
    blinkStartTime = 0;
    Serial.println("Blink stopped");
  }

  // If blink has been continuously detected for more than 3 seconds, turn on the buzzer
  if (blinkDetected && millis() - blinkStartTime > 2000) {
    if (!buzzerState) {
      buzzerState = true;
      digitalWrite(BUZZER_PIN, HIGH);
      Serial.println("Buzzer turned on");
    }
  } else {
    // If blink detection stops or duration is less than 2 seconds, turn off the buzzer
    if (buzzerState) {
      buzzerState = false;
      digitalWrite(BUZZER_PIN, LOW);
      Serial.println("Buzzer turned off");
    }
  }
}
