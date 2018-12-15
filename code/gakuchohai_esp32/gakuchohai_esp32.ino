/*
  Definition of motor pins
*/
const int m1[2] = {33, 25};
const int m2[2] = {26, 27};
const int m3[2] = {14, 12};

void motor_con() {
  static uint8_t pwm[3] = {0, 0, 0}; //The pwm values of each motors
  static boolean forward[3] = {true, true, true};//The boolean values of if motors direction is fowoard

  /*
     motor1 control
  */
  ledcWrite(1, 0);
  ledcWrite(2, 0);
  digitalWrite(m1[0], LOW);
  digitalWrite(m1[1], LOW);
  if (forward[0]) {
    ledcWrite(1, pwm[0]);
    digitalWrite(m1[1], LOW);
  } else {
    ledcWrite(2, pwm[0]);
    digitalWrite(m1[0], LOW);
  }

  /*
     motor2 control
  */
  ledcWrite(3, 0);
  ledcWrite(4, 0);
  digitalWrite(m2[0], LOW);
  digitalWrite(m2[1], LOW);
  if (forward[1]) {
    ledcWrite(3, pwm[1]);
    digitalWrite(m2[1], LOW);
  } else {
    ledcWrite(4, pwm[1]);
    digitalWrite(m2[0], LOW);
  }

  /*
     motor3 control
  */
  ledcWrite(5, 0);
  ledcWrite(6, 0);
  digitalWrite(m3[0], LOW);
  digitalWrite(m3[1], LOW);
  if (forward[2]) {
    ledcWrite(5, pwm[2]);
    digitalWrite(m3[1], LOW);
  } else {
    ledcWrite(6, pwm[2]);
    digitalWrite(m3[0], LOW);
  }
}

void setup() {
  digitalWrite(m1[0], LOW);
  digitalWrite(m1[0], LOW);
  digitalWrite(m2[1], LOW);
  digitalWrite(m2[1], LOW);
  digitalWrite(m3[0], LOW);
  digitalWrite(m3[1], LOW);

  delay(100); //delay time to be stabilize

  /*
     setup ledc(pwm)
  */
  ledcSetup(0, 12800, 8);

  //motor1
  ledcAttachPin(m1[0], 1);
  ledcAttachPin(m1[1], 2);

  //motor2
  ledcAttachPin(m2[0], 3);
  ledcAttachPin(m2[1], 4);

  //motor3
  ledcAttachPin(m3[0], 5);
  ledcAttachPin(m3[1], 6);
}

void loop() {
}
