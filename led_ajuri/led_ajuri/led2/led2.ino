// ledikirjasto
#include <Adafruit_NeoPixel.h>
#define STATUSPIN 4
#define POWERPIN 5
Adafruit_NeoPixel strip = Adafruit_NeoPixel(1, STATUSPIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(9, POWERPIN, NEO_GRB + NEO_KHZ800);

int statusint = 0;   
boolean kytkin = false;
int fadeValue = 0;
unsigned int integerValue = 0; // Max value is 65535
char incomingByte;
char b;
String buf="";


void setup() {
  // put your setup code here, to run once:
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
      uint32_t color1 = strip.Color(0, 0, 10);
       for (uint16_t i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, color1);
           strip.show();
        }
    }   
    if (statusint == 1) { // Light ON, green LED
        uint32_t color1 = strip.Color(20, 20, 20);
        for (uint16_t i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, color1);
            strip.show();
        }
    }    
    if (statusint == 2) { // ERROR, red LED
        uint32_t color1 = strip.Color(10, 0, 0);
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
    /*if (Serial.available() > 0) { // something came across serial
        integerValue = 0; // throw away previous integerValue
        while (1) { // force into a loop until '\n' is received
            incomingByte = Serial.read();
            if (incomingByte == '\n') break; // exit the while(1), we're done receiving
            if (incomingByte == -1)   continue; // if no characters are in the buffer read() returns -1
            integerValue *= 10; // shift left 1 decimal place
            // convert ASCII to integer, add, and shift left 1 decimal place
            integerValue = ((incomingByte - 48) + integerValue);
            if (incomingByte != -1){
              changeparameter(integerValue);
            }
        }
    }*/
    while(Serial1.available())
    {
      Serial1.readBytes(&b, 1);
      if(32<=b && b<=127 || b=='\r' || b=='\n')
      {
       //buf+="\e[0m";
       buf+=b;
       //Serial.print("\e[0m");
       //Serial.write(b);
      }
      else
      {
        //buf+="\e[31m.";
        //Serial.print("\e[31m.");
      }
    }
    Serial.print(buf);
    long jee = buf.toInt();
    //Serial.print(jee);
    //Serial.print('\n');
    delay(70);
    changeparameter(jee);
    buf=""; 
}

void changeparameter(long value){ // muuttaa min/max arvoja
    if (value >= 5000 && value < 5003) {
        statusint = value - 5000;
       /* Serial.print("statusint=");
        Serial.print(statusint);
        Serial.print("\n");*/
    }
    if (value >= 6000 && value < 6256) {
        fadeValue = value - 6000;
        Serial.print("fadeValue=");
        Serial.print(fadeValue);
        Serial.print("\n");
    }
    if (value >= 7000 && value <= 7001) {
        kytkin = value - 7000;
        Serial.print("kytkin=");
        Serial.print(kytkin);
        Serial.print("\n");
    }
}

/*void changeparameter(long value){ // muuttaa min/max arvoja
    if (value == 5) {
        statusint = value[3];
        Serial.print("statusint=");
        Serial.print(statusint);
        Serial.print("\n");
    }
    if (value[0] == 6) {
        fadeValue = value[1]*100+value[2]*10+value[3];
        Serial.print("fadeValue=");
        Serial.print(fadeValue);
        Serial.print("\n");
    }
    if (value[0] == 7) {
        kytkin = value[3];
        Serial.print("kytkin=");
        Serial.print(kytkin);
        Serial.print("\n");
    }
}*/


