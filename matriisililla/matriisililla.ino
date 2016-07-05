// ledikirjasto
#include <Adafruit_NeoPixel.h>
#define STATUSPIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(9, STATUSPIN, NEO_GRB + NEO_KHZ800);

// pinnien alustaminen
int ledv = 10;
int ledp = 11;
int analogPin = 1;
int buttonPin1 = 8;
int buttonPin2 = 7;
int button1State = 0;
int button2State = 0;

//apilla saadettavat muuttujat
int lisaa = 51;
float minvalue = 0;
float maxvalue = 255;

// muita globaaleja muuttujia
float valiarvo = 0;
int arvo = 0;
float fadeValue = 0;
int statusint = 0;             // 0 standby, 1 on, 2 off
unsigned int integerValue = 0; // Max value is 65535
char incomingByte;

//alustetaan arduino
void setup(){
    Serial.begin(9600); // Begin the serial monitor at 9600bps
    pinMode(buttonPin1, INPUT);
    pinMode(buttonPin2, INPUT);
    strip.begin();
    strip.show();   
}


//main looppi
void loop(){
    statusled();
    serialfunc();
    button1State = digitalRead(buttonPin1);
    button2State = digitalRead(buttonPin2);
    
    if (button1State == LOW && button2State == LOW) {   //pot
        buttonfunc1();
    }   
    if (button1State == HIGH && button2State == LOW) {  //+light
        buttonfunc2(button1State, button2State);
    }    
    if (button1State == LOW && button2State == HIGH) {  //-light
        buttonfunc3(button1State, button2State);
    }   
    if (button1State == HIGH && button2State == HIGH) { //vled on/off
        buttonfunc4(button1State, button2State);
    }
}

//Funktioita
void millisdelay(unsigned long aika){     //viive
    unsigned long currentMillis = millis();
    unsigned long previousMillis = currentMillis;
    while ((currentMillis - previousMillis) < aika) {
        currentMillis = millis();
        serialfunc();
    }
}

void serialfunc(){                        //ottaa vastaan dataa
    if (Serial.available() > 0) { // something came across serial
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
    }
}

void changeparameter(unsigned int value){ // muuttaa min/max arvoja
    if (value >= 1000 && value < 1255) {
        minvalue = value - 1000;
        Serial.print("Min=");
        Serial.print(minvalue);
        Serial.print("\n");
    }
    if (value > 2000+minvalue && value < 2256) {
        maxvalue = value - 2000;
        Serial.print("Max=");
        Serial.print(maxvalue);
        Serial.print("\n");
    }
    if (value > 3000 && value < 3256) {
        lisaa = value - 3000;
        Serial.print("Lisaa=");
        Serial.print(lisaa);
        Serial.print("\n");
    }
}

void statusled(){                         // statusled code  
    if (fadeValue == 0) { // Standby, blue LED
        uint32_t color = strip.Color(0, 0, 10);
        for (uint16_t i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, color);
            strip.show();
        }
    }   
    if (fadeValue > 0) { // Light ON, green LED
        uint32_t color = strip.Color(0, 10, 0);
        for (uint16_t i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, color);
            strip.show();
        }
    }    
    if (statusint == 2) { // ERROR, red LED
        uint32_t color = strip.Color(10, 0, 0);
        for (uint16_t i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, color);
            strip.show();
        }
    }
}

//LED-funktiot
void buttonfunc1() { // pot
        arvo = analogRead(analogPin) / 4;
        if (valiarvo - 10 > arvo || arvo > valiarvo + 10) {
            valiarvo = arvo;
            Serial.print(valiarvo);
            Serial.print("\n");
            fadeValue = (((maxvalue - minvalue)/255)*valiarvo)+minvalue;
            Serial.print("minV");
            Serial.print(minvalue);
            Serial.print("maxV");
            Serial.print(maxvalue);
            Serial.print("fV");
            Serial.print(fadeValue);
            Serial.print("\n");
            if (fadeValue < 10) {
                fadeValue = 0;
            }
            analogWrite(ledv, fadeValue);
            analogWrite(ledp, fadeValue);
        }        
    
}

