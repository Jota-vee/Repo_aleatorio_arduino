#define led 7
bool palindromo;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}
void loop() {
  palindromo = true;
  if (Serial.available()) {
    String palavra = Serial.readString();
    if (palavra.length() == 1){
      Serial.print(1);
    }
    else if (palavra.length()%2 == 0) {
      for (int i=0;i<(palavra.length()/2);i++) {
        if (palavra[i] != palavra[palavra.length()-1-i]) {
          palindromo = false;
          break;
        }
      }
    }
    else {
      for (int i=0;i<(((palavra.length()+1)/2)-1);i++) {
        if (palavra[i] != palavra[palavra.length()-1-i]) {
          palindromo = false;
          break;
        }
      }
    }
    if (palindromo) {
      for (int i=0;i<3;i++) {
        digitalWrite(led, HIGH);
        delay(200);
        digitalWrite(led, LOW);
        delay(200);
      }
    }
    else {
      for (int i=0;i<3;i++) {
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
        delay(1000);
      }
    }
  }
}