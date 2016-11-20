const int LED = 14;
const int BUTTON = 6;

#define HWSERIAL Serial3


void setup(){

  Serial.begin(9600);
  HWSERIAL.begin(9600);

  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);

}



void loop(){


  if(digitalRead(BUTTON) == HIGH){

    digitalWrite(LED, HIGH);
    Serial.println("Sending!!");
    
    HWSERIAL.write('1');

  }

  if(HWSERIAL.available() > 0){

    char confirm = (char)HWSERIAL.read();

    if(confirm == 'y'){

      Serial.println("thank you");
    }

  }

}

