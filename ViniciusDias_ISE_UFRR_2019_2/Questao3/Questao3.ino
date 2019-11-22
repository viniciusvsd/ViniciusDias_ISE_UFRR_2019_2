int matrizPinodosLEDS[] = {2, 3, 4};
boolean balanco = false;
float matrizCores[] = {0, 0, 0};
float matrizBranco[] = {0, 0, 0};
float matrizPreto[] = {0, 0, 0};
int mediaLeituras;

void setup()
{

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 

  Serial.begin(9600);

}

void loop()
{
  checaBalanco();
  checaCores();
  mostraCores();
}

void checaBalanco() {
  if (balanco == false) {
    confBalanco();
  }

}

void confBalanco() {
  
  Serial.println("Calibrando o branco");
  delay(5000);
  for (int i = 0; i <= 2; i++) {
    digitalWrite(matrizPinodosLEDS[i], HIGH);
    delay(100);
    mediaSensor(5);
    matrizBranco[i] = mediaLeituras;
    digitalWrite(matrizPinodosLEDS[i], LOW);
    delay(100);
  }

  Serial.println("Calibrando o preto");
  delay(5000);
  for (int i = 0; i <= 2; i++) {
    digitalWrite(matrizPinodosLEDS[i], HIGH);
    delay(100);
    mediaSensor(5);
    matrizPreto[i] = mediaLeituras;
    digitalWrite(matrizPinodosLEDS[i], LOW);
    delay(100);
  }

  Serial.println("Sensor Calibrado");
  balanco = true;
  delay(3000);
}

void checaCores() {
  for (int i = 0; i <= 2; i++) {
    digitalWrite(matrizPinodosLEDS[i], HIGH);
    delay(100);
    mediaSensor(5);
    matrizCores[i] = mediaLeituras;
    float cinzaDif = matrizBranco[i] - matrizPreto[i];
    matrizCores[i] = (matrizCores[i] - matrizPreto[i]) / (cinzaDif) * 255;
    digitalWrite(matrizPinodosLEDS[i], LOW);
    delay(100);
  }

}


void mediaSensor(int vezes) {
  int leituras;
  int somatorio = 0;
  for (int i = 0; i < vezes; i++) {
    leituras = analogRead(0);
    somatorio = leituras + somatorio;
    delay(10);
  }
  mediaLeituras = (somatorio) / vezes;
}

void mostraCores() {
  Serial.print("R = ");
  Serial.println(int(matrizCores[0]));
  Serial.print("G = ");
  Serial.println(int(matrizCores[1]));
  Serial.print("B = ");
  Serial.println(int(matrizCores[2]));

}
