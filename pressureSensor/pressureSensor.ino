#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Analog input pin that the Velostat is connected to
const int pressureInPin = A0;
// Digital input put for LED strip
const int lightPin = 6;  

// value read from the Velostat
int sensorValue = 0;

//LED brightness
int LEDbrightness = 0;

// Initialize LED strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, lightPin, NEO_RGB + NEO_KHZ800);

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  //init Analog Pin as PULLUP
  //(meaning it sends out voltage)
  digitalWrite(pressureInPin, HIGH);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(pressureInPin);

  // print the results to the serial monitor:
  Serial.print("sensor = " );
  Serial.println(sensorValue);

//  colorWipe(strip.Color(calculateBrightness(sensorValue), 0, 0), 0); // Red
  LEDbrightness = calculateBrightness(sensorValue);
  colorStrip(LEDbrightness);
}

void colorStrip(int brightness){
  for (int i = 0; i< strip.numPixels(); i++){
        strip.setBrightness(brightness);
        strip.setPixelColor(i, 255, 0, 255); 
        strip.show(); 
  }  
}

int calculateBrightness(int pressure){
  //The sensor is a pullup, so the value will be lower if pressure is higher
  LEDbrightness = 255 - (pressure/4);
  return LEDbrightness;
}
// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
  }
}
