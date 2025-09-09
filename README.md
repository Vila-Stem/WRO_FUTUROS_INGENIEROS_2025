github# Vila-Stem 8
![VS8 (1)](https://github.com/user-attachments/assets/a4774f91-6fe7-40f2-a07a-25e1a2d4d9e4)
# Table of contents
### [Our journey](#our-journey)
### [Team](##Team)
### [Videos](/Videos/)
### [Team Photos](/t-photos/)
### [Vehicle Photos](/v-photos/)
### [List of materials used for the regional](#List-of-materials-used-for-the-regional)
# Our journey
This text contains our struggles and achievements, which we have came across during our few months of preparation. How many things we had to redesign, how many things we had to figure out to make our robot work.

## Team
Our team consists of 3 members and a coach, we are the Vila-Stem 8 team from Vila-real. This is our first year competing together in WRO, but is our first year in the Future Engineers category.

>Members

- **Juan Silvestre**
  - First year competing in WRO and in the Future Engineers category.
- **Anes Rahmi**
  - First year competing in WRO and in the Future Engineers category.
- **Ainhoa Mormeneo**
  - Fourth year competing in WRO and first time in the Future Engineers category.

>Coach

- **Roman Mormeneo**
  - vilastemrobotics@gmail.com

>Links to our socials:
  - **Facebook**:https://www.facebook.com/share/1NDRsjeibe/
 
  - **Instagram**:https://www.instagram.com/vila_stem?igsh=Nmw1OHVpN242b2xh

  - **Tiktok**:https://www.tiktok.com/@vila_stem?_t=ZN-8yPXRYwSxYk&_r=1

  - **Youtube**:https://youtube.com/@vila_stem?si=-ah0tXMzC0TzTKeQ
# Robot
Building the robot was one of the easiest things ever. We started by taking ideas from previous years. We bought the basics, board one, some wheels, screws and distance sensors. The base we decided to make it from scratch in 3d. We drew what we wanted and then we took it to Tinkercad where we printed it. We made a nice base with everything ready, where to put the sensors, the battery and the most important thing, the board!

# Errors
When we started programming we realized towards the end that we had to modify the structure of the robot a bit. The sensors that we had placed on the sides needed to be moved to the corners, as they would detect the walls better.

# List of materials used for the regional:

- Arduino V4 minima (1)
    - Main controller board
- Camara HuskyLens (1)
    - Used to identify colors
- Expansion shield (1)
    - Used to simplify connections to the Arduino
- Ultrasonic Sensor (3)
    - Used to avoid the walls
- Battery 5.000mA (1)
- Voltage regulator LM2596S (1)
    - Outputs 5V at 1A
- Motor Driver L298N (1)
- Button switch (1)
    - Starts the program
- Master switch (1)
    - Connects the battery
- Soldering Board (1)
- 10k resistor (1)
    - Pullup resistor
- Chassis Kit (1)
    - Purchased
- 12V dc motor (1)
- 6V servo ans steering rods (1)
- Metal frame (1)
    - The frame of the robot
- Transmission (Axle, gear reductor) (1)
- 3D printed chassis (1)
    - Added for more space to store the battery and equipment

# Modification after the regional competition
In Denia we learned a lot about our mistakes, we also followed improvement instructions that our jury told us. 
What we modified the most was the robot: We changed the arduino for an ESP32 because it gave us better results, we were thinking of using a rasperry pi but we control more C +++ and not so much phyton. Other modifications were in the program, which we were told was a botch, that the variables that we had created should be in English and not in Valencian. All the recommendations that they gave us we wrote them down to improve the robot for the final of Spain, in Cáceres.In addition to following the advice of our judges in Denia, we looked at the mistakes the robot made there and sought a solution. For the competition, we brought three distance sensors, but in the end we only used two, and they gave us quite a few problems. To improve this, we decided to install six distance sensors, reinforcing each angle so that we could work better. We bought the materials we needed and got to work.We decided to put two on each side, one at the front and one at the rear, making a total of six. Now it was less likely that the robot would fail us due to “too long a distance” that it couldn't read.
With just a few weeks to go before the competition, we've had a lot of errors. We started with the programming, where at first we couldn't find the “ideal” angle for the robot's laser sensors. That was quickly solved by placing a small piece under the support so that it could read the wall of the field. Before, when it was looking down, it read the ground, but now it reads the field.
Another problem we had was not having a black competition field. Through various tests with the laser, we realised that its behaviour changed depending on the colour where the laser was reflected. To solve this, we bought black tape, placed it on the field and tested the robot, but then we discovered another problem. When we put the tape on, we saw that it was reflective; it wasn't matte tape, but shiny, and the sensor couldn't read it because it reflected too much. Third time lucky: we painted the field with matte black paint. Since then, the robot has been reading well; it was a definitive solution.
After successfully programming the laser sensor, we looked for a solution to determine how many turns the robot had made and when it should stop. To do this, we thought about reading the lines without the camera, so we came up with the idea of using a colour sensor. We calculated the approximate values given by the coloured lines: 
Orange: 3677-3296
Blue: 5901-3900
White: 4439 

# List of materials used for the nacional:
- ESP-32
    - (Microcontroller)
- TCS34725
  - (Colour sensor)
- VL53L1X
    - (ToF/distance sensor)
- L298n
    - (Motor driver)
- Lm2596
    - (Buck Converter)
- HuskyLens Camera
    - (Colour detection, for obstacles)
- Switch
    - (Master Power)
- Pushbutton
    - (Start)
- Servo
    - (Steering)
- 12V DC motor
    - (movement)
- Pull-up resitors

