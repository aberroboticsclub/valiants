#include <valiant.h>
#define TEST_MOTORS false
#define TEST_ULTRASONIC false
#define TEST_LED false
#define TEST_LDR false
#define TEST_SERVO false
#define TEST_INFRARED false
#define TEST_SPEAKER false

Valiant valiant;

const int melody[] = {
  NOTE_G4, NOTE_A4, NOTE_G4, NOTE_C5, NOTE_C5, NOTE_C5,
  //YOU PUT YOUR BODY PART IN
  NOTE_G4, NOTE_A4, NOTE_G4, NOTE_C5, NOTE_C5, NOTE_C5,
  //YOU PUT YOUR BODY PART OUT
  NOTE_G4, NOTE_A4, NOTE_G4, NOTE_C5, NOTE_C5, NOTE_C5,
  //YOU PUT YOUR BODY PART IN
  NOTE_A4, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_B4,
  //AND YOU SHAKE IT ALL ABOUT
  NOTE_G4, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_B4, NOTE_A4, NOTE_G4, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_B4,
  //YOU DO THE HOKEY POKEY AND YOU TURN YOURSELF AROUND
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5,
  //THAT'S WHAT IT'S ALL ABOUT
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
const int noteDurations[] = {
  8, 4, 8, 4, 2, 2,
  //YOU PUT YOUR BODY PART IN
  8, 4, 8, 4, 2, 2,
  //YOU PUT YOUR BODY PART OUT
  8, 4, 8, 4, 2, 2,
  //YOU PUT YOUR BODY PART IN
  4, 6, 4, 6, 6, 4, 2,
  //AND YOU SHAKE IT ALL ABOUT
  4, 4, 6, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
  //YOU DO THE HOKEY POKEY AND YOU TURN YOURSELF AROUND
  4, 2, 8, 2, 4, 4
  //THAT'S WHAT IT'S ALL ABOUT
};

void setup() {
  Serial.begin(9600);
  valiant.setup(&Serial);

}

void loop() {
  #ifdef TEST_MOTORS
  if (TEST_MOTORS) {
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
   delay(5000);
  }
  #endif

  #ifdef TEST_ULTRASONIC
  if (TEST_ULTRASONIC) {
  //test ultrasonics
  Serial.println(valiant.ping_ultrasonic_cm());
  }
  #endif

  #ifdef TEST_LED
  if (TEST_LED) {
  //test LED
	valiant.turnOnLed();
	delay(1000);
	valiant.turnOffLed();
	delay(1000);
  }
  #endif

  #ifdef TEST_SERVO
  if (TEST_SERVO) {
  //test servo
  valiant.turretMove(90);
  delay(1000);
  valiant.turretMove(60);
  delay(1000);
  valiant.turretMove(140);
  delay(1000);
  valiant.turretMove(90);
  delay(5000);
  }
  #endif

  #ifdef TEST_LDR
  if (TEST_LDR) {
  //test LDR
	Serial.println(valiant.readLight());
	delay(50);
  }
  #endif

  #ifdef TEST_INFRARED
  if (TEST_INFRARED) {
  //test Infrared
  Serial.print("left ");
  Serial.print(valiant.readLeftInfrared());
  Serial.print(" | ");
  Serial.print("right ");
  Serial.println(valiant.readRightInfrared());
  delay(10);
  }
  #endif

  #ifdef TEST_SPEAKER
  if (TEST_SPEAKER) {
	// iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < valiant.calculateLength(melody); thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(valiant.speaker, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(valiant.speaker);
  }
  }
  #endif
}
