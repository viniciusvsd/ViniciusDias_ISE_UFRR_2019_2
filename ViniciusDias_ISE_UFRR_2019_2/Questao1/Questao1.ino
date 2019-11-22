#define CONTAR 8  // pino onde será conectado a tecla de contagem   
#define MODO 9   // pino onde será conectado a tecla de modo  

byte tabela_7_seg [16] = {
  B01111110, // = Digito 0
  B00001100, // = Digito 1
  B10110110, // = Digito 2
  B10011110, // = Digito 3
  B11001100, // = Digito 4
  B11011010, // = Digito 5
  B11111010, // = Digito 6
  B00001110, // = Digito 7
  B11111110, // = Digito 8
  B11001110, // = Digito 9
  B11101110, // = Digito A
  B11111000, // = Digito B
  B01110010, // = Digito C
  B10111100, // = Digito D
  B11110010, // = Digito E
  B11100010  // = Digito F
};

int contagem = 9, inc_dec = 1;

void setup()
{
  DDRD = B11111110;
  pinMode(CONTAR, INPUT);
  pinMode(MODO, INPUT);
}

void loop()
{
  if (digitalRead(CONTAR) == LOW)
  {
    contagem += inc_dec;
    if (contagem < 0)
    {
      contagem = 15;
    }
    if (contagem > 15)
    {
      contagem = 0;
    }
    while (digitalRead(CONTAR) == LOW)
    {
    }
  }
  if (digitalRead(MODO) == LOW)
  {
    inc_dec = inc_dec * (-1);
    while (digitalRead(MODO) == LOW) {
    }
  }
  PORTD = tabela_7_seg[contagem];
  delay(50);
}
