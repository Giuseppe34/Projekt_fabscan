
#define LIGHT_PIN A3
#define LASER_PIN A4
#define MS_PIN    A5

//Stepper 1 as labeled on Shield, Turntable
#define ENABLE_PIN_0  2
#define STEP_PIN_0    3
#define DIR_PIN_0     4

#define TURN_LASER_OFF      200 //vypnuti laseru
#define TURN_LASER_ON       201 //zapnuti laseru
#define PERFORM_STEP        202 //krok
#define SET_DIRECTION_CW    203 //smer
#define SET_DIRECTION_CCW   204
#define TURN_STEPPER_ON     205 //zapnuti motoru
#define TURN_STEPPER_OFF    206
#define FABSCAN_PING        210
#define FABSCAN_PONG        211
#define SELECT_STEPPER      212
#define LASER_STEPPER       11
#define TURNTABLE_STEPPER   10
//the protocol: we send one byte to define the action what to do.
//If the action is unary (like turnung off the light) we only need one byte so we are fine.
//If we want to tell the stepper to turn, a second byte is used to specify the number of steps.
//These second bytes are defined here below.

#define ACTION_BYTE         1    //normal byte, first of new action
#define LIGHT_INTENSITY     2
#define TURN_TABLE_STEPS    3
#define LASER1_STEPS        4
#define LASER2_STEPS        5
#define LASER_ROTATION      6
#define STEPPER_ID          7

int incomingByte = 0;
int byteType = 1;
int currStepper;


//current motor: turn a single step 
void step()
{
 if(currStepper == TURNTABLE_STEPPER){
   digitalWrite(STEP_PIN_0, LOW);
 }else if(currStepper == LASER_STEPPER){
   digitalWrite(STEP_PIN_1, LOW);
 }

 delay(3);
 if(currStepper == TURNTABLE_STEPPER){
   digitalWrite(STEP_PIN_0, HIGH);
 }else if(currStepper == LASER_STEPPER){
   digitalWrite(STEP_PIN_1, HIGH);
 }
 delay(3);
}

//step the current motor for <count> times
void step(int count)
{
  for(int i=0; i<count; i++){ //otáčení motoru
    step();
  }
}

void setup() 
{ 
  // initialize the serial port
   Serial.begin(9600);
   pinMode(LASER_PIN, OUTPUT); //výstupní piny
   pinMode(LIGHT_PIN, OUTPUT);
 
   pinMode(MS_PIN, OUTPUT);
   digitalWrite(MS_PIN, HIGH);  //HIGH for 16microstepping, LOW for no microstepping

  pinMode(ENABLE_PIN_0, OUTPUT);
  pinMode(DIR_PIN_0, OUTPUT);
  pinMode(STEP_PIN_0, OUTPUT);
 
 //disable all steppers at startup
 digitalWrite(ENABLE_PIN_0, HIGH);  //HIGH to turn off
 digitalWrite(ENABLE_PIN_1, HIGH);  //HIGH to turn off
 digitalWrite(ENABLE_PIN_2, HIGH);  //LOW to turn on
 digitalWrite(ENABLE_PIN_3, HIGH);  //LOW to turn on 
 
 digitalWrite(LASER_PIN, HIGH); //zapnutí laseru
 Serial.write(FABSCAN_PONG); 
 //pošle signál zpět do počítače, takže víme že konfigurace je hotova a nyní můžeme pracovat s fabscanem
 
 currStepper = TURNTABLE_STEPPER;  //turntable is default stepper
} 

void loop() 
{

  if(Serial.available() > 0){

    incomingByte = Serial.read();
    
    switch(byteType){
      case ACTION_BYTE:
      
          switch(incomingByte){    //this switch always handles the first byte
            //Laser
            case TURN_LASER_OFF:
              digitalWrite(LASER_PIN, LOW);    // vypnutí laseru
              break;
            case TURN_LASER_ON:
              digitalWrite(LASER_PIN, HIGH);   // zapnutí laseru
              break;
            case ROTATE_LASER: //unused
              byteType = LASER_ROTATION;
              break;
            //TurnTable
            case PERFORM_STEP:
              byteType = TURN_TABLE_STEPS;
              break;
            case SET_DIRECTION_CW: //smer otáčení
              if(currStepper == TURNTABLE_STEPPER){
                digitalWrite(DIR_PIN_0, HIGH);
              }else if(currStepper == LASER_STEPPER){
                digitalWrite(DIR_PIN_1, HIGH);
              }
              break;
            case SET_DIRECTION_CCW: //smer otácení
              if(currStepper == TURNTABLE_STEPPER){
                digitalWrite(DIR_PIN_0, LOW);
              }else if(currStepper == LASER_STEPPER){
                digitalWrite(DIR_PIN_1, LOW);
              }
              break;
            case TURN_STEPPER_ON: //
              if(currStepper == TURNTABLE_STEPPER){
                digitalWrite(ENABLE_PIN_0, LOW);
              }else if(currStepper == LASER_STEPPER){
                digitalWrite(ENABLE_PIN_1, LOW);
              }
              break;
            case TURN_STEPPER_OFF:
              if(currStepper == TURNTABLE_STEPPER){
                digitalWrite(ENABLE_PIN_0, HIGH);
              }else if(currStepper == LASER_STEPPER){
                digitalWrite(ENABLE_PIN_1, HIGH);
              }
              break;
            case TURN_LIGHT_ON:
              byteType = LIGHT_INTENSITY;
              break;
            case TURN_LIGHT_OFF:
              digitalWrite(LIGHT_PIN, LOW);
              break;
            case FABSCAN_PING:
              delay(1);
              Serial.write(FABSCAN_PONG);
              break;
            case SELECT_STEPPER:
              byteType = STEPPER_ID;
              break;
            }
      
          break;
       case LIGHT_INTENSITY:       //after this point we take care of the second byte if one is sent
          analogWrite(LIGHT_PIN, incomingByte);
          byteType = ACTION_BYTE;  //reset byteType
          break;
        case TURN_TABLE_STEPS:
          step(incomingByte);
          byteType = ACTION_BYTE;
          break;
        case STEPPER_ID:
          Serial.write(incomingByte);
          currStepper = incomingByte;
          byteType = ACTION_BYTE;
          break;
    }
  } 
} 
