# BibliGotchi

<p>
  A custom made Tamagotchi, with a heavenly touch. Made by a 17 year old from Bosnia and Herzegovina, this project is a showcase of my learning in the hardware
  related space. I made this using KiCad for the PCB, OnShape for the case and Arduino IDE for the firmware.
</p>
<img src="Images/Case_Images/Top_Side-View.png" width="760">
<p>
  This tamagotchi features 3 main stats: Hunger, Energy and Happiness.
  You can improve these by interacting with the tamagotchi through the buttons, each button does something different , like play, feed or sleep.
  There is also 4 different screens depending on the stats: a screen with a neautral feeling, happy screen, sad screen and a sleeping screen.
  I drew my own 32x32 sprites, you can draw your own to customize this project even more.
</p>
<h1>
  Why did I make this project?
</h1>
<p>
  I made this project to qualify to a hackathon called Fallout , organized by a nonprofit organization called Hack Club. I chose to make this tamagotchi because 
  it really seemed like a not so simple , yet not super-advanced project , and at the same time it looked really cool and was interactive which is really importand nowadays
  in this world full of everything on the web, having something that you interact with physically makes it different and cooler, a project I really was hoping
  to build. It helped me better understand Firmware development, and also I improved my case design skills.
</p>

---
<p align="center">
  <a href="Zine.pdf">Read the zine</a>
  &nbsp;|&nbsp;
  <a href="PCB-Files/Gerbers.zip">Download Gerbers</a>
  &nbsp;|&nbsp;
  <a href="Case-Files/">STEP case files</a>
  &nbsp;|&nbsp;
  <a href="BOM/BOM.csv">PCB BOM</a>
</p>

---

## Overview
BibliGotchi is a project built on the Seeed studio xiao-esp32-c6 , using a custom PCB designed in KiCad to make everything connected and work. BibliGotchi Features a 0.96' OLED Screen, a 3.7V 500mAH battery, a passive buzzer, 3x buttons for interactivity. I also built a custom case in OnShape, here is the <a href="https://cad.onshape.com/documents/44d918d4bf107306610f1545/w/f7f086a823beff1369bb4e84/e/70df229ea8fe1c8cd39e3565">OnShape Link </a>. The case features nicely made top and bottom cover, that I used filet on to eliminate sharp edges, I also added holes for the USB-C connection to the ESP32, the screen and inserting the battery. I also made a custom enclosure inside to keep the battery in, where u screw in 2 screws after putting in the battery and they keep it in. The firmware is developed in Arduino UNO using C++, it keeps the record of age, happines and other stats, and updates them as we interact with the BibliGotchi.It also displays the stats with progress bars.I also drew 4 sprites for the sleep,happy,sad,neutral states in a 32x32 pixel format.

## Case Galery

| Top View | Top Side View|
| --- | --- |
| <img src="Images/Case_Images/Top_View.png" alt="Normal case view" width="420"> | <img src="Images/Case_Images/Top_Side-View.png" alt="Top side-view" width="420"> |
| Bottom View | Exploded View |
| <img src="Images/Case_Images/Bottom_View.png" width="420"> | <img src="Images/Case_Images/Exploded_View.png" width = "420">|


## PCB Gallery

| Top View 1 | Top View 2 |
| --- | --- |
| <img src="Images/PCB_Images/PCB_Front1.png"> | <img src="Images/PCB_Images/PCB_Front2.png"> |
| Bottom View 1 | Bottom View 2 |
| <img src="Images/PCB_Images/PCB_Back1.png"> | <img src="Images/PCB_Images/PCB_Back2.png"> |

## Routing

| Top Routing | Bottom Routing |
| --- | --- |
| <img src="Images/PCB_Images/Routing_Top.png"> | <img src="Images/PCB_Images/Routing_Bottom.png"> |


## How to Assemble the Case Tutorial
# Step 1
<p>
  Just place the PCB on the bottom part , align the holes with the supports, just like this:
</p>

| Align the PCB | Place it on the bottom part |
| --- | --- |
| <img src="Images/PCB_Images/Step0_1.png"> | <img src="Images/PCB_Images/Step0_2.png"> |

# Step 2
<p>
  Put heat set inserts into the hole in the bottom for the M3 screw, then screw in the M3 screws to connect the bottom part, top part and secure the PCB:
</p>

| Align the Top Part | Screw it into the bottom part through the PCB |
| --- | --- |
| <img src="Images/Assembly_Tutorial/Step1_1.png"> | <img src="Images/Case_Images/Top_Side-View.png"> |

# Step 3
<p>
  Put heat set inserts into the hole in the bottom for the M2 screw, then screw in the M2 screws:
</p>

| Put the M2 screws into the holes | Screw it in firmly |
| --- | --- |
| <img src="Images/Assembly_Tutorial/Step3_1.png"> | <img src="Images/Assembly_Tutorial/Step3_3.png"> |

# Step 4
<p>
 Put the battery into the battery holder I made in the case:
</p>

| Put the battery into the battery holder |
| --- |
| <img src="Images/Assembly_Tutorial/Step4_2.png"> |

# Step 5
<p>
  Put the heat set inserts here and then screw into them the little M2 L8mm screws, that will hold the battery in:
</p>

| Put the heat set M2 inserts in and screw in the L8mm M2 screws into them | Now they hold the battery firmly |
| --- | --- |
| <img src="Images/Assembly_Tutorial/Step5_1.png"> | <img src="Images/Assembly_Tutorial/Step5_2.png"> |

---

## Firmware 

<p>
  The firmware is made in Arduino IDE using C++, it tracks the age of the tamagotchi, and is listening for clicks of buttons to update the tamagotchi.
  
</p>
