#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int trig = 4;
int echo = 8;
int led_red = 9;
int led_green = 10;
int timeInMicro;
uint16_t distance_1;
uint16_t distance_2;
RF24 radio(6, 7); // CE, CSN
uint8_t addresses[][5] = {"00001", "00002"};

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  radio.begin();
  radio.openWritingPipe(addresses[0]); // 00002
  radio.openReadingPipe(1, addresses[1]); // 00001
  radio.setPALevel(RF24_PA_MIN);
  Serial.begin(9600);
}

void loop() {
  delay(50);

  radio.stopListening();
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  timeInMicro = pulseIn(echo, HIGH, 10000); // Set timeout to 10ms

  distance_2 = timeInMicro / 29 / 2;
  Serial.println(distance_2);
  bool success = radio.write(&distance_2, sizeof(distance_2));
  if (!success) {
    Serial.println("Transmission failed!");
  }
  delay(50);

  radio.startListening();
  unsigned long start_time = millis();
  while (!radio.available()) {
    if (millis() - start_time > 1000) { // Exit loop after 1 second
      break;
    }
  }
  if (radio.available()) {
    radio.read(&distance_1, sizeof(distance_1));
    Serial.print("Distance_1 received: ");
    Serial.println(distance_1);
    if (distance_1>1 && distance_1 <= 20) {
      digitalWrite(led_red, HIGH);
      digitalWrite(led_green, LOW);
      delay(1500);
    } else {
      digitalWrite(led_green, HIGH);
      digitalWrite(led_red, LOW);
    }
  } else {
    digitalWrite(led_green, HIGH);
    digitalWrite(led_red, LOW);
  }
  Serial.println( );
}
