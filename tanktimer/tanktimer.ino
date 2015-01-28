const int timerBuzzer = 19;
const unsigned long timerBlinkDuration = 500; // Duration in milliseconds - 0.5 second

// Alkaline
const int alkalineBtnOn = 2;
const int alkalineBtnOff = 3;
const int alkalineLEDBusy = 4;
const int alkalineLEDDone = 5;
const unsigned long alkalineTimerDuration = 180000; // Duration in milliseconds - 3 minutes
const unsigned long alkalineTimerWarning = 150000; // Will trigger 30 seconds before timer end
unsigned long alkalineTimerEpoch = 0;
unsigned long alkalineTimerWarningLast = 0;
boolean alkalineTimerState = false;
int alkalineBtnOnState = 0;
int alkalineBtnOffState = 0;
int alkalineWarningState = 0;
int alkalineWarningLEDState = 0;

// Nickel - One
const int nickel1BtnOn = 6;
const int nickel1BtnOff = 7;
const int nickel1LEDBusy = 8;
const int nickel1LEDDone = 9;
const unsigned long nickel1TimerDuration = 900000; // Duration in milliseconds - 15 minutes
const unsigned long nickel1TimerWarning = 870000; // Will trigger 30 seconds before timer end
unsigned long nickel1TimerEpoch = 0;
unsigned long nickel1TimerWarningLast = 0;
boolean nickel1TimerState = false;
int nickel1BtnOnState = 0;
int nickel1BtnOffState = 0;
int nickel1WarningState = 0;
int nickel1WarningLEDState = 0;

// Nickel - Two
const int nickel2BtnOn = 10;
const int nickel2BtnOff = 11;
const int nickel2LEDBusy = 12;
const int nickel2LEDDone = 13;
const unsigned long nickel2TimerDuration = 900000; // Duration in milliseconds - 15 minutes
const unsigned long nickel2TimerWarning = 870000; // Will trigger 30 seconds before timer end
unsigned long nickel2TimerEpoch = 0;
unsigned long nickel2TimerWarningLast = 0;
boolean nickel2TimerState = false;
int nickel2BtnOnState = 0;
int nickel2BtnOffState = 0;
int nickel2WarningState = 0;
int nickel2WarningLEDState = 0;

// Chrome
const int chromeBtnOn = 14;
const int chromeBtnOff = 15;
const int chromeLEDBusy = 16;
const int chromeLEDDone = 17;
const unsigned long chromeTimerDuration = 120000; // Duration in milliseconds - 2 minutes
const unsigned long chromeTimerWarning = 90000; // Will trigger 30 seconds before timer end
unsigned long chromeTimerEpoch = 0;
unsigned long chromeTimerWarningLast = 0;
boolean chromeTimerState = false;
int chromeBtnOnState = 0;
int chromeBtnOffState = 0;
int chromeWarningState = 0;
int chromeWarningLEDState = 0;

void setup(){
  Serial.begin(115200);//1200);

  // Alkaline
  pinMode(alkalineBtnOn, INPUT);
  pinMode(alkalineBtnOff, INPUT);
  pinMode(alkalineLEDBusy, OUTPUT);
  pinMode(alkalineLEDDone, OUTPUT);

  // Nickel - One
  pinMode(nickel1BtnOn, INPUT);
  pinMode(nickel1BtnOff, INPUT);
  pinMode(nickel1LEDBusy, OUTPUT);
  pinMode(nickel1LEDDone, OUTPUT);

  // Nickel - Two
  pinMode(nickel2BtnOn, INPUT);
  pinMode(nickel2BtnOff, INPUT);
  pinMode(nickel2LEDBusy, OUTPUT);
  pinMode(nickel2LEDDone, OUTPUT);

  // Chrome
  pinMode(chromeBtnOn, INPUT);
  pinMode(chromeBtnOff, INPUT);
  pinMode(chromeLEDBusy, OUTPUT);
  pinMode(chromeLEDDone, OUTPUT);
}

