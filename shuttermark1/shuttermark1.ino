int incomingByte = 0;
int motorstate = 0;

// Pin Assignments //
// Don't change these! These pins are statically defined by shield layout
const byte PWMA = 3;  // PWM control (speed) for motor A
const byte PWMB = 11; // PWM control (speed) for motor B
const byte DIRA = 12; // Direction control for motor A
const byte DIRB = 13; // Direction control for motor B
const byte BRKA = 9;  // Break control for motor A
const byte BRKB = 8;  // Break control for motor B
const byte CRTA = 0;  // Current sensing for motor A
const byte CRTB = 1;  // Current sensing for motor B

// Clockwise and counter-clockwise definitions.
// Depending on how you wired your motors, you may need to swap.
#define CW  0
#define CCW 1

// Motor definitions to make life easier:
#define MOTOR_A 0
#define MOTOR_B 1

void setup(){
  Serial.begin(9600);\
  setupArdumoto();
}

void loop(){
  if(Serial.available()>0){
    incomingByte = Serial.read();
    if(incomingByte == 121){
      motorstate = 1;
    }
    if(incomingByte == 110){
      motorstate = 0;
    }
    Serial.println(motorstate);
  }
  Serial.println(analogRead(CRTB));
  
  if(motorstate==1){
    driveArdumoto(MOTOR_B,CW,255);
  }
  if(motorstate==0){
    driveArdumoto(MOTOR_B,CCW,255);
  }
  
  delay(1000);
  
  
}

void driveArdumoto(byte motor, byte dir, byte spd)
{
  if (motor == MOTOR_A)
  {
    digitalWrite(DIRA, dir);
    analogWrite(PWMA, spd);
  }
  else if (motor == MOTOR_B)
  {
    digitalWrite(DIRB, dir);
    analogWrite(PWMB, spd);
  }  
}

void stopArdumoto(byte motor)
{
  driveArdumoto(motor, 0, 0);
}

void breakArdumoto(byte motor)
{
  if (motor == MOTOR_A)
  {
    stopArdumoto(motor);
    digitalWrite(BRKA, 1);
  }
  else if (motor == MOTOR_B)
  {
    stopArdumoto(motor);
    digitalWrite(BRKB, 1);
  } 
}

void setupArdumoto()
{
  // All pins should be setup as outputs:
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  pinMode(BRKA, OUTPUT);
  pinMode(BRKB, OUTPUT);

  // Initialize all pins as low:
  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
  digitalWrite(BRKA, LOW);
  digitalWrite(BRKB, LOW);
}

