// Definimos las constantes para los pines
const int ENA = 10;
const int IN1 = 7;
const int IN2 = 6;
const int IN3 = 5;
const int IN4 = 4;
const int TCRT5000R = 20;
const int TCRT5000L = 19;

void setup() {

  delay(5000);

  // Configuramos los pines como salidas
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(TCRT5000L, INPUT);
  pinMode(TCRT5000R, INPUT);
  // Iniciamos la comunicación serial a 9600 baudios
  Serial.begin(9600);
}

void loop() {
  // Hacemos girar el motor en una dirección durante 2 segundos
  /*
    RUEDA DERECHA
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
    RUEDA IZQUIERDA
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
  */

  int sensorLeft = digitalRead(TCRT5000L);
  int sensorRight = digitalRead(TCRT5000R);
  Serial.println(sensorLeft);
  Serial.println(sensorRight);

  if (sensorLeft == 0 && sensorRight == 0) {
    forwardRight();
    forwardLeft();
  } else if (sensorLeft == 0 && sensorRight == 1) {
    forwardLeft();
  } else if (sensorLeft == 1 && sensorRight == 0) {
    forwardRight();
  } else {
      forwardRight();
    }

  delay(1000);
}
void forwardRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 50);
}

void forwardLeft() {
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 50);
}