void buttonfunc2(int button1State, int button2State) { // +light
    fadeValue = fadeValue + lisaa ;
    if (fadeValue > maxvalue) {
        fadeValue = maxvalue;
    }
    if (fadeValue < minvalue) {
        fadeValue = minvalue;
            }
    // sets the value (range from 0 to 255):
    analogWrite(ledv, fadeValue);
    analogWrite(ledp, fadeValue);
    // wait for 200 milliseconds to set max);
    millisdelay(200);
    button1State = digitalRead(buttonPin1);
    if (button1State == HIGH) {
        analogWrite(ledv, maxvalue);
        analogWrite(ledp, maxvalue);
        fadeValue = maxvalue;
        while (button1State == HIGH && button2State == LOW) {
            button1State = digitalRead(buttonPin1);
            button2State = digitalRead(buttonPin2);
        }
    }
}

void buttonfunc3(int button1State, int button2State) { // -light
    fadeValue = fadeValue - lisaa ;
    if (fadeValue < minvalue) {
        fadeValue = minvalue;
    }
    // sets the value (range from 0 to 255):
    analogWrite(ledv, fadeValue);
    analogWrite(ledp, fadeValue);
    // wait for 200 milliseconds to set off
    millisdelay(200);
    button2State = digitalRead(buttonPin2);
    if (button2State == HIGH) {
        digitalWrite(ledv, LOW);
        digitalWrite(ledp, LOW);
        fadeValue = 0;
        while (button2State == HIGH && button1State == LOW) {
            button1State = digitalRead(buttonPin1);
            button2State = digitalRead(buttonPin2);
        }
    }
}

void buttonfunc4(int button1State, int button2State) { // VIHREÃ„POISSA
    analogWrite(ledv, LOW);
    fadeValue = (maxvalue+minvalue)/2;
    analogWrite(ledp, fadeValue);
    while (button2State == HIGH && button1State == HIGH) {
        button1State = digitalRead(buttonPin1);
        button2State = digitalRead(buttonPin2);
    }
<<<<<<< HEAD
    while (1) {
        statusled();
        serialfunc();
        button1State = digitalRead(buttonPin1);
        button2State = digitalRead(buttonPin2);
        if (button1State == LOW && button2State == LOW) {
            arvo = analogRead(analogPin) / 4;
            if (valiarvo - 10 > arvo || arvo > valiarvo + 10) {
                valiarvo = arvo;
                fadeValue = (((maxvalue - minvalue)/255)*valiarvo)+minvalue;
                if (fadeValue < 10) {
                    fadeValue = 0;
                }
                analogWrite(ledp, fadeValue);
            }
=======
}
void buttonfunc5(int button1State, int button2State) {
    // VIHREÄPOISSA
    if (button2State == HIGH && button1State == HIGH) {
        analogWrite(ledv, LOW);
        fadeValue = 153;
        analogWrite(ledp, fadeValue);
        while (button2State == HIGH && button1State == HIGH) {
            button1State = digitalRead(buttonPin1);
            button2State = digitalRead(buttonPin2);
>>>>>>> origin/master
        }
        if (button1State == HIGH && button2State == LOW) {
            fadeValue = fadeValue + lisaa ;
            if (fadeValue > maxvalue) {
                fadeValue = maxvalue;
            }
            if (fadeValue < minvalue) {
                fadeValue = minvalue;
            }
            // sets the value (range from 0 to 255):
            analogWrite(ledp, fadeValue);
            // wait for 200 milliseconds to set max
            millisdelay(200);
            button1State = digitalRead(buttonPin1);
            if (button1State == HIGH) {
                analogWrite(ledp, maxvalue);
                fadeValue = maxvalue;
                while (button1State == HIGH && button2State == LOW) {
                    button1State = digitalRead(buttonPin1);
                    button2State = digitalRead(buttonPin2);
                }
            }
        }
            
        if (button2State == HIGH && button1State == LOW) {
            fadeValue = fadeValue - lisaa ;
            if (fadeValue < minvalue) {
                fadeValue = minvalue;
            }
            // sets the value (range from 0 to 255):
            analogWrite(ledp, fadeValue);
            // wait for 200 milliseconds to set off
            millisdelay(200);
            button2State = digitalRead(buttonPin2);
            if (button2State == HIGH) {
                digitalWrite(ledp, LOW);
                fadeValue = 0;
                while (button2State == HIGH && button1State == LOW) {
                   button1State = digitalRead(buttonPin1);
                   button2State = digitalRead(buttonPin2);
                }
            }
        }
        if (button1State == HIGH && button2State == HIGH) {
            fadeValue = (maxvalue+minvalue)/2;
            analogWrite(ledv, fadeValue);
            analogWrite(ledp, fadeValue);
            while (button1State == HIGH && button1State == HIGH) {
                button1State = digitalRead(buttonPin1);
                button2State = digitalRead(buttonPin2);
            }
            break;
        }
    }
}