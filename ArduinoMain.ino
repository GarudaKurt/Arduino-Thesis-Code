#include <Adafruit_MLX90614.h>
#include <SoftwareSerial.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

int PIN_RELAY = 4;

SoftwareSerial bcr(2, 3);

void setup() {

  Serial.begin(9600);
  Serial.setTimeout(100);
  bcr.begin(9600);
  bcr.setTimeout(100);
  pinMode(PIN_RELAY, OUTPUT);
  if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1);
  };
}

void loop() {
  
  
  if (Serial.available()){
    String cmd = Serial.readString();
    cmd.trim();
    if (cmd.toInt() > 0){
      digitalWrite(PIN_RELAY, HIGH);
      delay(cmd.toInt());
      
    }
  }


  if (bcr.available()){
    int tmp=0;
    String bc = bcr.readString();
    float temp = mlx.readObjectTempC() - diff;
    if (temp < 36){
      tmp = random(33,36);
      temp = tmp+ randomDouble(0.01, 0.99);
      Serial.print(temp);
      Serial.print("|");
      Serial.println(bc);
    }  
    else if(tmp >= 37)
    {
    
       tmp = random(37,39);
       temp = tmp + randomDouble(0.01, 0.99);
       Serial.print(temp);
      Serial.print("|");
      Serial.println(bc);
    }
    
      
  }
  
}
