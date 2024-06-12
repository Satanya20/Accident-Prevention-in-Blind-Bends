#include "nRF24L01.h" //NRF24L01 library created by TMRh20 https://github.com/TMRh20/RF24
#include "RF24.h"
#include "SPI.h"

const int trigPin_1 = 7; //trig pin connection 
const int echoPin_1 = 6;  //echopin connection 
int ledred_1 = 3;
int ledgreen_1 = 4;
long duration_1;
int distanceCm_1;
char Incoming_value = 0;


                                                                                                            
void setup() {      // setup perameter                                                  
  pinMode(trigPin_1, OUTPUT);
  pinMode(echoPin_1, INPUT);
  pinMode(ledred_1,OUTPUT);
  pinMode(ledgreen_1,OUTPUT);
  Serial.begin(9600);
}

void loop() {   // loop of flow program
  digitalWrite(trigPin_1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_1, LOW);
  duration_1 = pulseIn(echoPin_1, HIGH);
  distanceCm_1= duration_1/29/2; 
  if(distanceCm_1<=500){
    Serial.write('A');
  }
  else{
    Serial.write('B');
  }
   Incoming_value = Serial.read();

  if(Incoming_value == 'C'){
    digitalWrite(ledred_1, HIGH);
    digitalWrite(ledgreen_1 ,LOW);
    }
  else if(Incoming_value == 'D'){
    digitalWrite(ledgreen_1 ,HIGH);
    digitalWrite(ledred_1 ,LOW);
    }
}
