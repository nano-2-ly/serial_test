#include <ArduinoJson.h>

#include <Stepper.h>

/*json*/
DynamicJsonDocument doc(1024);

/*stepper motor */
// 2048:한바퀴(360도), 1024:반바퀴(180도)...
const int stepsPerRevolution = 2048; 
// 모터 드라이브에 연결된 핀 IN4, IN2, IN3, IN1
Stepper myStepper(stepsPerRevolution,52,51,50,49); 


void parse_json(char* json){
  auto error = deserializeJson(doc, json);
  if (error) {
      Serial.print(F("deserializeJson() failed with code "));
      Serial.println(error.c_str());
      return;
  }
}

void setup() {
  //serial
  Serial.begin(9600);

  //json
  
  
  //stepper motor
  myStepper.setSpeed(14); 

  //pin option
  for(int i= 36;i<=45;i++){
    pinMode(i, OUTPUT);
  }
  
}
void loop() {
  delay(1000);
  if(Serial.available()){
    String command_str = Serial.readString();
    command_str.trim();

    auto error = deserializeJson(doc, command_str);
    if (error) {
        Serial.print(F("deserializeJson() failed with code "));
        Serial.println(error.c_str());
        return;
    }
    String sensor = doc["sensor"];
    Serial.println(command_str);
    Serial.println(sensor);
    Serial.println("ok");

     
    /*
    parse_json(command_char);
    Serial.println(command_str);
    Serial.println(command_char);
    char desc[] = {};
    desc = doc["desc"];
    Serial.println(desc[0]); 
    */
  }
  /*
  const char* desc = doc["desc"];
  Serial.println(desc); 

  if(desc == "LED_control"){ //PID = 1 -> LED control 
    Serial.println("hello");
    for(int i=0;i<=10;i++){
      if (i==0){
        digitalWrite(i+36, LOW);
      }
      else if (i==1){
        digitalWrite(i+36, HIGH);
      }
    }
  }
  */
  /*
  if(command[0] == "2"){ //PID = 2 -> BLDC motor control
    continue;
  }
  
  if(command[0] == "3"){ //PID = 3 -> BLDC homing control
    continue;
  }

  if(command[0] == "4"){ //PID = 4 -> step motor control
    myStepper.step(stepsPerRevolution);
    delay(500);
  }

  if(command[0] == "5"){ //PID = 5 -> step homing control
    continue;
  }

  if(command[0] == "6"){ //PID = 6 -> laser control
    continue;
  }
  
  if(command[0] == "0"){ //PID = 0 -> status
    
    Serial.println(analogRead(A0));
  }
  Serial.print(analogRead(A0));
  for(int i= 36;i<=45;i++){
    digitalWrite(i, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(10); 

    
  
  Serial.print("PD0 : ");
  Serial.println(analogRead(A0));
  }
  */
  /*
  for(int i= 36;i<=45;i++){
    digitalWrite(i, LOW);   // turn the LED on (HIGH is the voltage level)  
    delay(10); 
  }
  Serial.print("PD0 : ");
  Serial.println(analogRead(A0));
  Serial.print("PD0 : ");
  Serial.println(analogRead(A0));
  Serial.print("PD0 : ");
  Serial.println(analogRead(A0));
  /*
  Serial.println(analogRead(A1));
  Serial.println(analogRead(A2));
  Serial.println(analogRead(A3));
  Serial.println(analogRead(A4));
  Serial.println(analogRead(A5));
  Serial.println(analogRead(A6));
  Serial.println(analogRead(A7));
  Serial.println(analogRead(A8));
  Serial.println(analogRead(A9));
  */
}
