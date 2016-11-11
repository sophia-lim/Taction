#define BUTTON 2
#define LED A4
unsigned long timer = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);

  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {

    if (digitalRead(BUTTON) == HIGH) {
      //Serial.print("Hola");
      delay(125);
      //Serial.write(1);  
      digitalWrite(LED,HIGH);
      delay(1000);
      digitalWrite(LED,LOW);
      //Define yourself as COM8  
      Serial.write("8 \n");
      
    } else {}


    while(Serial.available() > 0) {
      //Add other Arduino's identity into temp
      char temp = (char)Serial.read();
      //If it is other Arduino, then confirm
      if (temp == '2') {
        Serial.write("Ok. Gotcha.");
      } else if (temp == '3'){
        Serial.write("4");
      }
    }
    
}
