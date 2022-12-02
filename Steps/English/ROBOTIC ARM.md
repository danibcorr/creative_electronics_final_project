# Robotic Arm

# 1. Abstract

This project consists of building and programming a robotic arm. It will be able to perform manual movements by joystick control and to repeat recorded movements, all controlled by an Arduino Mega.
and to repeat recorded movements, all controlled by an Arduino Mega. The main reason for using the Arduino Mega is because of its large number of I/O pins, plus extra GND and GND sockets.
plus extra GND and VCC sockets.

This project has arisen for the development of the final practice of the subject of Creative Electronics, a subject belonging to the University of Malaga (UMA).

The whole project has been carried out by Clara Rubio Almagro, Laura Sánchez Sánchez and Daniel Bazo Correa, students of Electronic Systems Engineering at the University of Málaga.

The main idea, the structure of the robotic arm, the starting code and the tools/utilities can be found in this [link](https://www.instructables.com/Automated-Robotic-Arm-That-Learns-Ft-Tinkercad-Ard/).

# 2. Steps

## 2.1. Components

The required components are:

- A microcontroller. In this case, an Arduino Mega. Although any other microcontroller with enough pins or adding some expansion board would be valid.
- 2 joysticks for manual control.
- LCD screen with which to visualize the behavior of the robot (the state in which we are).
- 4 servomotors.
- 4 buttons.
- And we also need the parts of the robot, which have been printed in 3D.

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image.png" width="300"/>
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image (1).png" width="300"/>
</p>

After analyzing the starting project we have found ourselves in the position of having to make some changes. These changes are presented below:

- In the original project, the control box had a touch screen to move through the different modes. We, have used an LCD screen, which will show which mode the robotic arm is in, in combination with four buttons to change modes.
- We also designed our new control box to better accommodate the modifications to the LCD screen and buttons.
- On the robotic arm we have changed some parts that we have not found in stores. Therefore, we have chosen to do the design and 3D printing. Specifically, the printed parts have been the substitutes for the two brass tubes in the starting project. The rest of the pieces are the same as in the original project.

### 2.1.1. Buttons module

We have designed and soldered a module for the four buttons.

The design in question is as follows:

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image (2).png" width="300"/>
</p>

In the above image, we had to replace VCC with GND and vice versa. Subsequently, the buttons have been configured as input configured with Pull-UP resistors.

The result obtained after soldering was as follows:

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image (3).png" width="300"/>
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image (4).png" width="300"/>
</p>

Once the module was soldered we tested it with a simple [program](https://github.com/danibcorr/creative_electronics_final_project/tree/main/Tests/prueba_botones).

### 2.1.2. Building the arm

Regarding the construction of the arm, we have followed the same steps as the [link](https://www.instructables.com/EEZYbotARM/). As an illustration, we will show some of the parts of the process in assembling the robot arm in order to explain how to fit the different parts of the arm together.

First of all, let's start with the base and the gripper, since the servomotor will be located on them.

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image (5).png" width="300"/>
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image (6).png" width="300"/>
</p>

Subsequently, we built the arm elbow by adding the other servo motor by fitting it with the base and the gripper. Due to the precision of the 3D printer used, we have sanded some printed parts. Especially the gears, as they did not fit well with other parts.

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image (7).jpg" width="300"/>
</p>

### 2.1.3. Component testing

Our recommendation is to test each component separately. Therefore, in the case of the LCD display we have used the code provided in the following [link](https://docs.arduino.cc/learn/electronics/lcd-displays) or you can see another example [here](https://github.com/danibcorr/creative_electronics_final_project/tree/main/Tests/prueba_lcd). In the case of the servomotors we have an example code [here](https://github.com/danibcorr/creative_electronics_final_project/tree/main/Tests/prueba_servos) and finally for the buttons [here](https://github.com/danibcorr/creative_electronics_final_project/tree/main/Tests/prueba_botones)

Although the connections are shown in the link provided above, we attach an image with the connections we have made in the case of the LCD panel using the test code:

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/image (8).jpg" width="300"/>
</p>

As for the joysticks, it is important to know what your axes are along with the range of values in which each axis is located. This way we get to configure the robot arm to move in a restricted area acquiring more control over its positions.

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/Espa%C3%B1ol/Brazo%20Robo%CC%81tico/imagen (9).png" width="300"/>
</p>

## 2.2. Designing and printing the control box

Once we have prepared all the components that are going to be inside the control box, it is the turn to design the box.

## 2.5. The code

The state machine used in the programming is shown below. It has 5 main states from which it will jump as the corresponding buttons are pressed. With the intention of knowing the state we are in and to provide a friendlier interface, we display the current state through the LCD screen.

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/English/ROBOTIC%20ARM/Diagram_EN.png" width="500"/>
</p>

The robotic arm can be in two modes, manual or automatic.

Initially the robotic arm would be in **Home** mode.

If the robotic arm is in **Home** mode and someone presses the yellow button, it will switch to manual mode, where the person can control the robotic arm with the joysticks on the control box. When the robotic arm is in this mode, if someone presses the red button it will return to **Home** mode.

If the robotic arm is in **Home** mode and someone presses the blue button, it will switch to **Automatic** mode. In this mode, pressing the green button will **execute** the last movements it has recorded, now if someone presses the blue button it will **record** the movements, but pressing the red button will return to **Automatic** mode.

We go back to **Automatic** mode, if you press the red button it will start **recording** movements, if you press the green button it will **stop recording** and **execute**.
