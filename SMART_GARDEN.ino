int moisture_sensor = A0;
int motor = A1;
int relay = 13;
int buzzer = 8;
int moisture_value = 0;
int motor_value;
float motor_voltage = 0;

void setup() {
  Serial.begin(9600);
  pinMode(moisture_sensor, INPUT);
  pinMode(motor, INPUT);
  pinMode(relay , OUTPUT);
  pinMode(buzzer , OUTPUT);
}

void loop() {
  moisture_value = analogRead(moisture_sensor);
  Serial.print("MOISTURE VALUE= ");
  Serial.print(moisture_value);
  Serial.println();
  delay(100);
  if (moisture_value >= 500)
  {
    digitalWrite(relay, LOW);
    delay(100);
    motor_value = analogRead(motor);
    motor_voltage = (5. / 1023.) * motor_value;
    Serial.print("   MOTOR VOLTAGE= ");
    Serial.print(motor_voltage);
    Serial.println();
    if (motor_voltage <= 0.08)
    {
      digitalWrite(relay, HIGH);
      delay(100);
      digitalWrite(buzzer, HIGH);
      delay(1000);
      digitalWrite(buzzer, LOW);
    }
  }
  if (moisture_value <= 300)
  {
    digitalWrite(relay, HIGH);
    delay(100);
  }
  delay(180000);
}
