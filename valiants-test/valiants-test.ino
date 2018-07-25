#include <valiant.h>

Valiant valiant;

void setup() {
  Serial.begin(9600);
  valiant.setup(&Serial);

}

void loop() {
  /*
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
  //Serial.println(valiant.ping_ultrasonic_cm());

  //valiant.turretMove(90);
  //delay(1000);
  valiant.forwardsspeed(240);
  delay(2000);
  valiant.halt();
  delay(2000);
}
