int message = 9675;
char tilde = '~';
byte masterId = 0;
byte slave_1 = 1;
byte slave_2 = 2;


void setup(){
 Serial.begin(9600);

}


void loop(){

  //Serial.println(reseiveIntMessageSlvae());
  while (Serial.available() > 0) {
    char temp = (char)Serial.read();
    if (temp == '1') {
      Serial.write("y");
      Serial.println("Got the 1.");
    } else {
      Serial.println("Didn't get the 1.");
    }
  }
    Serial.println("No serial");
}


void sendMessageInt(int msg, byte slaveId){

 int msgOne  = byte(msg/256);
 int msgTwo  = byte(msg%256);

 Serial.write(tilde);
 Serial.write(masterId);
 Serial.write(slaveId);
 Serial.write(msgOne);
 Serial.write(msgTwo);

}

boolean echoReceived(){

 char tilda = '~';
 
 if(Serial.read() > 0){

   if(Serial.read() == tilda){

     if(Serial.read() == slave_1){
       
       if(Serial.read() == 'y'){
        
        return true; 
       }
     }
   }
 }
 return false;
}


int reseiveIntMessageSlvae(){

 byte myID = slave_1;
 int recover = 0;
 char tilda = '~';

 while(Serial.available() > 0){
  
   if(Serial.read() == tilda){

     if(Serial.read() == masterId){

       if(Serial.read() == myID){

         recover = 0;
         byte partOne = Serial.read();
         byte partTwo = Serial.read();

         recover = ((int)partOne)*256 + partTwo;

         char received = 'y';

         Serial.write(tilda);
         Serial.write(myID);
         Serial.write(received);

       }
     }
   }
 }
 return recover;
}
