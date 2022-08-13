class TSprayer{
  private:
    int PIN_SENSOR = A0;
    int PIN_RELAY = A3;
    uint32_t interval;
  public:
    void init(int aSensorPin, int aRelayPin);
    void run();
};

void TSprayer::init(int aSensorPin, int aRelayPin){
  PIN_SENSOR = aSensorPin;
  PIN_RELAY = aRelayPin;
  pinMode(PIN_SENSOR, INPUT);
  pinMode(PIN_RELAY, OUTPUT);
}

void TSprayer::run(){
  if(digitalRead(PIN_SENSOR) == LOW)
    interval = (millis() + 3000) /1000;

  if (millis()/1000 > interval)
    digitalWrite(PIN_RELAY, HIGH);
  else
    digitalWrite(PIN_RELAY, LOW);
  Serial.println(interval);
}
