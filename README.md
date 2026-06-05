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

### 🛠️ Bill of Materials (BOM)

| Item | Description | Value | LCSC Part | Qty | MOQ | Unit Price | Total Price | Resources |
| :--- | :--- | :--- | :--- | :---: | :---: | :---: | :---: | :--- |
| Battery | Single-cell battery | Battery_Cell |  | 1 | 1 | $5.11 | $5.11 | [Datasheet](https://www.kiwi-electronics.com/image/catalog/pdf/LP503035%20500mAh%203.7V%20%28AD306053%29%2020230615%5B34%5D.pdf), [Purchase Link](https://www.aliexpress.com/item/1005006043243361.html) |
| Buzzer | Passive Buzzer | 1207-P6.5MM | C49246964 | 1 | 10 | $0.03 | $0.32 | [Datasheet](https://www.lcsc.com/datasheet/C49246964.pdf), [Purchase Link](https://www.lcsc.com/product-detail/C49246964.html) |
| Switch | Push button switch, generic, two pins | SW_Push | C2888493 | 3 | 50 | $0.01 | $0.54 | [Datasheet](https://www.lcsc.com/datasheet/C2888493.pdf), [Purchase Link](https://www.lcsc.com/product-detail/C2888493.html) |
| ESP32-C6 MCU | IoT mini development board | XIAO-ESP32-C3-SMD |  | 1 | 1 | $6.15 | $6.15 | [Datasheet](https://files.seeedstudio.com/wiki/SeeedStudio-XIAO-ESP32C6/res/esp32-c6_datasheet_en.pdf), [Purchase Link](https://www.aliexpress.com/item/1005006987272421.html) |
| OLED Display | 0.96' Inch OLED Display | HS96L03W2C03 | C5248080 | 1 | 1 | $2.24 | $2.24 | [Datasheet](https://www.lcsc.com/datasheet/C5248080.pdf), [Purchase Link](https://www.lcsc.com/product-detail/C5248080.html) |
| PCB + Shipping | | | | 1 | 5 | | $30.00 | - |
| **Total** | | | | **8** | **68** | **$13.54** | **$44.36** | |

### ⚙️ Build BOM

| Item | Description | Quantity | Total Price |
| :--- | :--- | :--- | :--- |
| M3 L20 Screws | M3 Screws Length 20mm used to connect the Bottom and Top part and hold the PCB in place | 2 | $0.10 (Bulk: ~$5.00) |
| M2 Screws L16mm | M2 Screws Length 16mm to screw into the sides for more stability | 2 | $0.10 (Bulk: ~$5.00) |
| M2 Screws L8mm | M2 Screws Length 8mm to help hold the battery in place | 2 | $0.10 (Bulk: ~$4.00) |
| M3 Heat Set Inserts | M3 Inserts to help you hold the screw firmly and stable | 2 | $0.10 (Bulk: ~$4.00) |
| M2 Heat Set Inserts | M2 Inserts to hold your screws tight | 4 | $0.20 (Bulk: ~$4.00) |
| **Total** | | **12** | **$0.60** (Actual Bulk Total: ~$22.00) |

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
  The left button does the action Feed, which increses the HUN(hunger) stat, meaning the PET is good on hunger.
  The middle button is for Play which decreases ENG(energy) by 5 , but increases HAP(happiness) by 10;
  The right button makes the PET Sleep, it puts it into the sleep state and displays it sleeping, and while it does so , it increases ENG(energy) by 15.
</p>

## BibliGotchi Different States Pictures

| Sad state (if any stat is < 30) | Happy state (all stats > 50) |
| --- | --- |
| <img src="Images/Firmware_Images/Sad.png"> | <img src="Images/Firmware_Images/Happy.png"> |
| Neutral state (if its not in any other state) | Sleep state (you press the Sleep button |
| <img src="Images/Firmware_Images/Neutral.png"> | <img src="Images/Firmware_Images/Sleep.png"> |

<h2>
  How to install and flash the firmware?
</h2>
<ul>
  <li>
    Go to the <a href=Firmware> Firmware </a> folder of this github page, and install the BibliGotchi_Firmware.ino ;
  </li>
  <li>
    Go into Arduino IDE
  </li>
  <li>
     <h3> Step 1:Install the ESP32 Board Package</h3>
    <p>ESP32 support isn't included by default, so you need to add Espressif's board package URL.</p>
    <ul>
      <li>
        Open the Arduino IDE.
      </li>
      <li>
        Go to File > Preferences (or Arduino IDE > Settings on macOS).
      </li>
      <li>
        In the "Additional Boards Manager URLs" field, add the following URL: https://espressif.github.io/arduino-esp32/package_esp32_index.json > Note: If you already have URLs here, separate entries with commas.
      </li>
      <li>
        Click OK to save the preferences.
      </li>
      <li>
        Wait for the board index to download.
      </li>
    </ul>
  </li>
  <li>
    <h2>Step 2: Install the Board in Boards Manager</h2>
    <ul>
      <li>
        Open the Boards Manager by navigating to Tools > Board > Boards Manager.
      </li>
      <li>
        In the search bar, type esp32.
      </li>
      <li>
        Locate the entry for "esp32 by Espressif Systems".
      </li>
      <li>
        Click the Install button. > Important: Ensure you are using version 3.0.0 or later, which supports the C6.
      </li>
      <li>
        Wait for the installation to finish.
      </li>
    </ul>
  </li>
  <li>
    <h2>Step 3: Make a new project file</h2>
     <p>
   Create a new Arduino sketch: File > New Sketch, then save it as Tamagotchi.ino or whatever you want to call it.
   </p>
  </li>
  <li>
    <h2>Step 4: Select the Board and the Port </h2>
    <ol>
      <li>After making the new project, go to Tools > Board > esp32</li>
      <li>Select your board model: XIAO ESP32C6</li>
    </ol>
  </li>
  <li>
    <h2>Step 5: Install the libraries </h2>
    <p>In Sketch > Include Library > Manage Libraries, install:</p>
    <ol>
      <li>Adafruit SSD1306 (by Adafruit)</li>
      <li>Adafruit GFX Library (by Adafruit), which will be prompted as a dependency</li>
    </ol>
  </li>
  <li>
    <h2>Step 6: Uploading the code </h2>
    <p>Connect your XIAO-ESP32-C6 to your PC or Laptop with Arduino IDE opened with a USB-C cable, Copy and past the BibliGothi_Firmware.ino into your own sketch, or maybe you have installed it and followed the steps above already.</p>
    <ol>
      <li>
        Click the Verify button, looks like a checkmart in the top left corner.
      </li>
      <li>
        Click the Upload button, it is right besides the Verify button , looks like an arrow pointint right.
      </li>
    </ol>
  </li>
  <li>
  <h2>Step 7: Enjoy</h2>
    <p>You have now finished both the case assembly and the firmware setup , so you are free to play with your new friend BibliGotchi.</p>
  </li>
</ul>
