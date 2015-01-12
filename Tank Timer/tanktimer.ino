const int timerBuzzer = 12;

const int nickelBtnOn = 2;
const int nickelBtnOff = 3;
const int nickelLEDBusy = 4;
const int nickelLEDDone = 5;
const int nickelTimerDuration = 1080000; // Duration in milliseconds - 18 minutes

const int chromeBtnOn = 6;
const int chromeBtnOff = 7;
const int chromeLEDBusy = 8;
const int chromeLEDDone = 9;
const int chromeTimerDuration = 150000; // Duration in milliseconds - 2.5 minutes

boolean nickelTimerState = false;
unsigned long nickelTimerEpoch = 0;
int nickelBtnOnState = 0;
int nickelBtnOffState = 0;

boolean chromeTimerState = false;
unsigned long chromeTimerEpoch = 0;
int chromeBtnOnState = 0;
int chromeBtnOffState = 0;

void setup(){
  Serial.begin(1200);
  pinMode(nickelBtnOn, INPUT);
  pinMode(nickelBtnOff, INPUT);
  pinMode(nickelLEDBusy, OUTPUT);
  pinMode(nickelLEDDone, OUTPUT);
  
  pinMode(chromeBtnOn, INPUT);
  pinMode(chromeBtnOff, INPUT);
  pinMode(chromeLEDBusy, OUTPUT);
  pinMode(chromeLEDDone, OUTPUT);
}

void  loop() {
  nickelBtnOnState = digitalRead(nickelBtnOn);
  nickelBtnOffState = digitalRead(nickelBtnOff);
  if (nickelBtnOnState == 0) {
    nickelTimerState = true;
  }
  if (nickelBtnOffState == 0) {
    nickelTimerState = false;
    nickelTimerEpoch = 0;
    digitalWrite(nickelLEDBusy, LOW);
    digitalWrite(nickelLEDDone, LOW);
    noTone(timerBuzzer);
  }
  if (nickelTimerState){
    if (nickelTimerEpoch == 0){
      nickelTimerEpoch = millis();
      digitalWrite(nickelLEDBusy, HIGH);
    }
    if (millis() - nickelTimerEpoch >= nickelTimerDuration){
      digitalWrite(nickelLEDBusy, LOW);
      digitalWrite(nickelLEDDone, HIGH);
      tone(timerBuzzer, 1000);
    }
  }

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
  //  Serial.print("Nickel Timer State: ");
  //  Serial.println(nickelTimerState);
  //  Serial.print("Nickel Timer Epoch: ");
  //  Serial.println(nickelTimerEpoch);
  //  Serial.print("Current Time: ");
  //  Serial.println(millis());
}




