#define MOTOR_L 6
#define MOTOR_R 5

void setup() {
	pinMode(MOTOR_L, OUTPUT);
	pinMode(MOTOR_R, OUTPUT);
	digitalWrite(MOTOR_L, LOW);
	digitalWrite(MOTOR_R, LOW);
	
	Serial.begin(9600);
}

void loop() {
	if(Serial.available() > 0) {
		int incomingByte = Serial.read();
		if(incomingByte == 'H') {
			digitalWrite(MOTOR_L, HIGH);
			digitalWrite(MOTOR_R, HIGH);
		}
		else if(incomingByte == 'L') {
			digitalWrite(MOTOR_L, LOW);
			digitalWrite(MOTOR_R, LOW);
		}
	}
}
