void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

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

void statusled(){                         // statusled code  
    if (fadeValue == 0) { // Standby, blue LED
      uint32_t color1 = strip.Color(0, 0, 10);
       for (uint16_t i = 0; i < strip.numPixels(); i++) {
            strip.setPixelColor(i, color1);
           strip.show();
        }
    }   
    if (fadeValue > 0) { // Light ON, green LED
        uint32_t color1 = strip.Color(0, 10, 0);
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
void rgbvalaistus(float fadeValue){
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
