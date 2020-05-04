//PC-Engine rapid fire mod, for the white PC-Engine Mini-controllers.
//2020 Konsolkongen/Bearking  

#include <FastLED.h>

const int buttonSelect = A2;
const int buttonI = A0;
const int buttonII = A1;
const int Irapid = 9;
const int IIrapid = 10;
const int IrapidLED = 8;
const int IIrapidLED = 7;

int buttonImode; // 0 = Normal, 1 = Rapid fire
int buttonIImode; // 0

int buttonSelectState = 0;
int buttonIstate;
int buttonIIstate;
int lastButtonSelectState = 0;
int lastButtonIstate;
int lastButtonIIstate;

unsigned long select_held; // How long the button was held (milliseconds)
unsigned long selectTime;   // How long since the button was first pressed
unsigned long buttonIheld;
unsigned long buttonItime;
unsigned long buttonIIheld;
unsigned long buttonIItime;

void setup()
{
//Serial.begin(9600);
  
  pinMode(buttonSelect, INPUT_PULLUP);
  pinMode(buttonI, INPUT_PULLUP);
  pinMode(buttonII, INPUT_PULLUP);
  pinMode(Irapid, OUTPUT);
  pinMode(IIrapid, OUTPUT);
  pinMode(IrapidLED, OUTPUT);
  pinMode(IIrapidLED, OUTPUT);
}

void loop()
{
//  Serial.print("Time: ");
//  Serial.print(millis());
//  Serial.print(" Since push: ");
//  Serial.print(select_held);
//  Serial.print(" Button: ");
//  Serial.print(buttonSelectState);
//  Serial.print(" Last Button: ");
//  Serial.println(lastButtonSelectState);
  
  buttonIstate = digitalRead(buttonI); // Read the state of the button and move it to the variable.
  buttonIIstate = digitalRead(buttonII);
  buttonSelectState = digitalRead(buttonSelect);

  if (buttonSelectState == LOW && lastButtonSelectState == HIGH) {
    selectTime = millis();  
  }

  if (buttonIstate == LOW && lastButtonIstate == HIGH) {
    buttonItime = millis();
  }

  if (buttonIIstate == LOW && lastButtonIIstate == HIGH) {
    buttonIItime = millis();
  }

  select_held = (millis() - selectTime);
  buttonIheld = (millis() - buttonItime);
  buttonIIheld = (millis() - buttonIItime);

// Every second the button is held, buttonImode will change.
  if (buttonSelectState == LOW && buttonIstate == LOW) {
    EVERY_N_MILLISECONDS(2000) { // Function defined in the FastLED library. Every 2000ms, do the following...
      if (select_held && buttonIheld >= 2000) {
        buttonImode++;
        if (buttonImode > 1) {
          buttonImode = 0;
        }
      }
    }
  }

  if (buttonSelectState == LOW && buttonIIstate == LOW) {
    EVERY_N_MILLISECONDS(2000) {
      if (select_held && buttonIIheld >= 2000) {
        buttonIImode++;
        if (buttonIImode > 1) {
          buttonIImode = 0;
        }
      }  
    }
  }


  switch (buttonImode) {
    case 0: // Normal
      digitalWrite(Irapid, LOW);
      digitalWrite(IrapidLED, LOW);
    break;
 
    case 1: // Rapid fire
      digitalWrite(Irapid, HIGH);
      digitalWrite(IrapidLED, HIGH);
    break;
  }

  switch (buttonIImode) {
    case 0: // Normal
      digitalWrite(IIrapid, LOW);
      digitalWrite(IIrapidLED, LOW);
    break;

    case 1: // Rapid fire
      digitalWrite(IIrapid, HIGH);
      digitalWrite(IIrapidLED, HIGH);
    break;
  }
lastButtonSelectState = buttonSelectState;
lastButtonIstate = buttonIstate;
lastButtonIIstate = buttonIIstate;
}
