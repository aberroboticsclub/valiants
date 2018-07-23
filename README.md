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

#### Move Forwards

To move forwards at full speed use the function:

```
bobTheRobot.forwards();
```

To move forwards at a set speed use the function:

```
bobTheRobot.forwards(speed);
```

where speed is between 0 and 255, 0 being stop and 255 full speed.

## Running the tests

Explain how to run the automated tests for this system

### Break down into end to end tests

Explain what these tests test and why

```
Give an example
```

### And coding style tests

Explain what these tests test and why

```
Give an example
```

## Deployment

Add additional notes about how to deploy this on a live system

## Built With

* [Dropwizard](http://www.dropwizard.io/1.0.2/docs/) - The web framework used
* [Maven](https://maven.apache.org/) - Dependency Management
* [ROME](https://rometools.github.io/rome/) - Used to generate RSS Feeds

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags).

## Authors

* **Billie Thompson** - *Initial work* - [PurpleBooth](https://github.com/PurpleBooth)

See also the list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* Hat tip to anyone whose code was used
* Inspiration
* etc
