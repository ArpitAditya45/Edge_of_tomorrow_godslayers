nt soundSensor = 2; 
int IRSensor = 4; 
int LED = 13; 
int LEDIR = 12;
int soundLed = 7;

int Sou_Light;
int threshold = 0;
void setup() {
  pinMode (soundSensor, INPUT); // sensor pin INPUT
  pinMode (LED, OUTPUT); // Led pin OUTPUT\
  
}



int  Sound_True(){
  int statusSensor = digitalRead (soundSensor);
  threshold = 0;
  if (statusSensor == 0){
    digitalWrite(LED, LOW); // LED LOW
    
  }
  else{
    digitalWrite(LED, HIGH); // LED High
    threshold++;
    
  }
  return threshold;
  }


void loop(){
  int statusSensor = digitalRead (soundSensor);
  int statusSensorIR = digitalRead (IRSensor);
  pinMode (soundLed, OUTPUT);
  int LED1_timer = millis ();

int p =0;

if (statusSensorIR == 0){
  
  digitalWrite(LEDIR, HIGH);
  while ( (millis () - LED1_timer) <= 15000){
    
    p = p + Sound_True();
    
  }
  if (p>=10){
      digitalWrite(soundLed, HIGH);
      delay(500);
      digitalWrite(soundLed, LOW);
      delay(500);
      digitalWrite(soundLed, HIGH);
      delay(500);
      digitalWrite(soundLed, LOW);
      delay(500);
    }
}

else{
  digitalWrite(LEDIR, LOW);
  
}

  
}