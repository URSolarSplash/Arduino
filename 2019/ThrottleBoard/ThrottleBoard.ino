#include <statelessTelemetryNode.h>

float rawThrottle = 0;

bool throttleEnable = false;
bool throttleMode = false;
bool boatConfig = false; // false = endurance, true = sprint

int deadzoneSize = 10;

ThrottleNode throttleNode(&Serial,100);

void setup() {
  pinMode(5,OUTPUT); //yellow
  pinMode(6,OUTPUT); //green
  pinMode(9,OUTPUT); //red
  
  pinMode(7,INPUT_PULLUP); // Dead man's switch and motor enable switch (SAFETY)
  pinMode(8,INPUT_PULLUP); // boat configuration switch (repurposed from ENABLE switch)
  pinMode(10,INPUT_PULLUP); // Throttle mode (MODE)

}

void loop() {
  
  // Add dead zone on either end when reading throttle
  // Bottom and top have area where they are mapped to 0 and 255
  // this corrects for minor errors in sensing so it's easier to have 
  // throttle *completely off* or *completely on*
  rawThrottle = map(analogRead(A1),0 + deadzoneSize,1023 - deadzoneSize,0,255);
  throttleNode.throt = (uint16_t)constrain(rawThrottle,0,255);

  throttleEnable = !digitalRead(7);
  boatConfig = !digitalRead(8);
  throttleMode = !digitalRead(10);

  throttleNode.mode = throttleMode;
  throttleNode.enable = throttleEnable;
  throttleNode.config = boatConfig;

  // Write status LEDs
  digitalWrite(6,throttleMode);
  digitalWrite(5,throttleEnable);
  analogWrite(9,throttleNode.throt);

  throttleNode.update();
}

