// Librerías necesarias
#include <Servo.h> 

// Pines Botones
// Definir variables para los valores de los botones
// Boton amarillo = Manual
// Boton azul = automático
// Boton rojo = atrás
// Boton verde = ejecutar los movimientos grabados
#define BotonAmarillo 36
#define BotonAzul 38
#define BotonRojo 40
#define BotonVerde 42

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
    Serial.println("BotonAmarillo");
    db[0] = millis();
  }      
  anteriorPulsador[0] = estadoPulsador[0];

  estadoPulsador[1] = digitalRead(BotonRojo);
  if (!estadoPulsador[1] && anteriorPulsador[1] && millis() - db[1] >= 200UL)
  {
    Serial.println("BotonRojo");
    db[1] = millis();
  }      
  anteriorPulsador[1] = estadoPulsador[1];

  estadoPulsador[2] = digitalRead(BotonAzul);
  if (!estadoPulsador[2] && anteriorPulsador[2] && millis() - db[2] >= 200UL)
  {
    Serial.println("BotonAzul");
    db[2] = millis();
  }      
  anteriorPulsador[2] = estadoPulsador[2];

  estadoPulsador[3] = digitalRead(BotonVerde);
  if (!estadoPulsador[3] && anteriorPulsador[3] && millis() - db[3] >= 200UL)
  {
    Serial.println("BotonVerde");
    db[3] = millis();
  }      
  anteriorPulsador[3] = estadoPulsador[3];
}
