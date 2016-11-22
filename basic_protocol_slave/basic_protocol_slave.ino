#define TILDE    126
#define M_ID     0
#define MY_ID    1
#define FIN      10
#define MSIZE    3

void setup(){
 Serial.begin(57600);
}


void loop(){
 Serial.println(reseiveIntMessageSlvae());
}



int reseiveIntMessageSlvae(){

int recover = 0;

 while(Serial.available() > 0){

   delay(5);
   uint8_t _t = Serial.read();

   if(_t == TILDE){

     delay(5);
     uint8_t _t = Serial.read();

     if(_t == M_ID){

       delay(5);
       uint8_t _t = Serial.read();

       if(Serial.read() == MY_ID){

         delay(5);
         uint8_t _t = Serial.read();

         if(Serial.read() == MSIZE){

          
           byte partOne;
           byte partTwo; 
           int counter = 0;

           do{
               partOne = Serial.read();
               partTwo = Serial.read();
               counter +=2;
               
               _t = Serial.read();
           }
           while(counter <= MSIZE && _t != 10);

             recover = ((int)partOne)*256 + partTwo;

           char received = 'y';

           Serial.write(TILDE);
           Serial.write(MY_ID);
           Serial.write(received);
         }
       }
     }
   }
 }
 return recover;
}
