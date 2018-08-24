# valiants
Easily programmable 'Valiant Library' for use by Aberystwyth Robotics Club and outreach.

## Getting Started

These instructions will show you how to get set-up with the Valiants library.

### Prerequisites

1) Download this repository either as a zip, then extracting the contents in the Arduino library folder, or clone the repository using Git using the following command.

```
git clone https://github.com/aberroboticsclub/valiants
```
2) Attach the library in your Arduino sketch using the header

```
#include <Valiant.h>
```

## Using the Library

A step by step series of instructions showing you how to interact with the Valiant using this library.

### Setting up the Valiant

Before you start programming you need to create a Valiant library object.
This needs to be done inside the Arduino sketch, as shown below.

```
#include <Valiant.h> //attach the valiant library

Valiant bobTheRobot; //create a robot called bob or whatever

void setup() { //open setup function
  bobTheRobot.setup(&Serial); //set up bob and give it access to the usb
} //close setup function

void loop() { //open loop function
  //don't do anything yet
} //close loop function
```

### Motors

To move the valiant use the following functions

#### Motors Forwards

To move forwards at full speed use the function:

```
bobTheRobot.forwards();
```


#### Motors Reverse

To reverse at full speed use the function:

```
bobTheRobot.reverse();
```


#### Motors Left

To move left at full speed use the function:

```
bobTheRobot.left();
```


#### Motors Right

To move right at full speed use the function:

```
bobTheRobot.right();
```


#### Motors Stop

To stop the motors use the function:

```
bobTheRobot.halt();
```

#### Drive for how long?

To drive for a certain amount of time use the following function:

```
delay(milliseconds);
```

Where milliseconds is the time you wish the motors to move for.

#### Example

An example of the motor drives can be found below

```
#include <valiant.h>

Valiant bobTheRobot;


void setup() {
  bobTheRobot.setup(&Serial);
}

void loop() {
  bobTheRobot.forwards();
  delay(1000);
  bobTheRobot.left();
  delay(1000);
  bobTheRobot.right();
  delay(1000);
  bobTheRobot.reverse();
  delay(1000);
  bobTheRobot.halt();
  delay(5000);
}
```


### Ultrasonics

An ultrasnonic sensor is mounted to the servo allowing it approximately 200 degrees of sensing obstacles. 

To take readings from the ultrasonic sensor, use the following functions.

```
bobTheRobot.ping_ultrasonic_cm(); //read distance in centimeters

bobTheRobot.ping_ultrasonic_in(); //read distance in inches
```

This function returns an int, therefore it can be assigned to another variable, or sent to the serial line to be printed. An example is shown below.

```
int myDistance = bobTheRobot.ping_ultrasonic_cm();

Serial.println(bobTheRobot.ping_ultrasonic_cm());
```

### Servo

This function will change the angle of the servo.

```
bobTheRobot.turretMove(angle);
```

The variable 'angle' being a number between 0 and 180.

### Speaker

To play songs, we need to define the notes and the durations. To define the notes, we will specify the notes and octaves. An example is shown below.

```
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
```

Next the note durations will be defined. An example is shown below.

```
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
```

A for loop will be used to iterate through the arrays containing the notes and durations. The tone function will then be used to output the notes to the speaker/amplifier. An example is shown below.

```
for (int thisNote = 0; thisNote < 45; thisNote++) {
  // to calculate the note duration, take one second
  // divided by the note type.
  //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
  int noteDuration = 1000 / noteDurations[thisNote];
  tone(speaker, melody[thisNote], noteDuration);

  // to distinguish the notes, set a minimum time between them.
  // the note's duration + 30% seems to work well:
  int pauseBetweenNotes = noteDuration * 1.30;
  delay(pauseBetweenNotes);
  // stop the tone playing:
  noTone(speaker);
}
```

### Infrared

Both infrared sensors are mounted at the front left and right of the Valiant, allowing for approximately 100 degrees of sensing. 

To take readings from the infrared sensors, use the following functions.

```
bobTheRobot.readLeftInfrared(); //read distance from left sensor

bobTheRobot.readRightInfrared(); //read distance from right sensor
```

This function returns an int, therefore it can be assigned to another variable, or sent to the serial line to be printed. An example is shown below.

```
int distanceLeft = bobTheRobot.readRightInfrared();

Serial.println(bobTheRobot.readRightInfrared());
```

### Wi-Fi



## Authors

* **Tomos Fearn** - *Initial work* - [tomos.fearn.org.uk](http://tomos.fearn.org.uk)
* **Dr Keiran Burrows** - *Initial work* - [Github](https://github.com/kbcool125)
