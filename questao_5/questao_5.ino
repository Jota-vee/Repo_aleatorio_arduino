#define led 7
char letra;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}
void loop() {
  if (Serial.available()) {
    letra = Serial.read();
    Serial.print(letra);
  }
  if (letra == 'R') {
      digitalWrite(led, HIGH);
    }
  else if (letra == 'G') {
      digitalWrite(led, HIGH);
      delay(200);
      digitalWrite(led, LOW);
      delay(200);
    }
  else if (letra == 'Y') {
      digitalWrite(led, HIGH);
      delay(1000);
      digitalWrite(led, LOW);
      delay(1000);
  }
}