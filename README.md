# Bi-Directional Counter
The following repo contains a written report as compiled on LaTex and codes of a project that involved the use of just **two ultrasonic sensors** and **Arduino Unos**
to create a low-cost **Bi-Directional Counter**, that can be employed in assembly line and transportation scenarios to count the number of objects entering and exiting a particular region.

## The Overview
This project undertaken as a part of the **ES-116 Course: Principles and Applications of Electrical Engineering** at **Indian Institute of Technology, Gandhinagar** in the **April 2023**.
The course project was open ended as to solve some real life scenario. The ideation behind the whole project was **crowd-regulation** where you could count accurately
the number of people entering or exiting a certain area. 

## The Ideation and Approach
This project approched the solution by the use of **two Ultrasonic Senors** placed in succession.

### PART-I: Just the Counting
Crossing the sensors one way would increase the count and going the contrary would decrease it. There were many online tutorials that aimed to just the number of
people passing in front of the sensor. That too came at a limitation as the Arduino's code runs at a loop and staying in front of the sensor would keep incrementing the count continuosly.
This problem was tackled by a clever idea wherein we stored **current and previous distance values** of the ultrasonic sensor. If the current distance value became significantly high when compared to the previous iteration's value, only then was the counter value incresed.
The file [CounterSingle](CounterSingle.ino) captures the same. 

### PART-II: The Bi-Directionality
Now came the bigger issue to tackle. This hadn't been done before. We thought of replacing the sensors but then a great idea struck. The idea was to keep two variables named **flag1** and **flag2** for each of the sensors. To increment the count, the item should first cross the first sensor and the flag1's value is increased, now we check if the value of **flag1 is greater than flag2**, if it is, only then is the **counter value increased**. Once the item crosses the second sensor, flag2 now also increments, and again we check **if flag2 > flag1**, but now since both have same values, so **we don't decrement the counter value**. This simple but clever algorithm was captured in the [Final Code File](BiDirectional-Final.ino)

### The Video
Do check out [this video](https://iitgnacin-my.sharepoint.com/:v:/g/personal/22110089_iitgn_ac_in/EfQ8WXY99V5NoKbG4jKfxDEBgKDCGY1H6GR3wmn3eBjVxw?nav=eyJyZWZlcnJhbEluZm8iOnsicmVmZXJyYWxBcHAiOiJPbmVEcml2ZUZvckJ1c2luZXNzIiwicmVmZXJyYWxBcHBQbGF0Zm9ybSI6IldlYiIsInJlZmVycmFsTW9kZSI6InZpZXciLCJyZWZlcnJhbFZpZXciOiJNeUZpbGVzTGlua0NvcHkifX0&e=SZG8Lq) for the same !
