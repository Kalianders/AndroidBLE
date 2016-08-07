// ledikirjasto
#include <Adafruit_NeoPixel.h>
#define STATUSPIN 4 //oranssi maa = sininen 5v = punanen
#define POWERPIN 5 // keltanen maa = vihreä  5v = ruskea
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, STATUSPIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(9, POWERPIN, NEO_GRB + NEO_KHZ800);

int statusint = 0;   
boolean kytkin = false;
int fadeValue = 0;
unsigned int integerValue = 0; // Max value is 65535
char incomingByte;
char b;
int jee=0;

void setup() {
Serial.begin(9600); // Begin the serial monitor at 9600bps
Serial1.begin(9600); // Begin the serial monitor at 9600bps
strip.begin();
strip2.begin();
}

void loop() {
    serialfunc();
    statusled();
    rgbvalaistus();
}

void statusled(){   // statusled code  
    if (statusint == 0) { // Standby, blue LED
        uint32_t color1 = strip.Color(0,255, 0);
        for (uint16_t i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, color1);
            strip.show();
        }
    }   
    if (statusint == 1) { // Light ON, green LED
        uint32_t color1 = strip.Color(0, 0, 200);
        for (uint16_t i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, color1);
            strip.show();
        }
    }    
    if (statusint == 2) { // ERROR, red LED
        uint32_t color1 = strip.Color(255, 0, 0);
        for (uint16_t i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, color1);
            strip.show();
        }
    }
}

void rgbvalaistus(){
    if (kytkin == false) { // white
        uint32_t color2 = strip2.Color(fadeValue, fadeValue, fadeValue);
        for (uint16_t i2 = 0; i2 < strip2.numPixels(); i2++) {
            strip2.setPixelColor(i2, color2);
            strip2.show();
        }
    }
    if (kytkin == true) { // blue off
        uint32_t color2 = strip2.Color(fadeValue, fadeValue, 0);
        for (uint16_t i2 = 0; i2 < strip2.numPixels(); i2++) {
            strip2.setPixelColor(i2, color2);
            strip2.show();
        }
    }
}

void serialfunc(){                        //ottaa vastaan dataa
    while(Serial1.available())
    {
      Serial1.readBytes(&b, 1);
      if(32<=b && b<=125 || b=='\r' || b=='\n')
      {
        if (b == 'S')
        {
          Serial1.readBytes(&b, 1);
          if (b == 'S' || b == 'F' || b == 'B')
          {
            Serial1.readBytes(&b, 1);
            while (b != 'E')
            {
              jee = jee*10+(b-48);
              Serial1.readBytes(&b, 1);
            }
            Serial.print(jee);
            changeparameter(jee);
            jee = 0;
          }
        }
      }
    }
}
void changeparameter(int value){ // muuttaa min/max arvoja
    if (value >= 1000 && value < 1003) {
        statusint = value - 1000;
        Serial.print("statusint=");
        Serial.print(statusint);
        Serial.print("\n");
    }
    if (value >= 2000 && value < 2256) {
        fadeValue = value - 2000;
        Serial.print("fadeValue=");
        Serial.print(fadeValue);
        Serial.print("\n");
    }
    if (value >= 3000 && value <= 3001) {
        kytkin = value - 3000;
        Serial.print("kytkin=");
        Serial.print(kytkin);
        Serial.print("\n");
    }
}
