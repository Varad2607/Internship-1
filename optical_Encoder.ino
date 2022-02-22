volatile long temp, counter = 0; //This variable will increase or decrease depending on the rotation of encoder
#define LRpwm 9
#define LRdir 8

void setup() {
  Serial.begin (9600);

  pinMode(2, INPUT_PULLUP); // internal pullup input pin 2

  pinMode(3, INPUT_PULLUP); // internal pullup input pin 3
   pinMode(LRpwm, OUTPUT);
  pinMode(LRdir, OUTPUT);
  //Setting up interrupt
  //A rising pulse from encoder activated ai0(). AttachInterrupt 0 is DigitalPin no. 2 on most Arduino.
  attachInterrupt(0, ai0, RISING);

  //B rising pulse from encoder activated ai1(). AttachInterrupt 1 is DigitalPin no. 3 on most Arduino.
  attachInterrupt(1, ai1, RISING);
}

void loop() {
  // Send the value of counter
  if ( counter != temp ) {
    Serial.println (counter);
    temp = counter;
  }
     if(counter>=324715){
      digitalWrite(LRdir, LOW);
       analogWrite(LRpwm, 0);
    }
    else if(counter<=-324715){
      digitalWrite(LRdir, LOW);
       analogWrite(LRpwm, 0);
    }
    else{
       digitalWrite(LRdir, HIGH);
       analogWrite(LRpwm, 50);
    }
}

void ai0() {
  // ai0 is activated if DigitalPin no. 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if (digitalRead(3) == LOW) {
    
    counter++;
   
  } else {
    counter--;
    
  }
}

void ai1() {
  // ai0 is activated if DigitalPin no. 3 is going from LOW to HIGH
  // Check with pin 2 to determine the direction
  if (digitalRead(2) == LOW) {
    counter--;
   
  } else {
    counter++;
    
  }
}
