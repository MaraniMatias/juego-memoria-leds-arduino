//  los botones hay que apretarlos rapido porque sino lee mal, (en otors poyecto use una funcion anti rebote)
/*     leds || botones
verde     7 || 2
amarrillo 8 || 3
rojo      9 || 4
verde     10|| 5
*/
const int leds[4] = { 7, 8, 9, 10};
const int btns[4] = { 2, 3, 4, 5};
const int ledestado = 13;

int juego[4];
int i = 0, b = 0;
boolean jugar = true, bien = false;

void setup() {
  // pin out
  pinMode(ledestado, OUTPUT);
  pinMode(leds[0], OUTPUT);
  pinMode(leds[1], OUTPUT);
  pinMode(leds[2], OUTPUT);
  pinMode(leds[3], OUTPUT);
  // pin in
  pinMode(btns[0], INPUT); //verde
  pinMode(btns[1], INPUT); //amarrillo
  pinMode(btns[2], INPUT); //rojo
  pinMode(btns[3], INPUT); //verde
  // preparar num random
  randomSeed(analogRead(A0));
}

void loop() {

  if (jugar) {
    for (i = 0; i <= 3; i++) {
      int valor = random(4);
      juego[i] = valor;
      digitalWrite(leds[valor], HIGH);
      delay(500);
      digitalWrite(leds[valor], LOW);
      delay(500);
    }
    jugar = false;
    b = 0;
  } else {
    leerbtn();
    if (b == 4 & bien) {
      digitalWrite(ledestado, HIGH);
      bien = false;
      jugar = true;
      delay(750);
      digitalWrite(ledestado, LOW);
    }
  }
}

void leerbtn() {

  int btn0 = digitalRead(btns[0]);
  if (btn0 == HIGH) {
    if (juego[b] == 0) {
      digitalWrite(leds[0], HIGH);
      bien = true;
      b++;
      delay(200);
      delay(200);
      digitalWrite(leds[0], LOW);
    } else {
      mal();
    }
  }


  int btn1 = digitalRead(btns[1]);
  if (btn1 == HIGH) {
    if (juego[b] == 1) {
      digitalWrite(leds[1], HIGH);
      bien = true;
      b++;
      delay(200);
      digitalWrite(leds[1], LOW);
    } else {
      mal();
      bien = true;
      b = 0;
    }
  }

  int btn2 = digitalRead(btns[2]);
  if (btn2 == HIGH) {
    if (juego[b] == 2) {
      digitalWrite(leds[2], HIGH);
      bien = true;
      b++;
      delay(200);
      digitalWrite(leds[2], LOW);
    } else {
      mal();
      bien = true;
      b = 0;
    }
  }


  int btn3 = digitalRead(btns[3]);
  if (btn3 == HIGH) {
    if (juego[b] == 3) {
      digitalWrite(leds[3], HIGH);
      bien = true;
      b++;
      delay(200);
      digitalWrite(leds[3], LOW);
    } else {
      mal();
      bien = true;
      b = 0;
    }
  }

}

void mal() {
  bien = true;
  b = 0;
  jugar = true;
  digitalWrite(leds[0], HIGH);
  digitalWrite(leds[1], HIGH);
  digitalWrite(leds[2], HIGH);
  digitalWrite(leds[3], HIGH);
  delay(200);
  digitalWrite(leds[0], LOW);
  digitalWrite(leds[1], LOW);
  digitalWrite(leds[2], LOW);
  digitalWrite(leds[3], LOW);
  delay(1000);
}
