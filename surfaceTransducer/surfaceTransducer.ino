#include <toneAC.h>

#define TRANS_1 9

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  toneAC(20, 10);
}
