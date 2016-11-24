//Testing the Sparkfun PCB/Audio Jack
const int audioIn = A13;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(audioIn, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogRead(audioIn));
  
}
