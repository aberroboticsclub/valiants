#include <valiant.h>

Valiant valiant;

void setup() {
  Serial.begin(9600);
  valiant.setup(&Serial);

}

void loop() {
  /*
  //test motors HIGH and LOW
   valiant.forwards();
   delay(1000);
   valiant.left();
   delay(1000);
   valiant.right();
   delay(1000);
   valiant.reverse();
   delay(1000);
   valiant.halt();
   delay(5000);*/


  //test ultrasonics
  //Serial.println(valiant.ping_ultrasonic_cm());


/*
  //test LED
	valiant.turnOnLed();
	delay(1000);
	valiant.turnOffLed();
	delay(1000);*/

  //test servo
  //valiant.turretMove(90);
  //delay(1000);

  //test LDR
	//Serial.println(valiant.readLight());
	//delay(50);

  /*
  //test Infrared
  Serial.print("left ");
  Serial.print(valiant.readLeftInfrared());
  Serial.print(" | ");
  Serial.print("right ");
  Serial.println(valiant.readRightInfrared());
  delay(10);*/
}
