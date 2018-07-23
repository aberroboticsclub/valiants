/*
 * Software Class written by Tomos Fearn
 * For use by Aberystwyth Robotics Club Valiants
 * tf10@outlook.com
*/
#ifndef VALIANT_H
#define VALIANT_H
#include <Arduino.h>
#include <HardwareSerial.h>
//#include <Servo.h>

class Valiant
{
public:

	#define DEBUG_SETUP true
	#define DEBUG_LIBRARY true
	#define DEBUG_MOTORS true

	//variables containing pins for motor controller
	const byte leftMotorForward = 10;
	const byte leftMotorReverse = 11;
	const byte rightMotorForward = 9;
	const byte rightMotorReverse = 6;

	//variables for infrared sensors
	const byte leftInfrared = A4;
	const byte rightInfrared = A5;

	//variables for ultrasonic sensors
	const byte ultrasonicTrigger = 7;
	const byte ultrasonicEcho = 8;

	//variables for encoders
	const byte leftEncoderReceiver = 2;
	const byte rightEncoderReceiver = 3;
	const byte leftEncoderTransmitter = A1;
	const byte rightEncoderTransmitter = A2;

	//usb serial connection parameters
	const int baudRate = 9600;
	HardwareSerial * serial;

	//variables for turret servo
	//const byte turretPin = 12;
	//Servo turret;

	Valiant();
	~Valiant();

	void setup(HardwareSerial * s);

	void turretLeft();
	void turretForwards();
	void turretRight();
	void turretMove(byte degree);

	void forwards();
	void forwards(byte speed);
	void reverse();
	void reverse(byte speed);
	void left();
	void left(byte speed);
	void right();
	void right(byte speed);
	void halt();


private:
protected:
};

#endif
