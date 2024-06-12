const int trigPin_2 = 5; //trig pin connection 
const int echoPin_2 = 4;  //echopin connection 
int ledred_2 = 10;
int ledgreen_2 = 11;
long duration_2;
int distanceCm_2;
char Incoming_value_2 = 0;


                                                                                                            
void setup() {      // setup perameter 
  Serial.begin(9600);                                                 
  pinMode(trigPin_2, OUTPUT);
  pinMode(echoPin_2, INPUT);
  pinMode(ledred_2,OUTPUT);
  pinMode(ledgreen_2,OUTPUT);
}

void loop() {   // loop of flow program
  digitalWrite(trigPin_2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin_2, LOW);
  duration_2 = pulseIn(echoPin_2, HIGH);
  distanceCm_2= duration_2/29/2; 
  if(distanceCm_2<=500){
    Serial.write('C');
  }
  else{
    Serial.write('D');
  }
   Incoming_value_2 = Serial.read();

  if(Incoming_value_2 == 'A'){
    digitalWrite(ledred_2, HIGH);
    digitalWrite(ledgreen_2 ,LOW);
    }
  else if(Incoming_value_2 == 'B'){
    digitalWrite(ledgreen_2 ,HIGH);
    digitalWrite(ledred_2 ,LOW);
    }
}
