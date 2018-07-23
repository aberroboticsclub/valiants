/*
 * Software Class written by Tomos Fearn
 * For use by Aberystwyth Robotics Club Valiants
 * tf10@outlook.com
*/
#include<valiant.h>

Valiant::Valiant(){}

Valiant::~Valiant(){}

/*
 * Setup pinouts and serial
 * connections for Valiant
*/
void Valiant::setup(HardwareSerial * s) {
	serial = s;
	serial->begin(baudRate);
//	this->turret.attach(turretPin);
	pinMode(leftMotorForward, OUTPUT);
	pinMode(leftMotorReverse, OUTPUT);
	pinMode(rightMotorForward, OUTPUT);
	pinMode(rightMotorReverse, OUTPUT);
	#ifdef DEBUG_SETUP
	if (DEBUG_SETUP) {
		serial->println("finished setup");
	}
	#endif
}



/*
 * Valiant Movement functions
 * fordwards() full speed on/off
 * forwards(speed) with speed parameters
*/
void Valiant::forwards() {
	#ifdef DEBUG_MOTORS
	if (DEBUG_MOTORS) {
		serial->println("motors forwards");
	}
	#endif
	digitalWrite(leftMotorForward, HIGH);
	digitalWrite(leftMotorReverse, LOW);
	digitalWrite(rightMotorForward, HIGH);
	digitalWrite(rightMotorReverse, LOW);
}

void Valiant::reverse() {
	#ifdef DEBUG_MOTORS
	if (DEBUG_MOTORS) {
		serial->println("motors reverse");
	}
	#endif
	digitalWrite(leftMotorForward, LOW);
	digitalWrite(leftMotorReverse, HIGH);
	digitalWrite(rightMotorForward, LOW);
	digitalWrite(rightMotorReverse, HIGH);
}

void Valiant::left() {
	#ifdef DEBUG_MOTORS
	if (DEBUG_MOTORS) {
		serial->println("motors left");
	}
	#endif
	digitalWrite(leftMotorForward, LOW);
	digitalWrite(leftMotorReverse, HIGH);
	digitalWrite(rightMotorForward, HIGH);
	digitalWrite(rightMotorReverse, LOW);
}

void Valiant::right() {
	#ifdef DEBUG_MOTORS
	if (DEBUG_MOTORS) {
		serial->println("motors right");
	}
	#endif
	digitalWrite(leftMotorForward, HIGH);
	digitalWrite(leftMotorReverse, LOW);
	digitalWrite(rightMotorForward, LOW);
	digitalWrite(rightMotorReverse, HIGH);
}

void Valiant::halt() {
	#ifdef DEBUG_MOTORS
	if (DEBUG_MOTORS) {
		serial->println("motors stopped");
	}
	#endif
	digitalWrite(leftMotorForward, LOW);
	digitalWrite(leftMotorReverse, LOW);
	digitalWrite(rightMotorForward, LOW);
	digitalWrite(rightMotorReverse, LOW);
}


void Valiant::forwards(byte speed) {
	#ifdef DEBUG_MOTORS
	if (DEBUG_MOTORS) {
		serial->print("motors forwards at ");
		serial->println(speed);
	}
	#endif
	analogWrite(leftMotorForward, speed);
	analogWrite(leftMotorReverse, 0);
	analogWrite(rightMotorForward, speed);
	analogWrite(rightMotorReverse, 0);
}

void Valiant::reverse(byte speed) {
	#ifdef DEBUG_MOTORS
	if (DEBUG_MOTORS) {
		serial->print("motors reverse at ");
		serial->println(speed);
	}
	#endif
	analogWrite(leftMotorForward, 0);
	analogWrite(leftMotorReverse, speed);
	analogWrite(rightMotorForward, 0);
	analogWrite(rightMotorReverse, speed);
}

void Valiant::left(byte speed) {
	#ifdef DEBUG_MOTORS
	if (DEBUG_MOTORS) {
		serial->print("motors left at ");
		serial->println(speed);
	}
	#endif
	analogWrite(leftMotorForward, 0);
	analogWrite(leftMotorReverse, speed);
	analogWrite(rightMotorForward, speed);
	analogWrite(rightMotorReverse, 0);
}

void Valiant::right(byte speed) {
	#ifdef DEBUG_MOTORS
	if (DEBUG_MOTORS) {
		serial->print("motors right at ");
		serial->println(speed);
	}
	#endif
	analogWrite(leftMotorForward, speed);
	analogWrite(leftMotorReverse, 0);
	analogWrite(rightMotorForward, 0);
	analogWrite(rightMotorReverse, speed);
}
