Rocket Shield Code explanation:

The RocketShield contains six LEDs that are controlled by the Arduino and a push button that starts the lift off sequence. 
4 of them are the counter leds

They are conected to pins 9,6,5 and 3. 

The counter LEDs are declared in an array:
	
	//Pin numbers for the counter leds in the Rocket_Shield
	int counter_leds[] = {9, 6, 5, 3};	

The truster leds are connected to the same pin: 
 
	int thrusters = 10;

All of the pins that controll the leds are PWM ennabled, therefore we can control their intensity.


The push button pin is also declared: 

	int igniter = 13;

For the Arduino to recognize when the press button is pushed, we need to declare its pin as an input in the Setup:

	  pinMode(igniter, INPUT);

The pins for the LEDs are declared as outputs:

	// Set counter_pins to output to power the leds.
  		for (int i = 0; i < sizeof(counter_leds); i++) {
    			pinMode(counter_leds[i], OUTPUT);
  		}
  	//Set thruster pins to output to power the leds.
  		pinMode(thrusters, OUTPUT);

In the Loop we constantly check if the push button is being pressed:

		// Read if the button is being pressed
		igniter_value = digitalRead(igniter);

When the button is pressed the lauch_sequence is initilized: 

  		if ( igniter_value == 1) {
    			// initilize the ignition sequence if the button is pressed
    			launch_sequence();
  		}

The launge sequence is declared as a function: 

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

	



