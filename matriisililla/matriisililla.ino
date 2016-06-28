#include <Adafruit_NeoPixel.h>

#define STATUSPIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(9, STATUSPIN, NEO_GRB + NEO_KHZ800);

int ledv = 10;
int ledp = 11;
int analogPin = 1;
unsigned char valiarvo = 0;
unsigned char arvo = 0;
unsigned char fadeValue = 0 ;
unsigned char lisaa = 51;   //tätä voi säätää kännykällä
 
int buttonPin1 = 8;
int buttonPin2 = 7;
int button1State = 0;
int button2State = 0;
unsigned char minValue = 204;  //säädetään apillä
unsigned char maxValue = 51; //säädetään apillä
int statusint = 0; // 0 standby, 1 on, 2 off

void setup()
{
  Serial.begin(9600);  // Begin the serial monitor at 9600bps
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  strip.begin();
  strip.show();
}
 
void loop()
{
// status led code
if (fadeValue == 0) {
uint32_t color = strip.Color(0,0,10);
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
  }
}

if (fadeValue > 0) {
uint32_t color = strip.Color(0,10,0);
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
  }
}

if (statusint == 2) {
uint32_t color = strip.Color(10,0,0);
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
  }
}
  
  //------arduino push button code----------------
if (button1State == LOW && button2State == LOW) {  
  arvo=analogRead(analogPin)/4;  
   if (valiarvo-3 > arvo || arvo > valiarvo+3){
     valiarvo = arvo;
     fadeValue=valiarvo;
     if (fadeValue < 4){
      fadeValue =0;
     }
   }
     analogWrite(ledv, fadeValue);
     analogWrite(ledp, fadeValue);
}

  
  button1State = digitalRead(buttonPin1);
  button2State = digitalRead(buttonPin2);
  if (button1State == HIGH && button2State == LOW) {    
     fadeValue = fadeValue+lisaa ;
     // sets the value (range from 0 to 255):
     analogWrite(ledv, fadeValue);
     analogWrite(ledp, fadeValue);
     // wait for 200 milliseconds to set max);
     delay(200);
     button1State = digitalRead(buttonPin1);
     if (button1State == HIGH){
        digitalWrite(ledv, HIGH);
        digitalWrite(ledp, HIGH);
        fadeValue = 255;
        while (button1State == HIGH && button2State == LOW){
          button1State = digitalRead(buttonPin1);
          button2State = digitalRead(buttonPin2);
        }
     }
  }
  
    if (button2State == HIGH && button1State == LOW){
        fadeValue = fadeValue-lisaa ;
        // sets the value (range from 0 to 255):
        analogWrite(ledv, fadeValue);
        analogWrite(ledp, fadeValue);
        // wait for 200 milliseconds to set off
        delay(200);
        //kekkee
        button2State = digitalRead(buttonPin2);
        if (button2State == HIGH) {
            digitalWrite(ledv, LOW);
            digitalWrite(ledp, LOW);
            fadeValue = 0;
            while (button2State == HIGH && button1State == LOW){
                button1State = digitalRead(buttonPin1);
                button2State = digitalRead(buttonPin2);
            }
        }
    }
    // VIHREÄPOISSA
  if (button2State == HIGH && button1State == HIGH) {
      analogWrite(ledv, LOW);
      fadeValue = 153;
      analogWrite(ledp, fadeValue);
      while (button2State == HIGH && button1State == HIGH){
        button1State = digitalRead(buttonPin1);
        button2State = digitalRead(buttonPin2);
      }
      while(1) {
        // status led code
if (fadeValue == 0) {
uint32_t color = strip.Color(0,0,10);
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
  }
}

if (fadeValue > 0) {
uint32_t color = strip.Color(0,10,0);
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
  }
}

if (statusint == 2) {
uint32_t color = strip.Color(10,0,0);
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
  }
}        
        button1State = digitalRead(buttonPin1);
        button2State = digitalRead(buttonPin2);
        if (button1State == LOW && button2State == LOW) {  
  arvo=analogRead(analogPin)/4;  
   if (valiarvo-3 > arvo || arvo > valiarvo+3){
     valiarvo = arvo;
     fadeValue=valiarvo;
     if (fadeValue < 4){
      fadeValue =0;
     }
   }
     analogWrite(ledp, fadeValue);
} 
        if (button1State == HIGH && button2State == LOW) {
            fadeValue = fadeValue+lisaa ;
            // sets the value (range from 0 to 255):
            analogWrite(ledp, fadeValue);
            // wait for 200 milliseconds to set max
            delay(200);
            button1State = digitalRead(buttonPin1);
            if (button1State == HIGH) {
                digitalWrite(ledp, HIGH);
                fadeValue = 255;
                while (button1State == HIGH && button2State == LOW){
                button1State = digitalRead(buttonPin1);
                button2State = digitalRead(buttonPin2);
                }
            }
        }
  
        if (button2State == HIGH && button1State == LOW){
            fadeValue = fadeValue-lisaa ;
            // sets the value (range from 0 to 255):
            analogWrite(ledp, fadeValue);
            // wait for 200 milliseconds to set off
            delay(200);
            button2State = digitalRead(buttonPin2);
            if (button2State == HIGH) {
                digitalWrite(ledp, LOW);
                fadeValue = 0;
                while (button2State == HIGH && button1State == LOW){
                    button1State = digitalRead(buttonPin1);
                    button2State = digitalRead(buttonPin2);
                }
            }
        }
        if (button1State == HIGH && button2State == HIGH) {
            fadeValue = 153;
            analogWrite(ledv, fadeValue);
            analogWrite(ledp, fadeValue);
            while (button1State == HIGH && button1State == HIGH){
                button1State = digitalRead(buttonPin1);
                button2State = digitalRead(buttonPin2);
            }
            break;
        }
      }
    }
  }
  // oketgoethoeh
