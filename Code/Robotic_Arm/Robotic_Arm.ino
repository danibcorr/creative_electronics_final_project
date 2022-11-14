// Librerías necesarias
#include <Servo.h> 



// Pines joystick
#define j1x A8
#define j1y A9
#define j2x A10
#define j2y A11

// Pines servos
#define servo_s1 22
#define servo_s2 24
#define servo_s3 26
#define servo_s4 28

// Pines Botones
// Definir variables para los valores de los botones
// Boton amarillo = manual
// Boton azul = automático
// Boton rojo = atrás
// Boton verde = ejecutar los movimientos grabados
#define BotonAmarillo 2
#define BotonAzul 3
#define BotonRojo 4
#define BotonVerde 5




// Definición de variables globales
// Variable de página
String page;

// Estados de pulsación
bool cs[] = {false, false, false, false, false};

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
  s1.attach(servo_s1);
  s2.attach(servo_s2);
  s3.attach(servo_s3);
  s4.attach(servo_s4);

  s1.write(90);
  s2.write(90);
  s3.write(90);
  s4.write(90);

  // Definir los pines de los joysticks como entrada
  pinMode(j1x, INPUT);
  pinMode(j1y, INPUT);
  pinMode(j2x, INPUT);
  pinMode(j2y, INPUT);

  pinMode(BotonAmarillo, INPUT);
  pinMode(BotonAzul, INPUT);
  pinMode(BotonRojo, INPUT);
  pinMode(BotonVerde, INPUT);

  // Inicializaciamos la comunicación serie
  Serial.begin(9600);
  
  // Estado inicial
  page = "home";
}

void loop()
{
  if (page == "home")
  {
    chooseModePage();
  }
  else if (page == "manual")
  {
    manualModePage();
  }
  else if (page == "automated")
  {
    automatedModePage();
  }
  else if (page == "record")
  {
    recordPage();
  }
  else if (page == "play")
  {
    playPage();
  }
}

void limpiar_estado_botones(int boton)
{
  for(int i = 0; i < sizeof(cs) / sizeof(bool); i++)
  {
    if(i != boton)
    {
      cs[i] = false;
    }
  }
}

void chooseModePage ()
{
  limpiar_estado_botones(0);

  ssn = 0;

  if (cs[0] == false)
  {
    cs[0] = true;
  }

  if (digitalRead(BotonAmarillo) == HIGH)
  {
    Serial.println("Pulsado boton modo manual");
    page = "manual";
  }        
  if (digitalRead(BotonAzul) == HIGH)
  {
    Serial.println("Pulsado boton modo automatico");
    page = "automated";
  }
}
  
void manualModePage()
{
  // Mostramos los valores de los joystick por el puerto serie
  Serial.print(analogRead(j1x));
  Serial.print("\t");
  Serial.print(analogRead(j2x));
  Serial.print("\t");
  Serial.print(analogRead(j1y));
  Serial.print("\t");
  Serial.println(analogRead(j2y));

  limpiar_estado_botones(1);
  ssn = 0;

  if (cs[1] == false)
  {
    cs[1] = true;
  }

  if (digitalRead(BotonRojo) == HIGH)
  {
    Serial.println("Pulsado boton atras, volvemos al menu");
    page = "home";
  }     

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
  else if (analogRead(j1x) <= 300)
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

  if (analogRead(j1y) >= 800)
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
  else if(analogRead(j1y) <= 300)
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
  else if(analogRead(j2x) <= 300)
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
  else if(analogRead(j2y) <= 300)
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

void automatedModePage(){

  limpiar_estado_botones(2);
  ssn = 0;

  if (cs[2] == false)
  {
    cs[2] = true;
  }  

  // Delay de 20 ms, antirrebote
  delay(20);
  if (digitalRead(BotonAzul) == HIGH)
  {
    Serial.println("Pulsado boton de grabar movimientos");
    page = "record";
  }        
  if (digitalRead(BotonVerde) == HIGH)
  {
    Serial.println("Pulsado boton de reproducir movimientos");
    page = "play";
  }
  if (digitalRead(BotonRojo) == HIGH)
  {
    Serial.println("Pulsado boton atras, volvemos al menu");
    page = "home";
  }
}

void recordPage()
{
  limpiar_estado_botones(3);

  if (cs[3] == false)
  {
    cs[3] = true;
  }

  if (digitalRead(BotonAzul) == HIGH)
  {
    Serial.println("Volvemos al menu automatico");
    page = "automated";
  }        
  if (digitalRead(BotonVerde) == LOW)
  {
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
  }

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

void playPage()
{
  limpiar_estado_botones(4);
  ssn = 0;

  if (cs[4] == false)
  {
    cs[4] = true;
  }
  
  if (digitalRead(BotonAzul) == HIGH)
  {
    Serial.println("Volvemos al menu automatico");
    page = "automated";
  }   
  
  for (int i = 0; i < 5; i++)
  {                    
    int j = i + 1;

    if (digitalRead(BotonAzul) == HIGH)
    {
      Serial.println("Volvemos al menu atomatico");
      page = "automated";
    }        
    
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
