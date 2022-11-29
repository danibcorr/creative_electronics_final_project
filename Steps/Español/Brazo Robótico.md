# Brazo Robótico

# 1. Resumen

Este proyecto consiste en construir y programar un brazo robótico. Este, será capaz de realizar movimientos de manera manual mediante el control por joystick
y de repetir movimientos grabados, todo ello controlado por un Arduino Mega. El motivo principal del uso de la Arduino Mega es por su gran cantidad de pines de I/O
además de tomas extras de GND y VCC.

Este proyecto ha surgido para la elaboración de la práctica final de la asignatura de Electrónica Creativa, asignatura perteneciente a la Universidad de Málaga (UMA).

Todo el proyecto ha sido realizado por Clara Rubio Almagro, Laura Sánchez Sánchez y Daniel Bazo Correa, estudiantes de Ingeniería de Sistemas Electrónicos de la Universidad de Málaga.

La idea principal, la estructura del brazo robótico, el código de partida y las herramientas/utilidades se pueden encontrar en este [enlace](https://www.instructables.com/Automated-Robotic-Arm-That-Learns-Ft-Tinkercad-Ard/).

# 2. Pasos

## 2.1. Componentes

Los componentes necesarios son:

- Un microcontrolador. En este caso, una Arduino Mega. Aunque sería válido cualquier otro microntrolador con la cantidad suficiente de pines o agregando alguna placa de expansión.
- 2 joystick para el control manual.
- Pantalla LCD con el que poder visualizar el comportamiento del robot (el estado en el que nos encontramos).
- 4 servomotores.
- 4 botones.
- Y también necesitamos las piezas del robot, las cuales han sido impresas en 3D.

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image.png"  width="300"/>
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image (1).png" width="300"/>
</p>

Tras analizar el proyecto de partida nos hemos visto en la tesitura de tener que realizar algunos cambios. Estos cambios se presentan a continuación:

- En el proyecto original, la caja de control tenía una pantalla táctil para moverse por los diferentes modos. Nosotros, hemos utilizado una pantalla LCD, que mostrará en qué modo está el brazo robótico, en combinación con cuatro botones para cambiar de modo.
- También hemos diseñado nuestra nueva caja de control para que se adapte mejor a las modificaciones de la pantalla LCD y los botones.
- En el brazo robótico hemos cambiado algunas piezas que no hemos encontrado en las tiendas. Por ello, hemos optado por realizar el diseñado e impresión en 3D. En concreto, las piezas impresas han sido las sustitutas de los dos tubos de latón en el proyecto de partida. El resto de piezas son las mismas que en el proyecto original.

## 2.2. Módulo de botones

Hemos diseñado y soldado un módulo para los cuatro botones.

El diseño en cuestión es el siguiente:

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image (2).png" width="300"/>
</p>

En la imagen anterior, hemos tenido que sustituir VCC por GND y viceversa. Posteriormente se han configurado los botones como entrada configurada con resistencias Pull-UP.

El resultado obtenido tras la soldadura fue el siguiente:

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image (3).png" width="300"/>
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image (4).png" width="300"/>
</p>

## 2.3. Construyendo el brazo

En cuanto a la construcción del brazo, hemos seguido los mismos pasos que el [enlace](https://www.instructables.com/EEZYbotARM/). A modo de ilustración, enseñaremos algunas de las partes del proceso en el montaje del brazo robot con el fin de explicar cómo encajar las diferentes piezas del brazo.

En primer lugar, vamos a empezar por la base y la pinza, ya que en ellas irá situado el servomotor.

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image (5).png" width="300"/>
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image (6).png" width="300"/>
</p>

Posteriormente, hemos construido el codo del brazo añadiendo el otro servomotor encajandolo con la base y la pinza. Debido a la precisión de la impresora 3D utilizada, hemos lijado algunas piezas impresas. Sobre todo, los engranajes, ya que no encajaban bien con otras piezas.

## 2.4. El código

Nuestra recomendación es ir probando cada componente por separado. Por ello, en el caso de la pantalla LCD hemos utilizado el código proporcionado en el siguiente [enlace](https://docs.arduino.cc/learn/electronics/lcd-displays). En el caso de los servomotores, hemos optado por 


La máquina de estados utilizada en la programación se muestra a continuación. Tiene 5 estados principales desde los que saltará según se pulsen los botones correspondientes. Con la intención de conocer el estado en el que nos encontramos y para ofrecer una interfaz más amigable, mostramos el estado actual a través de la pantalla LCD.

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/Diagram_SP.jpg" width="300"/>
</p>

El brazo robótico puede estar en dos modos, manual o automático.

Al principio el brazo robótico estaría en el modo **Home**.

Si el brazo robótico está en el modo **Home** y alguien pulsa el botón amarillo, cambiará al modo manual, en el que la persona podrá controlar el brazo robótico con los joysticks que hay en la caja de control. Cuando el brazo robótico esté en este modo, si alguien pulsa el botón rojo volverá al modo **Home**.

Si el brazo robótico está en el modo **Home** y alguien pulsa el botón azul, cambiará al modo **Automático**. En este modo, si se pulsa el botón verde se **ejecutan** los últimos movimientos que ha grabado, ahora si alguien pulsa el botón azul se **graban** los movimientos, pero si se pulsa el botón rojo se vuelve al estado **Automático**.

Volvemos al modo **Automático**, si se pulsa el botón rojo empezará a **grabar** movimientos, si se pulsa el botón verde se **detendrá la grabación** y se **ejecutará**.
