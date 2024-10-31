#include <Wire.h>
#include <TEA5767Radio.h>

const int pot1Pin = A0;  
const int pot2Pin = A1;  

TEA5767Radio radio = TEA5767Radio();
void setup() {
  Serial.begin(9600); 
    Wire.begin();
}

void loop() {

  int pot1Value = analogRead(pot1Pin);
  int pot2Value = analogRead(pot2Pin);


  int mappedPot1Value = map(pot1Value, 0, 1023, 88, 108);

  int mappedPot2Value = map(pot2Value, 0, 1023, 0, 9);


  float finalValue = mappedPot1Value + (mappedPot2Value * 0.1);

  Serial.print("Mapped Pot1 Value: ");
  Serial.print(mappedPot1Value);
  Serial.print("\tMapped Pot2 Value: ");
  Serial.print(mappedPot2Value);
  Serial.print("\tFinal Value: ");
  Serial.println(finalValue);


  radio.setFrequency(finalValue);
}

