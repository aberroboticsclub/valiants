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

This function returns an int, therefore it can be assigned to another variable, or sent to the serial line to be printed. Example show below

```
int myDistance = bobTheRobot.ping_ultrasonic_cm();

Serial.println(bobTheRobot.ping_ultrasonic_cm());
```

### Servo

### Speaker

### Infrared

### Wi-Fi



## Authors

* **Tomos Fearn** - *Initial work* - [tomos.fearn.org.uk](http://tomos.fearn.org.uk)
* **Dr Keiran Burrows** - *Initial work* - [Github](https://github.com/kbcool125)
