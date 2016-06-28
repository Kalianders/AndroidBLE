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
unsigned char lisaa = 51;
unsigned char minvalue = 0;
unsigned char maxvalue = 255;

// muita globaaleja muuttujia
unsigned char valiarvo = 0;
unsigned char arvo = 0;
int fadeValue = 0 ;
int statusint = 0; // 0 standby, 1 on, 2 off
unsigned int integerValue = 0; // Max value is 65535
char incomingByte;

//alustetaan arduino

void setup()
{
  Serial.begin(9600);  // Begin the serial monitor at 9600bps
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  strip.begin();
  strip.show();

}


//main looppi
void loop()
{
  statusled();
  serialfunc();
  button1State = digitalRead(buttonPin1);
  button2State = digitalRead(buttonPin2);

  buttonfunc1(button1State, button2State);
  buttonfunc2(button1State, button2State);
  buttonfunc3(button1State, button2State);
  buttonfunc4(button1State, button2State);
  buttonfunc5(button1State, button2State);
  buttonfunc6(button1State, button2State);









}


void millisdelay(unsigned long aika) {
  unsigned long currentMillis = millis();
  unsigned long previousMillis = currentMillis;
  while ((currentMillis - previousMillis) < aika) {
    currentMillis = millis();
    serialfunc();
  }
}


void serialfunc() {

  if (Serial.available() > 0) {   // something came across serial
    integerValue = 0;         // throw away previous integerValue
    while (1) {           // force into a loop until 'n' is received
      incomingByte = Serial.read();
      if (incomingByte == '\n') break;   // exit the while(1), we're done receiving
      if (incomingByte == -1) continue;  // if no characters are in the buffer read() returns -1
      integerValue *= 10;  // shift left 1 decimal place
      // convert ASCII to integer, add, and shift left 1 decimal place
      integerValue = ((incomingByte - 48) + integerValue);
      if (incomingByte != -1) changeparameter(integerValue);
    }
    Serial.println(integerValue);   // Do something with the value
  }
}


void changeparameter(unsigned int value) {
  if (value >= 1000 && value < 2000) {
    minvalue = value - 1000;
  }
  if (value > 2000 && value < 3000) {
    maxvalue = value - 2000;
  }
  Serial.print("ok");
}

// statusled code
void statusled() {

  if (fadeValue == 0) {        // Standby, blue LED
    uint32_t color = strip.Color(0, 0, 10);
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, color);
      strip.show();
    }
  }

  if (fadeValue > 0) {        // Light ON, green LED
    uint32_t color = strip.Color(0, 10, 0);
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, color);
      strip.show();
    }
  }

  if (statusint == 2) {      // ERROR, red LED
    uint32_t color = strip.Color(10, 0, 0);
    for (uint16_t i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, color);
      strip.show();
    }
  }
}
void buttonfunc1(int button1State, int button2State) {
  if (button1State == LOW && button2State == LOW) {
    arvo = analogRead(analogPin) / 4;
    if (valiarvo - 10 > arvo || arvo > valiarvo + 10) {
      Serial.print(arvo);
      Serial.print("\n");
      valiarvo = arvo;
      fadeValue = valiarvo * (maxvalue - minvalue) / 255 + minvalue;
      if (fadeValue < 10) {
        fadeValue = 0;
      }
    }
    analogWrite(ledv, fadeValue);
    analogWrite(ledp, fadeValue);
  }
}
void buttonfunc2(int button1State, int button2State) {
  if (button1State == LOW && button2State == LOW) {
    arvo = analogRead(analogPin) / 4;
    if (valiarvo - 10 > arvo || arvo > valiarvo + 10) {
      Serial.print(arvo);
      Serial.print("\n");
      valiarvo = arvo;
      fadeValue = valiarvo * (maxvalue - minvalue) / 255 + minvalue;
      if (fadeValue < 10) {
        fadeValue = 0;
      }
    }
    analogWrite(ledv, fadeValue);
    analogWrite(ledp, fadeValue);
  }
}



void buttonfunc3(int button1State, int button2State) {
  if (button1State == HIGH && button2State == LOW) {
    fadeValue = fadeValue + lisaa ;
    if (fadeValue > maxvalue) {
      fadeValue = maxvalue;
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
}
void buttonfunc4(int button1State, int button2State) {
  if (button2State == HIGH && button1State == LOW) {
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
    }
    while (1) {
      statusled();
      button1State = digitalRead(buttonPin1);
      button2State = digitalRead(buttonPin2);
      if (button1State == LOW && button2State == LOW) {
        arvo = analogRead(analogPin) / 4;
        if (valiarvo - 10 > arvo || arvo > valiarvo + 10) {
          valiarvo = arvo;
          fadeValue = valiarvo;
          if (fadeValue < 10) {
            fadeValue = 0;
          }
        }
        analogWrite(ledp, fadeValue);
      }
      if (button1State == HIGH && button2State == LOW) {
        fadeValue = fadeValue + lisaa ;
        // sets the value (range from 0 to 255):
        analogWrite(ledp, fadeValue);
        // wait for 200 milliseconds to set max
        millisdelay(200);
        button1State = digitalRead(buttonPin1);
        if (button1State == HIGH) {
          digitalWrite(ledp, HIGH);
          fadeValue = 255;
          while (button1State == HIGH && button2State == LOW) {
            button1State = digitalRead(buttonPin1);
            button2State = digitalRead(buttonPin2);
          }
        }
      }
    }
    void buttonfunc6(int button1State, int button2State) {
      if (button2State == HIGH && button1State == LOW) {
        fadeValue = fadeValue - lisaa ;
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
        fadeValue = 153;
        analogWrite(ledv, fadeValue);
        analogWrite(ledp, fadeValue);
        while (button1State == HIGH && button1State == HIGH) {
          button1State = digitalRead(buttonPin1);
          button2State = digitalRead(buttonPin2);
        }
        break;
      }
    }
