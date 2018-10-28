// ------------
// Blink an LED
// ------------

/*-------------

We've heavily commented this code for you. If you're a pro, feel free to ignore it.

Comments start with two slashes or are blocked off by a slash and a star.
You can read them, but your device can't.
It's like a secret message just for you.

Every program based on Wiring (programming language used by Arduino, and Particle devices) has two essential parts:
setup - runs once at the beginning of your program
loop - runs continuously over and over

You'll see how we use these in a second.

This program will blink an led on and off every second.
It blinks the D7 LED on your Particle device. If you have an LED wired to D0, it will blink that LED as well.

-------------*/

int redPin = A5;
int orangePin = A4;
int yellowPin = A3;
int greenPin = A2;
int bluePin = A1;


void setup()
{
  // Set up our pins for output
  pinMode( redPin, OUTPUT);
  pinMode( orangePin, OUTPUT);
  pinMode( yellowPin, OUTPUT);
  pinMode( greenPin, OUTPUT);
  pinMode( bluePin, OUTPUT);

  //Register our Particle function here
  Particle.function("led", ledControl);

  digitalWrite(redPin, LOW);
  digitalWrite(orangePin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
  digitalWrite(bluePin, LOW);

}


void loop() {

}



int ledControl( String n){
    int x = n.toInt();

    if (x < 150) {
        digitalWrite(redPin,HIGH);
        digitalWrite(orangePin, LOW);
        digitalWrite(yellowPin, LOW);
        digitalWrite(greenPin, LOW);
        digitalWrite(bluePin, LOW);
        return 5;
    }
    else if (x > 150 && x < 201)
    {
        digitalWrite(orangePin, HIGH);
        digitalWrite(redPin, LOW);
        digitalWrite(yellowPin, LOW);
        digitalWrite(greenPin, LOW);
        digitalWrite(bluePin, LOW);
        return 4;
    }
    else if (x > 200 && x < 251)
    {
        digitalWrite(yellowPin, HIGH);
        digitalWrite(redPin, LOW);
        digitalWrite(orangePin, LOW);
        digitalWrite(greenPin, LOW);
        digitalWrite(bluePin, LOW);
        return 3;
    }
    else if (x > 250 && x < 301)
    {
        digitalWrite(greenPin, HIGH);
        digitalWrite(redPin, LOW);
        digitalWrite(orangePin, LOW);
        digitalWrite(yellowPin, LOW);
        digitalWrite(bluePin, LOW);
        return 2;
    }
    else if (x > 300)
    {
        digitalWrite(bluePin, HIGH);
        digitalWrite(redPin, LOW);
        digitalWrite(orangePin, LOW);
        digitalWrite(yellowPin, LOW);
        digitalWrite(greenPin, LOW);
        return 1;
    }
    else {
        return -1;
    }
}
