// Librerías necesarias
#include <Servo.h> 
#include <LiquidCrystal.h>

// Pines LCD
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Pines joystick
#define j1x A8
#define j1y A9
#define j2x A10
#define j2y A11

// Pines servos
#define servo_s1 22   //derecha
#define servo_s2 24   //izquierda
#define servo_s3 26   //pinza
#define servo_s4 28   //base

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

int show_one[] = {0, 0, 0, 0, 0};



// Definición de variables globales
// Variable de página
String page;

// Estados de pulsación
bool estadoPulsador[] = {false, false, false, false};
bool anteriorPulsador[] = {false, false, false, false};
unsigned long db[4];

// Numero de secuencia guardado
int ssn = 0;

// Definición de los servos
Servo s1, s2, s3, s4;

//  Valores joystick
int x_out = 0, y_out = 0, x_out2 = 0, y_out2 = 0;

//define int variable array for saved position of the servos
int servo1PosSave[] = {90, 90, 90, 90, 90};
int servo2PosSave[] = {90, 90, 90, 90, 90};
int servo3PosSave[] = {90, 90, 90, 90, 90};
int servo4PosSave[] = {90, 90, 90, 90, 90};



void setup() 
{
  // Definir los pines de los servos
  s1.attach(servo_s1);    //derecha
  s2.attach(servo_s2);    //izquierda
  s3.attach(servo_s3);    //pinza
  s4.attach(servo_s4);    //base

  s1.write(90);
  s2.write(0);
  s3.write(0);
  s4.write(0);

  // Definir los pines de los joysticks como entrada
  pinMode(j1x, INPUT);
  pinMode(j1y, INPUT);
  pinMode(j2x, INPUT);
  pinMode(j2y, INPUT);

  pinMode(BotonAmarillo, INPUT_PULLUP);
  pinMode(BotonAzul, INPUT_PULLUP);
  pinMode(BotonRojo, INPUT_PULLUP);
  pinMode(BotonVerde, INPUT_PULLUP);

  // Inicializaciamos la comunicación serie
  Serial.begin(9600);
  
  // Estado inicial
  page = "Inicio";
}

void loop()
{
  if (page == "Inicio")
  {
    if (show_one[0] == 0)
    {
      show_one[1] = show_one[2] = show_one[3] = show_one[4] = 0;
      show_one[0] = 1;
      lcd.begin(16, 2);
      lcd.print("Modo inicio");
    }
    
    chooseModePage();
  }
  else if (page == "Manual")
  {
    if (show_one[1] == 0)
    {
      show_one[0] = show_one[2] = show_one[3] = show_one[4] = 0;
      show_one[1] = 1;
      lcd.begin(16, 2);
      lcd.print("Modo manual");
    }
    
    ManualModePage();
  }
  else if (page == "Automatico")
  {
    if (show_one[2] == 0)
    {
      show_one[0] = show_one[1] = show_one[3] = show_one[4] = 0;
      show_one[2] = 1;
      lcd.begin(16, 2);
      lcd.print("Modo automatico");
    }
    
    AutomaticoModePage();
  }
  else if (page == "Grabar")
  {
    if (show_one[3] == 0)
    {
      show_one[0] = show_one[1] = show_one[2] = show_one[4] = 0;
      show_one[3] = 1;
      lcd.begin(16, 2);
      lcd.print("Modo grabar");
    }
    
    GrabarPage();
  }
  else if (page == "Ejecutar")
  {
    if (show_one[4] == 0)
    {
      show_one[0] = show_one[1] = show_one[2] = show_one[3] = 0;
      show_one[4] = 1;
      lcd.begin(16, 2);
      lcd.print("Modo ejecutar");
    }
    
    EjecutarPage();
  }
}


