# ROBOTIC ARM

# Índex

# 1. Abstract

This Project consists on build and program a robotic arm. It would be able to do and repeat movements. All controlled by an Arduino mega.

This project has arisen for the elaboration of the final project of the Creative Electronics course, a subject belonging to the University of Málaga (UMA). 

The whole project has been carried out by Clara Rubio Almagro, Laura Sánchez Sánchez and Daniel Bazo Correa, students of Electronic Systems Engineering at the University of Málaga.

The main idea, robotic arm structure, starting code and tools/utilities can be found at this [link](Brazo Robótico/image (1).png).

# 2. Steps

## 2.1. Components

The components required are:

- Arduino Mega.
- 2 joystick.
- LCD display.
- 4 servo motors.
- 4 buttons.
- And also we need the robot’s pieces, in this case we have printed them.

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/English/ROBOTIC%20ARM/image.png"/>
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/English/ROBOTIC%20ARM/image (1).png"/>
</p>

We have made some changes. The main changes we have done are:

- On the original project the control box had a tactile screen for moving through the different modes, but we have used an LCD display that will show in which mode is the robotic arm, and four buttons for changing modes.
- We also have designed our new control box so in that way it will fit better the modifications of the LCD display and the buttons.
- In the robotic arm we have changed some pieces that we haven’t found in shops, so we have designed and printed them, these pieces are the two brass pipes. The rest of pieces are the same as the original project.

## 2.2. Buttons module

We have designed and welded a module for the four buttons.

The design is:

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/English/ROBOTIC%20ARM/image (2).png"/>
</p>

In the image above, we had to substitute VCC for GND and vice versa. Subsequently, the buttons have been configured as input configured with Pull-UP resistors.

The result obtained after welding was as follows:

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/English/ROBOTIC%20ARM/image (3).png"/>
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/English/ROBOTIC%20ARM/image (4).png"/>
</p>

## 2.3. Building the arm

In this part, we are going to explain how to match the different pieces of the arm.

First, we are starting with the base and the gripper, because the servo motor will be situated in them.

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/English/ROBOTIC%20ARM/image (5).png"/>
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/English/ROBOTIC%20ARM/image (6).png"/>
</p>

And then we have built the arm’s elbow with the other servo motor and we have matched it with the base and the gripper.

We sanded some pieces, especially the gears because they didn't fit well with the others (this will depend on the error associated with the 3D printer).

## 2.4. The code

In the case of the LCD display we have used the code provided in the following [link](https://docs.arduino.cc/learn/electronics/lcd-displays).

The state machine used in the programming is shown below. It has 5 main states from which you will jump as you press the corresponding buttons. With the intention of knowing the state in which we are and to offer a more user-friendly interface, we show the current state through the LCD screen.

<p align="center">
  <img src="https://github.com/danibcorr/creative_electronics_final_project/blob/main/Steps/English/ROBOTIC%20ARM/Diagram_EN.png"/>
</p>

The robotic arm can be in two modes, manual or automatic.

At the beginning the robotic arm would be in the **Home** mode.

If the robotic arm is in **Home** mode and someone press the yellow button it will change to manual mode, in which the person will be able to control the robotic arm with the joystics that are in the control box. When the robotic arm is in this mode, if anyone press the red button it would return to the **Home** mode.

If the robotic arm is in **Home** mode and someone presses the blue button it will change to **Automatic** mode. In this mode, if the green button is pressed it will **execute** the last movements that it has recorded, now if anyone presses the blue button it will **record** the movements, but if the red button is pressed it will return to **Automatic** state.

Back to the **Automatic** mode, if the red button is pressed it will start to **record** movements, if the green button is pressed it will **stop recording** and will **execute**.
