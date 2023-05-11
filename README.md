# Bi-Directional Counter
The following repo contains a written report as compiled on LaTex and codes of a project that involved the use of just **two ultrasonic sensors** and **Arduino Unos**
to create a low-cost **Bi-Directional Counter**, that can be employed in assembly line and transportation scenarios to count the number of objects entering and exiting a particular region.

## The Overview
This project undertaken as a part of the **ES-116 Course: Principles and Applications of Electrical Engineering** at **Indian Institute of Technology, Gandhinagar** in the **April 2023**.
The course project was open ended as to solve some real life scenario. The ideation behind the whole project was **crowd-regulation** where you could count accurately
the number of people entering or exiting a certain area. 

## The Ideation and Approach
This project approched the solution by the use of **two Ultrasonic Senors** placed in succession.
Crossing the sensors one way would increase the count and going the contrary would decrease it. There were many online tutorials that aimed to just the number of
people passing in front of the sensor. That too came at a limitation as the Arduino's code runs at a loop and staying in front of the sensor would keep incrementing the count continuosly.
This problem was tackled by a clever idea wherein we stored **current and previous distance values** of the ultrasonic sensor. If the current distance value became significantly high when compared to the previous iteration's value, only then was the counter value incresed.
The file [CounterSingle](CounterSingle.ino) captures the same.
