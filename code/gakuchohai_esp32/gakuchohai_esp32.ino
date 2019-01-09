/*
   Definition of ledc pin
*/
#define M1_L 1
#define M1_R 2
#define M2_L 3
#define M2_R 4
#define M3_L 5
#define M3_R 6

/*
   Definition of motor pins
*/
const uint8_t m1[2] = {33, 25};
const uint8_t m2[2] = {26, 27};
const uint8_t m3[2] = {14, 12};

void motor_con(int16_t pwm[3]) {
  /*
     motor1 control
  */
  ledcWrite(M1_L, 0);
  ledcWrite(M1_R, 0);
  if (pwm[0] >= 0) {
    ledcWrite(M1_L, pwm[0]);
    ledcWrite(M1_R, 0);
  } else {
    ledcWrite(M1_L, 0);
    ledcWrite(M1_R, -pwm[0]);
  }

  /*
     motor2 control
  */
  ledcWrite(M2_L, 0);
  ledcWrite(M2_R, 0);
  if (pwm[1] >= 0) {
    ledcWrite(M2_L, pwm[1]);
    ledcWrite(M2_R, 0);
  } else {
    ledcWrite(M2_L, 0);
    ledcWrite(M2_R, -pwm[1]);
  }

  /*
     motor3 control
  */
  ledcWrite(M3_L, 0);
  ledcWrite(M3_R, 0);
  if (pwm[2] >= 0) {
    ledcWrite(M3_L, pwm[2]);
    ledcWrite(M3_R, 0);
  } else {
    ledcWrite(M3_L, 0);
    ledcWrite(M3_R, -pwm[2]);
  }

}

void setup() {
  /*
     setup ledc(pwm)
  */
  ledcSetup(0, 12800, 8);

  //motor1
  ledcAttachPin(m1[0], M1_L);
  ledcAttachPin(m1[1], M1_R);

  //motor2
  ledcAttachPin(m2[0], M2_L);
  ledcAttachPin(m2[1], M2_R);

  //motor3
  ledcAttachPin(m3[0], M3_L);
  ledcAttachPin(m3[1], M3_R);

  ledcWrite(M1_L, 0);
  ledcWrite(M1_R, 0);
  ledcWrite(M2_L, 0);
  ledcWrite(M2_R, 0);
  ledcWrite(M3_L, 0);
  ledcWrite(M3_R, 0);
}

void loop() {
  int16_t pwm[3] = {0, 0, 0}; //The pwm values of each motors

   while (true) {
     pwm[0] = 255;
     pwm[1] = 255;
     pwm[2] = 255;
     motor_con(pwm);
     delay(1000);

     pwm[0] = 10;
     pwm[1] = 10;
     pwm[2] = 10;
     motor_con(pwm);
     delay(1000);

     
     pwm[0] = -255;
     pwm[1] = -255;
     pwm[2] = -255;
     motor_con(pwm);
     delay(1000);
    }
  
}
