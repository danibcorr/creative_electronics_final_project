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

[https://lh4.googleusercontent.com/JXzNt3ElzJ8p90b9IQQpHJhqTtJMSU5xWcz_1YQbPnEXIO0wQMdmIEQFDc7W7-61AIJWwhYX3r6hxjhzd7niGagQ-MaOAp_zp296dKxx1KsoJMvVEVGqchJdM2800y13OlQbVGU3kb8Df61y4hGGSbNxl94HMUw6ilZBoiUyCPWlDzMHxyEMc_aBO79upA](https://lh4.googleusercontent.com/JXzNt3ElzJ8p90b9IQQpHJhqTtJMSU5xWcz_1YQbPnEXIO0wQMdmIEQFDc7W7-61AIJWwhYX3r6hxjhzd7niGagQ-MaOAp_zp296dKxx1KsoJMvVEVGqchJdM2800y13OlQbVGU3kb8Df61y4hGGSbNxl94HMUw6ilZBoiUyCPWlDzMHxyEMc_aBO79upA)

[https://lh3.googleusercontent.com/wTRDIHSH12l8QmBJqoHCMvXaW0bE1Jjo0vFMEVk-Y5sxW_1oKm1N1bHjuF0e560U5ZIoHVERwdhQoh_YTi-CFkT2FfAOh0utwmnosL6TaP5_Ba_w_StgYSu_21E83Sh5F4HJjnXBxdeICQ0wRDkbTrnLZZNdgLkWLaiE7DdNfN8RkfAiutO-4JpFBKFrMQ](https://lh3.googleusercontent.com/wTRDIHSH12l8QmBJqoHCMvXaW0bE1Jjo0vFMEVk-Y5sxW_1oKm1N1bHjuF0e560U5ZIoHVERwdhQoh_YTi-CFkT2FfAOh0utwmnosL6TaP5_Ba_w_StgYSu_21E83Sh5F4HJjnXBxdeICQ0wRDkbTrnLZZNdgLkWLaiE7DdNfN8RkfAiutO-4JpFBKFrMQ)

Hemos realizado algunos cambios. Los principales cambios que hemos hecho son:

- En el proyecto original la caja de control tenía una pantalla táctil para moverse por los diferentes modos, pero nosotros hemos utilizado una pantalla LCD que mostrará en qué modo está el brazo robótico, y cuatro botones para cambiar de modo.
- También hemos diseñado nuestra nueva caja de control para que se adapte mejor a las modificaciones de la pantalla LCD y los botones.
- En el brazo robótico hemos cambiado algunas piezas que no hemos encontrado en las tiendas, así que las hemos diseñado e impreso, estas piezas son los dos tubos de latón. El resto de piezas son las mismas que en el proyecto original.

## 2.2. Módulo de botones

Hemos diseñado y soldado un módulo para los cuatro botones.

El diseño es:

[https://lh4.googleusercontent.com/jY8TvfyqD7DzQCEkgBdmkBEhisDg1wdX5UNAReknaNzIuu57MyhmHWyHluW4OTJ01Nu6jp_LWNEmEAVgRByWtZYAHxyhqlhivuhSHOAPyyiS-h_RQuHTxGh18OGAWFiB4NnHwwOb6GrNoCrG60BG1zZrDNIqIW3sL2jNzZnKmt1TeWpPIJrhHMLxxcWx2g](https://lh4.googleusercontent.com/jY8TvfyqD7DzQCEkgBdmkBEhisDg1wdX5UNAReknaNzIuu57MyhmHWyHluW4OTJ01Nu6jp_LWNEmEAVgRByWtZYAHxyhqlhivuhSHOAPyyiS-h_RQuHTxGh18OGAWFiB4NnHwwOb6GrNoCrG60BG1zZrDNIqIW3sL2jNzZnKmt1TeWpPIJrhHMLxxcWx2g)

En la imagen anterior, hemos tenido que sustituir VCC por GND y viceversa. Posteriormente se han configurado los botones como entrada configurada con resistencias Pull-UP.

El resultado obtenido tras la soldadura fue el siguiente:

[https://lh3.googleusercontent.com/OM_QMxltEBnwWk9tNz5PO28V9VI-WjcyiurTDKC_VyhN66-m_8wFMR5ODB9uFk_9KMZdP1JZ7eiHTsXGVD7toAf07q8VawmNJ7-4sEpmVmqwnrYOa9evx0y5b12oNcBgmcjujsC-8N0l8p_xiD9Ah90i3O295qc1EFZIXtaWqPc8yHzz8Y0PZ58QU3YGbw](https://lh3.googleusercontent.com/OM_QMxltEBnwWk9tNz5PO28V9VI-WjcyiurTDKC_VyhN66-m_8wFMR5ODB9uFk_9KMZdP1JZ7eiHTsXGVD7toAf07q8VawmNJ7-4sEpmVmqwnrYOa9evx0y5b12oNcBgmcjujsC-8N0l8p_xiD9Ah90i3O295qc1EFZIXtaWqPc8yHzz8Y0PZ58QU3YGbw)

[https://lh4.googleusercontent.com/U6w0fFEGjqQje4b--gEIKQDh6ycOUkjV_HFdyO_pnVIigi_3BCD5zWBtgt7_TpGv1-b7alM7SYUTlQUutknaJv5Fo-Kynreeye9A_pH4ImTgKN27L4DB6lSuRieulszB6-XvuacwlzaK19hj6SZAGuuB2sheVYx1e0ZNJiVOA3NSHImOdxWxm95lI54gkw](https://lh4.googleusercontent.com/U6w0fFEGjqQje4b--gEIKQDh6ycOUkjV_HFdyO_pnVIigi_3BCD5zWBtgt7_TpGv1-b7alM7SYUTlQUutknaJv5Fo-Kynreeye9A_pH4ImTgKN27L4DB6lSuRieulszB6-XvuacwlzaK19hj6SZAGuuB2sheVYx1e0ZNJiVOA3NSHImOdxWxm95lI54gkw)

## 2.3. Construyendo el brazo

En esta parte, vamos a explicar cómo encajar las diferentes piezas del brazo.

En primer lugar, vamos a empezar por la base y la pinza, ya que en ellas irá situado el servomotor.

[https://lh4.googleusercontent.com/3FWSHn4DCkFpdqkkbjI1Ukd_Rv-k2Ep8Rm2YTzHp1rO8hYIEhAODHtHWPYv5q4FPGOrJCX07dAQbAc_KDq9syLV9rJ_fzYep0Ag-PQtO4-nc8ED-5InmNL7bUtyVTxHXxMBVqgKdooR15Iv8Q0_vjKlNwRWiZ0LJaaAnwoPmvixuFaDfeoobBhKvbm7RIg](https://lh4.googleusercontent.com/3FWSHn4DCkFpdqkkbjI1Ukd_Rv-k2Ep8Rm2YTzHp1rO8hYIEhAODHtHWPYv5q4FPGOrJCX07dAQbAc_KDq9syLV9rJ_fzYep0Ag-PQtO4-nc8ED-5InmNL7bUtyVTxHXxMBVqgKdooR15Iv8Q0_vjKlNwRWiZ0LJaaAnwoPmvixuFaDfeoobBhKvbm7RIg)

[https://lh3.googleusercontent.com/2GFF7aFxQaU7Ml-CJ7RzZjzRYxFLpg-8ifk5PlENQsULvF2VqtsTzi6o2cNf9w59eDEl5B05vunLklEx1yhF-k-Ydo9a7jed6weaoyNc8PJVDAFaJQ-SJwMmXwyKwzfJ2GIvq3x2GSCwl2UlEjCzuXOKiEy3yv43GOGkxSjrcBfXoM2wPbKKxqZWrRZgYQ](https://lh3.googleusercontent.com/2GFF7aFxQaU7Ml-CJ7RzZjzRYxFLpg-8ifk5PlENQsULvF2VqtsTzi6o2cNf9w59eDEl5B05vunLklEx1yhF-k-Ydo9a7jed6weaoyNc8PJVDAFaJQ-SJwMmXwyKwzfJ2GIvq3x2GSCwl2UlEjCzuXOKiEy3yv43GOGkxSjrcBfXoM2wPbKKxqZWrRZgYQ)

Y luego hemos construido el codo del brazo con el otro servomotor y lo hemos encajado con la base y la pinza.

Hemos lijado algunas piezas, sobre todo los engranajes porque no encajaban bien con las otras (esto dependerá del error asociado a la impresora 3D).

## 2.4. El código

En el caso de la pantalla LCD hemos utilizado el código proporcionado en el siguiente [enlace](https://docs.arduino.cc/learn/electronics/lcd-displays).

La máquina de estados utilizada en la programación se muestra a continuación. Tiene 5 estados principales desde los que saltará según se pulsen los botones correspondientes. Con la intención de conocer el estado en el que nos encontramos y para ofrecer una interfaz más amigable, mostramos el estado actual a través de la pantalla LCD.

![Diagram_SP.jpg](Brazo%20Robo%CC%81tico%207efaf12d8f7a46b69ea446224b475983/Diagram_SP.jpg)

El brazo robótico puede estar en dos modos, manual o automático.

Al principio el brazo robótico estaría en el modo **Home**.

Si el brazo robótico está en el modo **Home** y alguien pulsa el botón amarillo, cambiará al modo manual, en el que la persona podrá controlar el brazo robótico con los joysticks que hay en la caja de control. Cuando el brazo robótico esté en este modo, si alguien pulsa el botón rojo volverá al modo **Home**.

Si el brazo robótico está en el modo **Home** y alguien pulsa el botón azul, cambiará al modo **Automático**. En este modo, si se pulsa el botón verde se **ejecutan** los últimos movimientos que ha grabado, ahora si alguien pulsa el botón azul se **graban** los movimientos, pero si se pulsa el botón rojo se vuelve al estado **Automático**.

Volvemos al modo **Automático**, si se pulsa el botón rojo empezará a **grabar** movimientos, si se pulsa el botón verde se **detendrá la grabación** y se **ejecutará**.