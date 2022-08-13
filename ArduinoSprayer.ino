#include "uSprayer.h"

TSprayer spray1, spray2;

void setup() {
  digitalWrite(A2, LOW);
  digitalWrite(A3, LOW);
  Serial.begin(9600);
  spray1.init(A0, A2);
  spray2.init(A1, A3);
}

void loop() {
  spray1.run();
  spray2.run();
}
