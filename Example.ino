//Using ESP8266 NodeMCU 1.0 (ESP-12E Module) as the Board

// Declare L298N Motor Driver pins

//Based off https://lastminuteengineers.com/l298n-dc-stepper-driver-arduino-tutorial/

int speedPinA = 14; //D5 PWM control 
int dir1PinA = 12; //D6
int dir2PinA = 13; //D7
bool CW = false;
bool ACW = false;

#define ClosedES 5 //D1 
#define OpenES 4 //D2


void setup() { 
 
Serial.begin(115200); // baud rate

//Define L298N Dual H-Bridge Motor Driver Pins

pinMode(dir1PinA,OUTPUT);
pinMode(dir2PinA,OUTPUT);
pinMode(speedPinA,OUTPUT);
pinMode(OpenES,INPUT_PULLUP);
pinMode(ClosedES,INPUT_PULLUP);

}

void loop() {

if((digitalRead(OpenES) == LOW) && (ACW) == false){
  Serial.println("OPEN SWITCH LOW");
  CW = false;
  ACW = true;
}

if((digitalRead(ClosedES) == LOW) && (CW) == false){
  Serial.println("CLOSED SWITCH LOW");
  CW = true;
  ACW = false;
}

Serial.print("Open Endstop : ");
Serial.println(digitalRead(OpenES));
Serial.print("Closed Endstop : ");
Serial.println(digitalRead(ClosedES));
Serial.print("CW : ");
Serial.println(CW);
Serial.print("ACW : ");
Serial.println(ACW);
//delay(500);

if(CW) { //is true

digitalWrite(speedPinA, 255);//Sets speed variable via PWM 
digitalWrite(dir1PinA, HIGH);
digitalWrite(dir2PinA, LOW);
Serial.println("Clockwise rotation"); 
Serial.println("   "); 
delay(1000);
}

if(ACW) { //is true

digitalWrite(speedPinA, 255);//Sets speed variable via PWM 
digitalWrite(dir1PinA, LOW);
digitalWrite(dir2PinA, HIGH);
Serial.println("Anti-Clockwise rotation"); 
Serial.println("   "); 
delay(1000);
}

    }
      
