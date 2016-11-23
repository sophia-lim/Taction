// Description : The following code reads analog pressure values from 3 Velostat pressure sensors
// All three control the RGB values for the LED strip

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Analog input pin that the Velostat is connected to
// Pressure pin controlling R
const int pressureInPin_1 = A0;
int sensorValue_1 = 0;
int lightSaturation_R = 0;

// Pressure pin controlling G
const int pressureInPin_2 = A1;
int sensorValue_2 = 0;
int lightSaturation_G = 0;

// Pressure pin controlling B
const int pressureInPin_3 = A2;
int sensorValue_3 = 0;
int lightSaturation_B = 0;

// Digital input put for LED strip
const int lightPin = 6;  

// Initialize LED strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, lightPin, NEO_RGB + NEO_KHZ800);

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'

  // initialize Analog Pin as PULLUP (meaning it sends out voltage)
  digitalWrite(pressureInPin_1, HIGH);
  digitalWrite(pressureInPin_2, HIGH);
  digitalWrite(pressureInPin_3, HIGH);
}

void loop() {
  // read the analog in value:
  sensorValue_1 = analogRead(pressureInPin_1);
  sensorValue_2 = analogRead(pressureInPin_2);
  sensorValue_3 = analogRead(pressureInPin_3);

  // print the results to the serial monitor:
  Serial.print("Sensor 1 : " );
  Serial.println(sensorValue_1);
  Serial.print("Sensor 2 : " );
  Serial.println(sensorValue_2);
  Serial.print("Sensor 3 : " );
  Serial.println(sensorValue_3);

  // Calculate saturation (0-255) for RGB
  lightSaturation_R = calculateSaturation(sensorValue_1);
  lightSaturation_G = calculateSaturation(sensorValue_2);
  lightSaturation_B = calculateSaturation(sensorValue_3);

  // Color the Neopixels
  colorStrip(lightSaturation_R, lightSaturation_G, lightSaturation_B);
}

// Color Neopixel strips
void colorStrip(int R, int G, int B){
  for (int i = 0; i< strip.numPixels(); i++){
        strip.setBrightness(100);
        strip.setPixelColor(i, R, G, B); 
        strip.show(); 
  }  
}

// This methods takes in the analog in value of the pressure sensor and returns the according RGB saturation values
int calculateSaturation(int pressure){
  //The sensor is a pullup, so the value will be lower if pressure is higher
  int saturation = 255 - (pressure/4);
  return saturation;
}

// Timer that will only check for pressure once every measure of song
void updateColors() {}

// Calculate BPM according to initial taps from pedal
void calculateBPM() {}

// LED fading in/out on each beat
void fadeBrightness() {}