void chooseModePage ()
{
  ssn = 0;

  estadoPulsador[0] = digitalRead(BotonAmarillo);
  if (!estadoPulsador[0] && anteriorPulsador[0] && millis() - db[0] >= 150UL)
  {
    lcd.begin(16, 2);
    lcd.print("Pulsado boton");
    lcd.setCursor(0, 1);
    lcd.print("modo manual");
    lcd.setCursor(0, 0);
    page = "Manual";
    db[0] = millis();
  }      
  anteriorPulsador[0] = estadoPulsador[0];

  estadoPulsador[1] = digitalRead(BotonAzul);
  if (!estadoPulsador[1] && anteriorPulsador[1] && millis() -db[1] >= 150UL)
  {
    lcd.begin(16, 2);
    lcd.print("Pulsado boton");
    lcd.setCursor(0, 1);
    lcd.print("modo automatico");
    lcd.setCursor(0, 0);
    page = "Automatico";
    db[1] = millis();
  }
  anteriorPulsador[1] = estadoPulsador[1];
}
  
void ManualModePage()
{
  // Mostramos los valores de los joystick por el puerto serie
  Serial.print(analogRead(j1x));
  Serial.print("\r\t");
  Serial.print(analogRead(j2x));
  Serial.print("\r\t");
  Serial.print(analogRead(j1y));
  Serial.print("\r\t");
  Serial.println(analogRead(j2y));

  ssn = 0;

  estadoPulsador[2] = digitalRead(BotonRojo);
  if (!estadoPulsador[2] && anteriorPulsador[2] && millis() -db[2] >= 150UL)
  {
    lcd.begin(16, 2);
    lcd.print("Pulsado boton");
    lcd.setCursor(0, 1);
    lcd.print("menu inicio");
    lcd.setCursor(0, 0);
    page = "Inicio";
    db[2] = millis(); 
  }     
  anteriorPulsador[2] = estadoPulsador[2];

  //-------------------------------Manual Joystick Control-------------------------------------------------------------------------------------------------------------

  if (analogRead(j1x) >= 800)
  {
    for (int i = s1.read(); i > 30; i--)
    {
      if (analogRead(j1x) < 800)
      {
        break;
      }

      s1.write(i);
      delay(20);
    }
  }
  else if (analogRead(j1x) <= 300)
  {
    for (int i = s1.read(); i < 90; i++)
    {
      if (analogRead(j1x) > 300)
      {
        break;
      }

      s1.write(i);
      delay(20);
    }
  }

  if (analogRead(j1y) >= 800)
  {
    for (int i = s2.read(); i < 60; i++)
    {
      if (analogRead(j1y) < 800)
      {
        break;
      }

      s2.write(i);
      delay(20);
    }
  }
  else if(analogRead(j1y) <= 300)
  {
     for (int i = s2.read(); i > 0; i--)
     {
      if (analogRead(j1y) > 300)
      {
        break;
      }

      s2.write(i);
      delay(20);
     }
  }

  if(analogRead(j2x) >= 800)
  {
    for (int i = s4.read(); i < 180; i++)
    {
      if (analogRead(j2x) < 800)
      {
        break;
      }

      s4.write(i);
      delay(30);
    }
  }
  else if(analogRead(j2x) <= 300)
  {
    for (int i = s4.read(); i > 0; i--)
    {
      if (analogRead(j2x) > 300)
      {
        break;
      }

      s4.write(i);
      delay(30);
    }
  }

  if(analogRead(j2y) >= 800)
  {
    for (int i = s3.read(); i < 90; i++)
    {
      if (analogRead(j2y) < 800)
      {
        break;
      }

      s3.write(i);
      delay(20);
    }
  }
  else if(analogRead(j2y) <= 300)
  {
    for (int i = s3.read(); i > 0; i--)
    {
      if (analogRead(j2y) > 300)
      {
        break;
      }

    s3.write(i);
    delay(20);
    }
  }
}

