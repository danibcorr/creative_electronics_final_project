// Librerías necesarias
#include <LiquidCrystal.h>

// Pines LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Pines Botones
// Definir variables para los valores de los botones
// Boton amarillo = Manual
// Boton azul = automático
// Boton rojo = atrás
// Boton verde = ejecutar los movimientos grabados
#define BotonAmarillo 2
#define BotonAzul 3
#define BotonRojo 4
#define BotonVerde 5

// Estados de pulsación
bool estadoPulsador[] = {false, false, false, false};
bool anteriorPulsador[] = {false, false, false, false};
unsigned long db[4];

void setup() 
{
  pinMode(BotonAmarillo, INPUT_PULLUP);
  pinMode(BotonAzul, INPUT_PULLUP);
  pinMode(BotonRojo, INPUT_PULLUP);
  pinMode(BotonVerde, INPUT_PULLUP);

  // Inicializaciamos la comunicación serie
  Serial.begin(9600);
}

void loop()
{
  estadoPulsador[0] = digitalRead(BotonAmarillo);
  if (!estadoPulsador[0] && anteriorPulsador[0] && millis() - db[0] >= 200UL)
  {
    lcd.begin(16, 2);
    lcd.print("Pulsado boton");
    lcd.setCursor(0, 1);
    lcd.print("BotonAmarillo");
    lcd.setCursor(0, 0);
    db[0] = millis();
  }      
  anteriorPulsador[0] = estadoPulsador[0];

  estadoPulsador[1] = digitalRead(BotonRojo);
  if (!estadoPulsador[1] && anteriorPulsador[1] && millis() - db[1] >= 200UL)
  {
    lcd.begin(16, 2);
    lcd.print("Pulsado boton");
    lcd.setCursor(0, 1);
    lcd.print("BotonRojo");
    lcd.setCursor(0, 0);
    db[1] = millis();
  }      
  anteriorPulsador[1] = estadoPulsador[1];

  estadoPulsador[2] = digitalRead(BotonAzul);
  if (!estadoPulsador[2] && anteriorPulsador[2] && millis() - db[2] >= 200UL)
  {
    lcd.begin(16, 2);
    lcd.print("Pulsado boton");
    lcd.setCursor(0, 1);
    lcd.print("BotonAzul");
    lcd.setCursor(0, 0);
    db[2] = millis();
  }      
  anteriorPulsador[2] = estadoPulsador[2];

  estadoPulsador[3] = digitalRead(BotonVerde);
  if (!estadoPulsador[3] && anteriorPulsador[3] && millis() - db[3] >= 200UL)
  {
    lcd.begin(16, 2);
    lcd.print("Pulsado boton");
    lcd.setCursor(0, 1);
    lcd.print("BotonVerde");
    lcd.setCursor(0, 0);
    db[3] = millis();
  }      
  anteriorPulsador[3] = estadoPulsador[3];
}
