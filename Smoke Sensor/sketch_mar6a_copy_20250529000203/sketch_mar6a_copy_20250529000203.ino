int red_LED_PIN = 7; // Red LED connected to pin 7
int green_LED_PIN = 6; // Green LED connected to pin 6
int buzzer = 5; // Buzzer connected to pin 5
int smoke_detector = A0; // MQ-2 sensor connected to analog pin A0
int safety_lim = 150; // Smoke density safe limit set to 100

void setup() {
  pinMode(red_LED_PIN, OUTPUT);
  pinMode(green_LED_PIN, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(smoke_detector, INPUT);
  Serial.begin(9600); // Start serial communication
}

void loop() {
  int sensor_read = analogRead(smoke_detector);
  Serial.print("Smoke Density: ");
  Serial.println(sensor_read);
  
  if (sensor_read > safety_lim) {
    digitalWrite(red_LED_PIN, HIGH); // Turn on red LED
    digitalWrite(green_LED_PIN, LOW); // Turn off green LED
    tone(buzzer, 9999, 5000); // Activate buzzer for 500ms
    delay(500); // Keep the buzzer ON for a while
    noTone(buzzer); // Turn off buzzer
  } else {
    digitalWrite(green_LED_PIN, HIGH); // Turn on green LED
    digitalWrite(red_LED_PIN, LOW); // Turn off red LED
    noTone(buzzer); // Ensure buzzer is off
  }
  delay(50);
}
