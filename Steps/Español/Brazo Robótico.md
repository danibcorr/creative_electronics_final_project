# Brazo Robótico

# Índice

# 1. Resumen

Este proyecto consiste en construir y programar un brazo robótico. Este, será capaz de hacer y repetir movimientos. Todo ello controlado por un mega Arduino.

Este proyecto ha surgido para la elaboración del proyecto final de la asignatura de Electrónica Creativa, asignatura perteneciente a la Universidad de Málaga (UMA).

Todo el proyecto ha sido realizado por Clara Rubio Almagro, Laura Sánchez Sánchez y Daniel Bazo Correa, estudiantes de Ingeniería de Sistemas Electrónicos de la Universidad de Málaga.

La idea principal, la estructura del brazo robótico, el código de partida y las herramientas/utilidades se pueden encontrar en este [enlace](https://www.instructables.com/Automated-Robotic-Arm-That-Learns-Ft-Tinkercad-Ard/).

# 2. Pasos

## 2.1. Componentes

Los componentes necesarios son:

- Arduino Mega.
- 2 joystick.
- Pantalla LCD.
- 4 servomotores.
- 4 botones.
- Y también necesitamos las piezas del robot, en este caso las hemos impreso.

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image.png"/>
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image (1).png"/>
</p>

Hemos realizado algunos cambios. Los principales cambios que hemos hecho son:

- En el proyecto original la caja de control tenía una pantalla táctil para moverse por los diferentes modos, pero nosotros hemos utilizado una pantalla LCD que mostrará en qué modo está el brazo robótico, y cuatro botones para cambiar de modo.
- También hemos diseñado nuestra nueva caja de control para que se adapte mejor a las modificaciones de la pantalla LCD y los botones.
- En el brazo robótico hemos cambiado algunas piezas que no hemos encontrado en las tiendas, así que las hemos diseñado e impreso, estas piezas son los dos tubos de latón. El resto de piezas son las mismas que en el proyecto original.

## 2.2. Módulo de botones

Hemos diseñado y soldado un módulo para los cuatro botones.

El diseño es:

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image (2).png"/>
</p>

En la imagen anterior, hemos tenido que sustituir VCC por GND y viceversa. Posteriormente se han configurado los botones como entrada configurada con resistencias Pull-UP.

El resultado obtenido tras la soldadura fue el siguiente:

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image (3).png"/>
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image (4).png"/>
</p>

## 2.3. Construyendo el brazo

En esta parte, vamos a explicar cómo encajar las diferentes piezas del brazo.

En primer lugar, vamos a empezar por la base y la pinza, ya que en ellas irá situado el servomotor.

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image (5).png"/>
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image (6).png"/>
</p>

Y luego hemos construido el codo del brazo con el otro servomotor y lo hemos encajado con la base y la pinza.

Hemos lijado algunas piezas, sobre todo los engranajes porque no encajaban bien con las otras (esto dependerá del error asociado a la impresora 3D).

## 2.4. El código

En el caso de la pantalla LCD hemos utilizado el código proporcionado en el siguiente [enlace](https://docs.arduino.cc/learn/electronics/lcd-displays).

La máquina de estados utilizada en la programación se muestra a continuación. Tiene 5 estados principales desde los que saltará según se pulsen los botones correspondientes. Con la intención de conocer el estado en el que nos encontramos y para ofrecer una interfaz más amigable, mostramos el estado actual a través de la pantalla LCD.

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/Diagram_SP.jpg"/>
</p>

El brazo robótico puede estar en dos modos, manual o automático.

Al principio el brazo robótico estaría en el modo **Home**.

Si el brazo robótico está en el modo **Home** y alguien pulsa el botón amarillo, cambiará al modo manual, en el que la persona podrá controlar el brazo robótico con los joysticks que hay en la caja de control. Cuando el brazo robótico esté en este modo, si alguien pulsa el botón rojo volverá al modo **Home**.

Si el brazo robótico está en el modo **Home** y alguien pulsa el botón azul, cambiará al modo **Automático**. En este modo, si se pulsa el botón verde se **ejecutan** los últimos movimientos que ha grabado, ahora si alguien pulsa el botón azul se **graban** los movimientos, pero si se pulsa el botón rojo se vuelve al estado **Automático**.

Volvemos al modo **Automático**, si se pulsa el botón rojo empezará a **grabar** movimientos, si se pulsa el botón verde se **detendrá la grabación** y se **ejecutará**.
