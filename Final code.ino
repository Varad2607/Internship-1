volatile long temp,temp2, counter = 0, counter2 = 0; 
#define LRpwm 9
#define LRdir 8
#define RRpwm 11
#define RRdir 10

void setup() {
  Serial.begin (9600);

  pinMode(2, INPUT_PULLUP); 

  pinMode(3, INPUT_PULLUP); 

  pinMode(20, INPUT_PULLUP); 

  pinMode(21, INPUT_PULLUP); 
  pinMode(LRpwm, OUTPUT);
  pinMode(LRdir, OUTPUT);
  pinMode(RRpwm, OUTPUT);
  pinMode(RRdir, OUTPUT);
  attachInterrupt(0, ai0, RISING);

  attachInterrupt(1, ai1, RISING);
  
  attachInterrupt(2, ai2, RISING);

  attachInterrupt(3, ai3, RISING);
}

void loop() {
  // Send the value of counter
  if ( counter != temp ) {
    Serial.println (counter);
    temp = counter;
  }
  if (counter >= 324715) {
    digitalWrite(LRdir, LOW);
    analogWrite(LRpwm, 0);
  }
  else if (counter <= -324715) {
    digitalWrite(LRdir, LOW);
    analogWrite(LRpwm, 0);
  }
  else {
    digitalWrite(LRdir, HIGH);
    analogWrite(LRpwm, 50);
  }
  if ( counter2 != temp2 ) {
    Serial.println (counter2);
    temp2 = counter2;
  }
  if (counter2 >= 324715) {
    digitalWrite(RRdir, LOW);
    analogWrite(RRpwm, 0);
  }
  else if (counter2 <= -324715) {
    digitalWrite(RRdir, LOW);
    analogWrite(RRpwm, 0);
  }
  else {
    digitalWrite(RRdir, HIGH);
    analogWrite(RRpwm, 50);
  }
}

void ai0() {
  if (digitalRead(3) == LOW) {

    counter++;

  } else {
    counter--;

  }
}

void ai1() {
  if (digitalRead(2) == LOW) {
    counter--;

  } else {
    counter++;

  }
}

void ai2() {
  if (digitalRead(21) == LOW) {

    counter2++;

  } else {
    counter2--;

  }
}

void ai3() {
  if (digitalRead(20) == LOW) {
    counter2--;

  } else {
    counter2++;

  }
}
