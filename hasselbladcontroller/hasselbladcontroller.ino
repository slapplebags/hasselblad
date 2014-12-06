#define MAX_DELAY 60u   //Maximum desired delay time (seconds)
#define PULSE_ON 350u   //Pulse on time (milliseconds)

int potentiometer;
int projectorPin = 13;

void setup(){
  pinMode(projectorPin, OUTPUT);
  potentiometer = analogRead(A0);
  Serial.begin(9600);
}

void changeSlide(){
  digitalWrite(projectorPin, HIGH);
  delay(PULSE_ON);
  digitalWrite(projectorPin, LOW);
}

void loop(){
  long desiredDelay = (((long)(((((float)analogRead(A0))/1023) * 60000))) / 1000) * 1000;
  if(desiredDelay > 0) delay(desiredDelay - PULSE_ON);
  else delay(desiredDelay);
  Serial.println(desiredDelay);
  changeSlide();
}
