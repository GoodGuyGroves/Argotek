const int timerBuzzer = 19;

// Alkaline
const int alkalineBtnOn = 3;
const int alkalineBtnOff = 4;
const int alkalineLEDBusy = 5;
const int alkalineLEDDone = 6;
const unsigned long alkalineTimerDuration = 180000; // Duration in milliseconds - 3 minutes

// Nickel - One
const int nickel1BtnOn = 7;
const int nickel1BtnOff = 8;
const int nickel1LEDBusy = 9;
const int nickel1LEDDone = 10;
const unsigned long nickel1TimerDuration = 900000; // Duration in milliseconds - 15 minutes

// Nickel - Two
const int nickel2BtnOn = 11;
const int nickel2BtnOff = 12;
const int nickel2LEDBusy = 13;
const int nickel2LEDDone = 14;
const unsigned long nickel2TimerDuration = 900000; // Duration in milliseconds - 15 minutes

// Chrome
const int chromeBtnOn = 15;
const int chromeBtnOff = 16;
const int chromeLEDBusy = 17;
const int chromeLEDDone = 18;
const unsigned long chromeTimerDuration = 120000; // Duration in milliseconds - 2 minutes

// Alkaline
boolean alkalineTimerState = false;
unsigned long alkalineTimerEpoch = 0;
int alkalineBtnOnState = 0;
int alkalineBtnOffState = 0;

// Nickel - One
boolean nickel1TimerState = false;
unsigned long nickel1TimerEpoch = 0;
int nickel1BtnOnState = 0;
int nickel1BtnOffState = 0;

// Nickel - Two
boolean nickel2TimerState = false;
unsigned long nickel2TimerEpoch = 0;
int nickel2BtnOnState = 0;
int nickel2BtnOffState = 0;

// Chrome
boolean chromeTimerState = false;
unsigned long chromeTimerEpoch = 0;
int chromeBtnOnState = 0;
int chromeBtnOffState = 0;

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
  }
  if (alkalineTimerState){
    if (alkalineTimerEpoch == 0){
      alkalineTimerEpoch = millis();
      digitalWrite(alkalineLEDBusy, HIGH);
    }
    if (millis() - alkalineTimerEpoch >= alkalineTimerDuration){
      digitalWrite(alkalineLEDBusy, LOW);
      digitalWrite(alkalineLEDDone, HIGH);
      tone(timerBuzzer, 1000);
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
  }
  if (nickel1TimerState){
    if (nickel1TimerEpoch == 0){
      nickel1TimerEpoch = millis();
      digitalWrite(nickel1LEDBusy, HIGH);
    }
    if (millis() - nickel1TimerEpoch >= nickel1TimerDuration){
      digitalWrite(nickel1LEDBusy, LOW);
      digitalWrite(nickel1LEDDone, HIGH);
      tone(timerBuzzer, 1000);
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
  }
  if (nickel2TimerState){
    if (nickel2TimerEpoch == 0){
      nickel2TimerEpoch = millis();
      digitalWrite(nickel2LEDBusy, HIGH);
    }
    if (millis() - nickel2TimerEpoch >= nickel2TimerDuration){
      digitalWrite(nickel2LEDBusy, LOW);
      digitalWrite(nickel2LEDDone, HIGH);
      tone(timerBuzzer, 1000);
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
  }
  if (chromeTimerState){
    if (chromeTimerEpoch == 0){
      chromeTimerEpoch = millis();
      digitalWrite(chromeLEDBusy, HIGH);
    }
    if (millis() - chromeTimerEpoch >= chromeTimerDuration){
      digitalWrite(chromeLEDBusy, LOW);
      digitalWrite(chromeLEDDone, HIGH);
      tone(timerBuzzer, 1000);
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