void  loop() {

  // Alkaline
  alkalineBtnOnState = digitalRead(alkalineBtnOn);
  alkalineBtnOffState = digitalRead(alkalineBtnOff);
  if (alkalineBtnOnState == 0) {
    alkalineTimerState = true;
  }
  if (alkalineBtnOffState == 0) {
    alkalineTimerState = false;
    alkalineTimerEpoch = 0;
    digitalWrite(alkalineLEDBusy, LOW);
    digitalWrite(alkalineLEDDone, LOW);
    noTone(timerBuzzer);
    alkalineTimerWarningLast = 0;
    alkalineWarningState = 0;
    alkalineWarningLEDState = 0;
  }
  if (alkalineTimerState){
    if (alkalineTimerEpoch == 0){
      alkalineTimerEpoch = millis();
      digitalWrite(alkalineLEDBusy, HIGH);
    }
    if (millis() - alkalineTimerEpoch >= alkalineTimerDuration - alkalineTimerWarning) {
      if (millis() - alkalineTimerEpoch >= alkalineTimerDuration){
        digitalWrite(alkalineLEDBusy, LOW);
        alkalineWarningState = 0;
        alkalineWarningLEDState = 0;
        digitalWrite(alkalineLEDDone, HIGH);
        tone(timerBuzzer, 1000);
      }
      else {
        if (alkalineWarningState == 1) {
          if (millis() >= alkalineTimerWarningLast + timerBlinkDuration) {
            digitalWrite(alkalineLEDDone, alkalineWarningLEDState);
            alkalineWarningLEDState = !alkalineWarningLEDState;
            alkalineTimerWarningLast = millis();
          }
        }
        else {
          digitalWrite(alkalineLEDDone, HIGH);
          alkalineWarningState = !alkalineWarningState;
          alkalineTimerWarningLast = millis();
        }
      }
    }
  }

  // Nickel - One
  nickel1BtnOnState = digitalRead(nickel1BtnOn);
  nickel1BtnOffState = digitalRead(nickel1BtnOff);
  if (nickel1BtnOnState == 0) {
    nickel1TimerState = true;
  }
  if (nickel1BtnOffState == 0) {
    nickel1TimerState = false;
    nickel1TimerEpoch = 0;
    digitalWrite(nickel1LEDBusy, LOW);
    digitalWrite(nickel1LEDDone, LOW);
    noTone(timerBuzzer);
    nickel1TimerWarningLast = 0;
    nickel1WarningState = 0;
    nickel1WarningLEDState = 0;
  }
  if (nickel1TimerState){
    if (nickel1TimerEpoch == 0){
      nickel1TimerEpoch = millis();
      digitalWrite(nickel1LEDBusy, HIGH);
    }
    if (millis() - nickel1TimerEpoch >= nickel1TimerDuration - nickel1TimerWarning) {
      if (millis() - nickel1TimerEpoch >= nickel1TimerDuration){
        digitalWrite(nickel1LEDBusy, LOW);
        nickel1WarningState = 0;
        nickel1WarningLEDState = 0;
        digitalWrite(nickel1LEDDone, HIGH);
        tone(timerBuzzer, 1000);
      }
      else {
        if (nickel1WarningState == 1) {
          if (millis() >= nickel1TimerWarningLast + timerBlinkDuration) {
            digitalWrite(nickel1LEDDone, nickel1WarningLEDState);
            nickel1WarningLEDState = !nickel1WarningLEDState;
            nickel1TimerWarningLast = millis();
          }
        }
        else {
          digitalWrite(nickel1LEDDone, HIGH);
          nickel1WarningState = !nickel1WarningState;
          nickel1TimerWarningLast = millis();
        }
      }
    }
  }

  // Nickel - Two
  nickel2BtnOnState = digitalRead(nickel2BtnOn);
  nickel2BtnOffState = digitalRead(nickel2BtnOff);
  if (nickel2BtnOnState == 0) {
    nickel2TimerState = true;
  }
  if (nickel2BtnOffState == 0) {
    nickel2TimerState = false;
    nickel2TimerEpoch = 0;
    digitalWrite(nickel2LEDBusy, LOW);
    digitalWrite(nickel2LEDDone, LOW);
    noTone(timerBuzzer);
    nickel2TimerWarningLast = 0;
    nickel2WarningState = 0;
    nickel2WarningLEDState = 0;
  }
  if (nickel2TimerState){
    if (nickel2TimerEpoch == 0){
      nickel2TimerEpoch = millis();
      digitalWrite(nickel2LEDBusy, HIGH);
    }
    if (millis() - nickel2TimerEpoch >= nickel2TimerDuration - nickel2TimerWarning) {
      if (millis() - nickel2TimerEpoch >= nickel2TimerDuration){
        digitalWrite(nickel2LEDBusy, LOW);
        nickel2WarningState = 0;
        nickel2WarningLEDState = 0;
        digitalWrite(nickel2LEDDone, HIGH);
        tone(timerBuzzer, 1000);
      }
      else {
        if (nickel2WarningState == 1) {
          if (millis() >= nickel2TimerWarningLast + timerBlinkDuration) {
            digitalWrite(nickel2LEDDone, nickel2WarningLEDState);
            nickel2WarningLEDState = !nickel2WarningLEDState;
            nickel2TimerWarningLast = millis();
          }
        }
        else {
          digitalWrite(nickel2LEDDone, HIGH);
          nickel2WarningState = !nickel2WarningState;
          nickel2TimerWarningLast = millis();
        }
      }
    }
  }

  // Chrome
  chromeBtnOnState = digitalRead(chromeBtnOn);
  chromeBtnOffState = digitalRead(chromeBtnOff);
  if (chromeBtnOnState == 0) {
    chromeTimerState = true;
  }
  if (chromeBtnOffState == 0) {
    chromeTimerState = false;
    chromeTimerEpoch = 0;
    digitalWrite(chromeLEDBusy, LOW);
    digitalWrite(chromeLEDDone, LOW);
    noTone(timerBuzzer);
    chromeTimerWarningLast = 0;
    chromeWarningState = 0;
    chromeWarningLEDState = 0;
  }
  if (chromeTimerState){
    if (chromeTimerEpoch == 0){
      chromeTimerEpoch = millis();
      digitalWrite(chromeLEDBusy, HIGH);
    }
    if (millis() - chromeTimerEpoch >= chromeTimerDuration - chromeTimerWarning) {
      if (millis() - chromeTimerEpoch >= chromeTimerDuration){
        digitalWrite(chromeLEDBusy, LOW);
        chromeWarningState = 0;
        chromeWarningLEDState = 0;
        digitalWrite(chromeLEDDone, HIGH);
        tone(timerBuzzer, 1000);
      }
      else {
        if (chromeWarningState == 1) {
          if (millis() >= chromeTimerWarningLast + timerBlinkDuration) {
            digitalWrite(chromeLEDDone, chromeWarningLEDState);
            chromeWarningLEDState = !chromeWarningLEDState;
            chromeTimerWarningLast = millis();
          }
        }
        else {
          digitalWrite(chromeLEDDone, HIGH);
          chromeWarningState = !chromeWarningState;
          chromeTimerWarningLast = millis();
        }
      }
    }
  }

  // Debugging
  //  if (nickel1TimerState) {
  //    Serial.print("Milliseconds: ");
  //    Serial.println(millis());
  //    Serial.print("Timer Epoch: ");
  //    Serial.println(nickel1TimerEpoch);
  //    Serial.print("Time elapsed: ");
  //    Serial.println(millis() - nickel1TimerEpoch);
  //    Serial.print("Timer Duration: ");
  //    Serial.println(nickel1TimerDuration);
  //  }

}
