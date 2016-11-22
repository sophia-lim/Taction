#define HWSERIAL Serial3
#define TILDE    126
#define M_ID     0
#define S_ID_1   1
#define S_ID_2   2
#define FIN      10
#define MSIZE    3


//char tilde = '~';
//byte masterId = 0;
//byte slave_1 = 1;
//byte slave_2 = 2;

const int LED = 14;
const int BUTTON = 6;



void setup(){

 Serial.begin(57600);
 HWSERIAL.begin(57600);

 pinMode(LED, OUTPUT);
 pinMode(BUTTON, INPUT);

}


void loop(){

//  uint16_t newMsg = random(0, 65535);

//  Serial.println(digitalRead(BUTTON));
 if(digitalRead(BUTTON) == HIGH){

   delay(125);

   digitalWrite(LED, HIGH);

   sendMessageInt(9526, S_ID_1);

//    Serial.println(newMsg);
 }



 if(echoReceived())
   Serial.println("Success");

}


void sendMessageInt(uint16_t msg, uint8_t slaveId){

 //  int msgOne  = byte(msg/256);
 //  int msgTwo  = byte(msg%256);
 //  
 //  Serial.print("message one: ");
 //  Serial.println(msgOne);
 //  Serial.print("message Two: ");
 //  Serial.println(msgTwo);


 int msgOne  = highByte(msg);
 int msgTwo  = lowByte(msg);

 HWSERIAL.write(TILDE);
 HWSERIAL.write(M_ID);
 HWSERIAL.write(S_ID_1);
 HWSERIAL.write(MSIZE);
 HWSERIAL.write(msgOne);
 HWSERIAL.write(msgTwo);
 HWSERIAL.write(FIN);
}

boolean echoReceived(){

 while(HWSERIAL.available() > 0){

   delay(5);
   uint8_t _t = HWSERIAL.read();
   
   if(_t == TILDE){
     
     delay(5);
     uint8_t _t = HWSERIAL.read();

     if(_t == S_ID_1){
       
       delay(5);
       uint8_t _t = HWSERIAL.read();

       if(_t == 'y'){

         return true; 
       }
     }
   }
 }
 return false;
}
