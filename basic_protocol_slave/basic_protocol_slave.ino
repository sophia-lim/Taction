#define TILDE    126
#define M_ID     0
#define MY_ID    2
#define FIN      10
#define MSIZE    3 //Next 3 bytes are the last

void setup(){
 Serial.begin(57600);
}


void loop(){
// Serial.println(reseiveIntMessageSlvae());
}

void serialEvent(){

  Serial.println(reseiveIntMessageSlvae());
}

int reseiveIntMessageSlvae(){

int recover = 0;

 while(Serial.available() > 0){

   delay(5);
   uint8_t _t = Serial.read();
//   Serial.println(_t);
   
   if(_t == TILDE){

//     delay(5);
     uint8_t _t = Serial.read();
     //Serial.println(_t);

     if(_t == M_ID){

       delay(5);
       uint8_t _t = Serial.read();
       //Serial.println(_t);

       if(_t == MY_ID){

         delay(5);
         uint8_t _t = Serial.read();
//         Serial.println(_t);

         if(_t == MSIZE){

//           delay(5);          
           byte partOne;
           byte partTwo; 
           int counter = 0;

           do {
               partOne = Serial.read();
               //Serial.print("High byte: ");
               //Serial.println(partOne);
               partTwo = Serial.read();
               //Serial.print("Low byte: ");
               //Serial.println(partTwo);
               counter +=2;
               
               _t = Serial.read();
           }
           while(counter <= MSIZE && _t != 10);

             recover = ((int)partOne)*256 + partTwo;
             //Serial.print("Recover: ");
             //Serial.println(recover);

           //char received = 'y';

           //Serial.write(TILDE);
           //Serial.write(MY_ID);
           //Serial.write(received);
         }
       }
     }
   }
 }
 return recover;
}