void AutomaticoModePage()
{
  ssn = 0;
    
  estadoPulsador[1] = digitalRead(BotonAzul);
  if (!estadoPulsador[1] && anteriorPulsador[1] && millis() -db[1] >= 150UL)
  {
    lcd.begin(16, 2);
    lcd.print("Pulsado boton");
    lcd.setCursor(0, 1);
    lcd.print("grabar movs.");
    lcd.setCursor(0, 0);
    page = "Grabar";
    db[1] = millis();
  }
  anteriorPulsador[1] = estadoPulsador[1];
       
  estadoPulsador[2] = digitalRead(BotonRojo);
  if (!estadoPulsador[2] && anteriorPulsador[2] && millis() -db[2] >= 150UL)
  {
    lcd.begin(16, 2);
    lcd.print("Pulsado boton");
    lcd.setCursor(0, 1);
    lcd.print("menu inicio");
    lcd.setCursor(0, 0);
    page = "Inicio";
    db[2] = millis();
  }
  anteriorPulsador[2] = estadoPulsador[2];

  estadoPulsador[3] = digitalRead(BotonVerde);
  if (!estadoPulsador[3] && anteriorPulsador[3] && millis() -db[3] >= 150UL)
  {
    lcd.begin(16, 2);
    lcd.print("Pulsado boton");
    lcd.setCursor(0, 1);
    lcd.print("ejecutar movs.");
    lcd.setCursor(0, 0);
    page = "Ejecutar";
    db[3] = millis();
  }
  anteriorPulsador[3] = estadoPulsador[3];
}

void GrabarPage()
{
  estadoPulsador[2] = digitalRead(BotonRojo);
  if (!estadoPulsador[2] && anteriorPulsador[2] && millis() -db[2] >= 150UL)
  {
    lcd.begin(16, 2);
    lcd.print("Pulsado boton");
    lcd.setCursor(0, 1);
    lcd.print("menu automatico");
    lcd.setCursor(0, 0);
    page = "Automatico";
    db[2] = millis();
  }
  anteriorPulsador[2] = estadoPulsador[2];

  estadoPulsador[3] = digitalRead(BotonVerde);
  if (!estadoPulsador[3] && anteriorPulsador[3] && millis() -db[3] >= 150UL)
  {
    lcd.begin(16, 2);
    lcd.print("Pulsado boton");
    lcd.setCursor(0, 1);
    lcd.print("ejecutar movs.");
    lcd.setCursor(0, 0);
    page = "Ejecutar";
    db[3] = millis();
  }
  anteriorPulsador[3] = estadoPulsador[3];

  switch(ssn)
  {
    case 0:
    {
      servo1PosSave[0] = s1.read();
      servo2PosSave[0] = s2.read();
      servo3PosSave[0] = s3.read();
      servo4PosSave[0] = s4.read();
    }
    
    break;
    
    case 1:
    {
      servo1PosSave[1] = s1.read();
      servo2PosSave[1] = s2.read();
      servo3PosSave[1] = s3.read();
      servo4PosSave[1] = s4.read();
    }
    
    break;
    
    case 2:
    {
      servo1PosSave[2] = s1.read();
      servo2PosSave[2] = s2.read();
      servo3PosSave[2] = s3.read();
      servo4PosSave[2] = s4.read();
    }
    
    break;
    
    case 3:
    {
      servo1PosSave[3] = s1.read();
      servo2PosSave[3] = s2.read();
      servo3PosSave[3] = s3.read();
      servo4PosSave[3] = s4.read();
    }
    
    break;

    case 4:
    {
      servo1PosSave[4] = s1.read();
      servo2PosSave[4] = s2.read();
      servo3PosSave[4] = s3.read();
      servo4PosSave[4] = s4.read();
    }
    
    break;
  }
    
  ssn++;

  //-------------------------------Manual Joystick Control-------------------------------------------------------------------------------------------------------------

  if (analogRead(j1x) >= 800)
  {
     for (int i = s1.read(); i < 180; i++)
     {
      if (analogRead(j1x) < 800)
      {
        break;
      }

      s1.write(i);
      delay(20);
     }
  }

  if(analogRead(j1x) <= 300)
  {
     for (int i = s1.read(); i > 0; i--)
     {
      if (analogRead(j1x) > 300)
      {
        break;
      }

      s1.write(i);
      delay(20);
     }
  }

  if(analogRead(j1y) >= 800)
  {
     for (int i = s2.read(); i < 140; i++)
     {
      if (analogRead(j1y) < 800)
      {
        break;
      }

      s2.write(i);
      delay(20);
     }
  }

  if(analogRead(j1y) <= 300)
  {
     for (int i = s2.read(); i > 70; i--)
     {
      if (analogRead(j1y) > 300)
      {
        break;
      }

      s2.write(i);
      delay(20);
     }
  }
//-------------------------------------------
  if(analogRead(j2x) >= 800)
  {
     for (int i = s4.read(); i < 120; i++)
     {
      if (analogRead(j2x) < 800)
      {
        break;
      }

      s4.write(i);
      delay(30);
     }
  }

  if(analogRead(j2x) <= 300)
  {
     for (int i = s4.read(); i > 50; i--)
     {
      if (analogRead(j2x) > 300)
      {
        break;
      }

      s4.write(i);
      delay(30);
     }
  }
//-------------------------------------------
  if(analogRead(j2y) >= 800)
  {
     for (int i = s3.read(); i < 120; i++)
     {
      if (analogRead(j2y) < 800)
      {
        break;
      }

      s3.write(i);
      delay(20);
     }
  }

  if(analogRead(j2y) <= 300)
  {
     for (int i = s3.read(); i > 60; i--)
     {
      if (analogRead(j2y) > 300)
      {
        break;
      }

      s3.write(i);
      delay(20);
     }
  }
}

