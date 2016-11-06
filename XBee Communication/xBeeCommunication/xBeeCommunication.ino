#define BUTTON A5
const int LED = 6;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
    //Serial.println("It is available.");
  //while(Serial.available() >0) {
    Serial.println("It is available.");
    
    if (analogRead(BUTTON) == HIGH) {
      //Serial.print("Hola");
      Serial.write('1');  
    }
    if (Serial.read() == '1') {
      digitalWrite(LED,HIGH);
      delay(1000);
      digitalWrite(LED,LOW);  
      //Serial.print("FUCK");
    }  
  //}
  

}
