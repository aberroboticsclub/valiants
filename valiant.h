/*
 * V1.0
 * Software Class written by Tomos Fearn
 * For use by Aberystwyth Robotics Club Valiants
 * tf10@outlook.com
*/
#ifndef VALIANT_H
#define VALIANT_H
#include <Arduino.h>
#include <HardwareSerial.h>
#include <Servo.h>

// Shouldn't need to change these values unless you have a specific need to do so.
	#define MAX_SENSOR_DISTANCE 500 // Maximum sensor distance can be as high as 500cm, no reason to wait for ping longer than sound takes to travel this distance and back. Default=500
	#define US_ROUNDTRIP_CM 57      // Microseconds (uS) it takes sound to travel round-trip 1cm (2cm total), uses integer to save compiled code space. Default=57
	#define US_ROUNDTRIP_IN 146     // Microseconds (uS) it takes sound to travel round-trip 1 inch (2 inches total), uses integer to save compiled code space. Defalult=146
	#define ONE_PIN_ENABLED true    // Set to "false" to disable one pin mode which saves around 14-26 bytes of binary size. Default=true
	#define ROUNDING_ENABLED false  // Set to "true" to enable distance rounding which also adds 64 bytes to binary size. Default=false
	#define URM37_ENABLED false     // Set to "true" to enable support for the URM37 sensor in PWM mode. Default=false
	#define TIMER_ENABLED false      // Set to "false" to disable the timer ISR (if getting "__vector_7" compile errors set this to false). Default=true

	// Probably shouldn't change these values unless you really know what you're doing.
	#define NO_ECHO 0               // Value returned if there's no ping echo within the specified MAX_SENSOR_DISTANCE or max_cm_distance. Default=0
	#define MAX_SENSOR_DELAY 5800   // Maximum uS it takes for sensor to start the ping. Default=5800
	#define ECHO_TIMER_FREQ 24      // Frequency to check for a ping echo (every 24uS is about 0.4cm accuracy). Default=24
	#define PING_ULTRASONIC_MEDIAN_DELAY 29000 // Microsecond delay between pings in the ping_median method. Default=29000
	#define PING_ULTRASONIC_OVERHEAD 5         // Ping overhead in microseconds (uS). Default=5
	#define PING_ULTRASONIC_TIMER_OVERHEAD 13  // Ping timer overhead in microseconds (uS). Default=13
	#if URM37_ENABLED == true
		#undef  US_ROUNDTRIP_CM
		#undef  US_ROUNDTRIP_IN
		#define US_ROUNDTRIP_CM 50  // Every 50uS PWM signal is low indicates 1cm distance. Default=50
		#define US_ROUNDTRIP_IN 127 // If 50uS is 1cm, 1 inch would be 127uS (50 x 2.54 = 127). Default=127
	#endif

	// Conversion from uS to distance (round result to nearest cm or inch).
	#define NewPingConvert(echoTime, conversionFactor) (max(((unsigned int)echoTime + conversionFactor / 2) / conversionFactor, (echoTime ? 1 : 0)))

	// Detect non-AVR microcontrollers (Teensy 3.x, Arduino DUE, etc.) and don't use port registers or timer interrupts as required.
	#if (defined (__arm__) && (defined (TEENSYDUINO) || defined (PARTICLE)))
		#undef  PING_ULTRASONIC_OVERHEAD
		#define PING_ULTRASONIC_OVERHEAD 1
		#undef  PING_ULTRASONIC_TIMER_OVERHEAD
		#define PING_ULTRASONIC_TIMER_OVERHEAD 1
		#define DO_BITWISE true
	#elif !defined (__AVR__)
		#undef  PING_ULTRASONIC_OVERHEAD
		#define PING_ULTRASONIC_OVERHEAD 1
		#undef  PING_ULTRASONIC_TIMER_OVERHEAD
		#define PING_ULTRASONIC_TIMER_OVERHEAD 1
		#undef  TIMER_ENABLED
		#define TIMER_ENABLED false
		#define DO_BITWISE false
	#else
		#define DO_BITWISE true
	#endif

	// Disable the timer interrupts when using ATmega128 and all ATtiny microcontrollers.
	#if defined (__AVR_ATmega128__) || defined (__AVR_ATtiny24__) || defined (__AVR_ATtiny44__) || defined (__AVR_ATtiny84__) || defined (__AVR_ATtiny25__) || defined (__AVR_ATtiny45__) || defined (__AVR_ATtiny85__) || defined (__AVR_ATtiny261__) || defined (__AVR_ATtiny461__) || defined (__AVR_ATtiny861__) || defined (__AVR_ATtiny43U__)
		#undef  TIMER_ENABLED
		#define TIMER_ENABLED false
	#endif

	// Define timers when using ATmega8, ATmega16, ATmega32 and ATmega8535 microcontrollers.
	#if defined (__AVR_ATmega8__) || defined (__AVR_ATmega16__) || defined (__AVR_ATmega32__) || defined (__AVR_ATmega8535__)
		#define OCR2A OCR2
		#define TIMSK2 TIMSK
		#define OCIE2A OCIE2
	#endif




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

	const byte led = 13;
	const byte ldr = A0;



	//usb serial connection parameters
	const int baudRate = 9600;
	HardwareSerial * serial;

	//Musical notes to frequencies
	#define NOTE_B0  31
	#define NOTE_C1  33
	#define NOTE_CS1 35
	#define NOTE_D1  37
	#define NOTE_DS1 39
	#define NOTE_E1  41
	#define NOTE_F1  44
	#define NOTE_FS1 46
	#define NOTE_G1  49
	#define NOTE_GS1 52
	#define NOTE_A1  55
	#define NOTE_AS1 58
	#define NOTE_B1  62
	#define NOTE_C2  65
	#define NOTE_CS2 69
	#define NOTE_D2  73
	#define NOTE_DS2 78
	#define NOTE_E2  82
	#define NOTE_F2  87
	#define NOTE_FS2 93
	#define NOTE_G2  98
	#define NOTE_GS2 104
	#define NOTE_A2  110
	#define NOTE_AS2 117
	#define NOTE_B2  123
	#define NOTE_C3  131
	#define NOTE_CS3 139
	#define NOTE_D3  147
	#define NOTE_DS3 156
	#define NOTE_E3  165
	#define NOTE_F3  175
	#define NOTE_FS3 185
	#define NOTE_G3  196
	#define NOTE_GS3 208
	#define NOTE_A3  220
	#define NOTE_AS3 233
	#define NOTE_B3  247
	#define NOTE_C4  262
	#define NOTE_CS4 277
	#define NOTE_D4  294
	#define NOTE_DS4 311
	#define NOTE_E4  330
	#define NOTE_F4  349
	#define NOTE_FS4 370
	#define NOTE_G4  392
	#define NOTE_GS4 415
	#define NOTE_A4  440
	#define NOTE_AS4 466
	#define NOTE_B4  494
	#define NOTE_C5  523
	#define NOTE_CS5 554
	#define NOTE_D5  587
	#define NOTE_DS5 622
	#define NOTE_E5  659
	#define NOTE_F5  698
	#define NOTE_FS5 740
	#define NOTE_G5  784
	#define NOTE_GS5 831
	#define NOTE_A5  880
	#define NOTE_AS5 932
	#define NOTE_B5  988
	#define NOTE_C6  1047
	#define NOTE_CS6 1109
	#define NOTE_D6  1175
	#define NOTE_DS6 1245
	#define NOTE_E6  1319
	#define NOTE_F6  1397
	#define NOTE_FS6 1480
	#define NOTE_G6  1568
	#define NOTE_GS6 1661
	#define NOTE_A6  1760
	#define NOTE_AS6 1865
	#define NOTE_B6  1976
	#define NOTE_C7  2093
	#define NOTE_CS7 2217
	#define NOTE_D7  2349
	#define NOTE_DS7 2489
	#define NOTE_E7  2637
	#define NOTE_F7  2794
	#define NOTE_FS7 2960
	#define NOTE_G7  3136
	#define NOTE_GS7 3322
	#define NOTE_A7  3520
	#define NOTE_AS7 3729
	#define NOTE_B7  3951
	#define NOTE_C8  4186
	#define NOTE_CS8 4435
	#define NOTE_D8  4699
	#define NOTE_DS8 4978




	NewPing(uint8_t trigger_pin, uint8_t echo_pin, unsigned int max_cm_distance = MAX_SENSOR_DISTANCE);
			unsigned int ping_ultrasonic(unsigned int max_cm_distance = 0);
			unsigned long ping_ultrasonic_cm(unsigned int max_cm_distance = 0);
			unsigned long ping_ultrasonic_in(unsigned int max_cm_distance = 0);
			unsigned long ping_ultrasonic_median(uint8_t it = 5, unsigned int max_cm_distance = 0);
			static unsigned int convert_cm(unsigned int echoTime);
			static unsigned int convert_in(unsigned int echoTime);
	#if TIMER_ENABLED == true
			void ping_ultrasonic_timer(void (*userFunc)(void), unsigned int max_cm_distance = 0);
			boolean check_timer();
			unsigned long ping_ultrasonic_result;
			static void timer_us(unsigned int frequency, void (*userFunc)(void));
			static void timer_ms(unsigned long frequency, void (*userFunc)(void));
			static void timer_stop();
	#endif

	Valiant();
	~Valiant();
	//variables for turret servo
	const byte turretPin = 12;
	Servo turret;

	const int speaker = A3;

	void setup(HardwareSerial * s);


	void forwards();
	void forwardsspeed(int speed);
	void reverse();
	void reverse(int speed);
	void left();
	void left(int speed);
	void right();
	void right(int speed);
	void halt();

	void turretMove(int degree);

	void turnOnLed();
	void turnOffLed();

	int readLight();

	int readLeftInfrared();
	int readRightInfrared();

	int calculateLength(int array);
	void checkArrayLength(int array1, int array2);



private:
	boolean ping_ultrasonic_trigger();
			void set_max_distance(unsigned int max_cm_distance);
	#if TIMER_ENABLED == true
			boolean ping_ultrasonic_trigger_timer(unsigned int trigger_delay);
			boolean ping_ultrasonic_wait_timer();
			static void timer_setup();
			static void timer_ms_cntdwn();
	#endif
	#if DO_BITWISE == true
			uint8_t _triggerBit;
			uint8_t _echoBit;
		#if defined(PARTICLE)
			#if !defined(portModeRegister)
				#if defined (STM32F10X_MD)
					#define portModeRegister(port)     ( &(port->CRL) )
				#elif defined (STM32F2XX)
					#define portModeRegister(port)     ( &(port->MODER) )
				#endif
			#endif
			volatile uint32_t *_triggerOutput;
			volatile uint32_t *_echoInput;
			volatile uint32_t *_triggerMode;
		#else
			volatile uint8_t *_triggerOutput;
			volatile uint8_t *_echoInput;
			volatile uint8_t *_triggerMode;
		#endif
	#else
			uint8_t _triggerPin;
			uint8_t _echoPin;
	#endif
			unsigned int _maxEchoTime;
			unsigned long _max_time;
protected:
};

#endif