void EjecutarPage()
{
  ssn = 0;

  estadoPulsador[2] = digitalRead(BotonRojo);
  if (!estadoPulsador[2] && anteriorPulsador[2] && millis() -db[2] >= 150UL)
  {
    lcd.begin(16, 2);
    lcd.print("Pulsado boton");
    lcd.setCursor(0, 1);
    lcd.print("menu automatico");
    lcd.setCursor(0, 0);
    page = "Automatico";
    db[2] = millis();
  }
  anteriorPulsador[2] = estadoPulsador[2];

  estadoPulsador[1] = digitalRead(BotonAzul);
  if (!estadoPulsador[1] && anteriorPulsador[1] && millis() -db[1] >= 150UL)
  {
    lcd.begin(16, 2);
    lcd.print("Pulsado boton");
    lcd.setCursor(0, 1);
    lcd.print("grabar movs.");
    lcd.setCursor(0, 0);
    page = "Grabar";
    db[1] = millis();
  }
  anteriorPulsador[1] = estadoPulsador[1];
  
  for (int i = 0; i < (sizeof(servo1PosSave) / sizeof(int)); i++)
  {                    
    int j = i + 1;

    estadoPulsador[2] = digitalRead(BotonRojo);
    if (!estadoPulsador[2] && anteriorPulsador[2] && millis() -db[2] >= 150UL)
    {
      lcd.begin(16, 2);
      lcd.print("Pulsado boton");
      lcd.setCursor(0, 1);
      lcd.print("menu automatico");
      lcd.setCursor(0, 0);
      page = "Automatico";
      db[2] = millis();
    }
    anteriorPulsador[2] = estadoPulsador[2];      
    
    if (servo1PosSave[i] < s1.read())
    {
      for (int p = s1.read(); p >= servo1PosSave[i]; p--)
      {
        s1.write(p);
        delay(20); 
      }
    }

    if (servo1PosSave[i] > s1.read())
    {
      for (int p = s1.read(); p <= servo1PosSave[i]; p++)
      {
        s1.write(p);
        delay(20); 
      }
    }

    if (servo2PosSave[i] < s2.read())
    {
      for (int p = s2.read(); p >= servo2PosSave[i]; p--)
      {
        s2.write(p);
        delay(20); 
      }
    }

    if (servo2PosSave[i] > s2.read())
    {
      for (int p = s2.read(); p <= servo2PosSave[i]; p++)
      {
        s2.write(p);
        delay(20); 
      }
    }
  
    if (servo3PosSave[i] < s3.read())
    {
      for (int p = s3.read(); p >= servo3PosSave[i]; p--)
      {
        s3.write(p);
        delay(20); 
      }
    }

    if (servo3PosSave[i] > s3.read())
    {
      for (int p = s3.read(); p <= servo3PosSave[i]; p++)
      {
        s3.write(p);
        delay(20); 
      }
    }

    if (servo4PosSave[i] < s4.read())
    {
      for (int p = s4.read(); p >= servo4PosSave[i]; p--)
      {
        s4.write(p);
        delay(20); 
      }
    }

    if (servo4PosSave[i] > s4.read())
    {
      for (int p = s4.read(); p <= servo4PosSave[i]; p++)
      {
        s4.write(p);
        delay(20); 
      }
    }
  }
}
