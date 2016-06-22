int ledv = 10;
int ledp = 11;
int fadeValue = 0 ;
int lisaa = 51;   //tätä voi säätää kännykällä
 
int buttonPin1 = 8;
int buttonPin2 = 7;
int button1State = 0;
int button2State = 0;
int minValue = 200;  //säädetään apillä
int maxValue = 1; //säädetään apillä

void setup()
{
  Serial.begin(9600);  // Begin the serial monitor at 9600bps
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
}
 
void loop()
{
  //------arduino push button code----------------
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
      fadeValue = 150;
      analogWrite(ledp, fadeValue);
      while (button2State == HIGH && button1State == HIGH){
        button1State = digitalRead(buttonPin1);
        button2State = digitalRead(buttonPin2);
      }
      while(1) {
        button1State = digitalRead(buttonPin1);
        button2State = digitalRead(buttonPin2);
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
            fadeValue = 150;
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
