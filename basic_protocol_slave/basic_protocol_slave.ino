////////////////////////////////////////////////////////////////////////////////
// Serial Communication Protocol Variables
////////////////////////////////////////////////////////////////////////////////

#define TILDE    126
#define M_ID     0
#define MY_ID    3
#define FIN      10
#define MSIZE    3
#define DLED     13


void blinkLED(uint8_t l, uint16_t t,uint8_t r) {
  for(int i = 0; i < r; i++) {
    digitalWrite(l, HIGH);
    delay(t);
    digitalWrite(l, LOW);
    delay(t);
  }
}


void sendMessageInt(uint16_t msg, uint8_t slaveId, HardwareSerial  &serial) {

  int msgOne  = highByte(msg);
  int msgTwo  = lowByte(msg);

  serial.write(TILDE);
  serial.write(M_ID);
  serial.write(slaveId);
  serial.write(MSIZE);
  serial.write(msgOne);
  serial.write(msgTwo);
  serial.write(FIN);
}

int reseiveIntMessageSlvae(){

int recover = 0;

 while(Serial.available() > 0){

   delay(5);
   uint8_t _t = Serial.read();
   if(_t == TILDE){
    Serial.println("GOT TILDE: ");
     uint8_t _t = Serial.read();
     
     if(_t == M_ID){
      Serial.print("GOT M_ID: "); Serial.println(_t, DEC);
       delay(5);
       uint8_t _t = Serial.read();
       if(_t == MY_ID){
        Serial.print("GOT MY_ID: "); Serial.println(_t, DEC);
         delay(5);
         uint8_t _t = Serial.read();
         
         if(_t == MSIZE) {        
           byte partOne;
           byte partTwo; 
           int counter = 0;

           do {
               partOne = Serial.read();
               partTwo = Serial.read();
               counter +=2;
               _t = Serial.read();
           }
           while(counter <= MSIZE && _t != 10);

             recover = ((int)partOne)*256 + partTwo;
         }
       }
       else {
        Serial.print("GOT ERRANT MY_ID: "); Serial.println(_t, DEC);
        }
     }
   }
 }
 return recover;
}

void serialEvent() {
  Serial.println("SERIAL EVENT");
  Serial.print("MSG: ");
  Serial.println(reseiveIntMessageSlvae());
    //Serial.println("Received back!");
}

void setup() {
  // Set up serial port.
  Serial.begin(57600);

  /* DEBUG LED */
  pinMode(DLED, OUTPUT);
  blinkLED(DLED, 100, 5);
}

void loop() { 
  //sendMessageInt(random(0, 65535), slaves[random(0, 1)], HWSERIAL) ;  
  while( !Serial.available() ) 
    blinkLED(DLED, 500, 2);
}


