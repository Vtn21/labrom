#define MOTOR_L 6
#define MOTOR_R 5

void setup() {
	pinMode(MOTOR_L, OUTPUT);
	pinMode(MOTOR_R, OUTPUT);
	digitalWrite(MOTOR_L, LOW);
	digitalWrite(MOTOR_R, LOW);
}

void loop() {
	analogWrite(MOTOR_L, 255);
	analogWrite(MOTOR_R, 255);
	delay(500);
	digitalWrite(MOTOR_L, LOW);
	digitalWrite(MOTOR_R, LOW);
        delay(500);
}
