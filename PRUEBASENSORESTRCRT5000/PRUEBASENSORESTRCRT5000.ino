// Definimos la constante para el pin del sensor
const int TCRT5000R = 20;
const int TCRT5000L = 19;

void setup() {

  // Iniciamos la comunicación serial a 9600 baudios
  Serial.begin(9600);
  pinMode(TCRT5000L, INPUT);
  pinMode(TCRT5000R, INPUT);
}

void loop() {
    int sensorLeft = digitalRead(TCRT5000L);
  int sensorRight = digitalRead(TCRT5000R);
  Serial.println(sensorLeft);
  Serial.println(sensorRight);
  Serial.println("------------------------");
  delay(200);
}
