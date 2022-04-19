//Rocket_Shield Code
//By Jaime Cababie

//Pin numbers for the counter leds in the Rocket_Shield
int counter_leds[] = {9, 6, 5, 3};

//Declaring the trusters in the Rocket_Shield
int thrusters = 10;

//Setup the push button
int igniter = 13;

int igniter_value = 0;


void setup() {


  // Set counter_pins to output to power the leds.
  for (int i = 0; i < sizeof(counter_leds); i++) {
    pinMode(counter_leds[i], OUTPUT);
  }
  //Set thruster pins to output to power the leds.
  pinMode(thrusters, OUTPUT);

  // Set the pushbutton pin to input
  pinMode(igniter, INPUT);

}

void loop() {
  // Read if the button is being pressed
  igniter_value = digitalRead(igniter); \
  if ( igniter_value == 1) {
    // initilize the ignition sequence if the button is pressed
    ignition_sequence();
  }

}


void ignition_sequence() {
  
  //Turn the couters one by one.
  for (int i = 0; i < sizeof(counter_leds); i++) {
    for (int j = 0; j < 200; j += 2) {
      analogWrite(counter_leds[i], j);
      delay(5);
    }

    // turn off the counters
  }
  for (int i = 0; i < sizeof(counter_leds); i++) {
    digitalWrite( counter_leds[i], LOW);
  }
  //the Thrusters start
  for (int i = 0; i < 200; i++) {
    analogWrite(thrusters, int(random(100, 255)));
    delay(int(random(5, 20)));
  }
  digitalWrite(thrusters, LOW);

}
