//Buttons (traced from the schematics)
#define BTN1 0
#define BTN2 1
#define BTN3 2

//I2C Oled (traced from the schematics)
#define SCL 23
#define SDA 22

//Buzzer (traced from the schematics)
#define BUZZER 18 

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Kept D-prefix pins as requested
#define BTN_LEFT    D1
#define BTN_MIDDLE  D2
#define BTN_RIGHT   D0
#define BUZZER_PIN  D10

struct Pet {
  int hunger;
  int happiness;
  int energy;
  unsigned long age;
};

Pet pet;

enum Screen {
  SCREEN_MAIN,
  SCREEN_FEED,
  SCREEN_PLAY,
  SCREEN_SLEEP,
};
Screen currentScreen = SCREEN_MAIN;

//UPDATE PET Function
unsigned long lastUpdate = 0;

void updatePet() {
  if (millis() - lastUpdate > 10000) {  // every 10 seconds
    
    // Fixed: Handle passive logic based on screen state
    if (currentScreen == SCREEN_SLEEP) {
      // Pet recovers energy over time while sleeping
      pet.energy += 15;
      if (pet.energy >= 100) {
        pet.energy = 100;
        currentScreen = SCREEN_MAIN; // Wakes up automatically when full!
      }
    } else {
      // Normal ticking down when awake
      pet.hunger--;
      pet.happiness--;
      pet.energy--;
    }

    if (pet.hunger < 0) pet.hunger = 0;
    if (pet.happiness < 0) pet.happiness = 0;
    if (pet.energy < 0) pet.energy = 0;

    pet.age += 10;
    lastUpdate = millis();
  }
}

//Button Press Function
unsigned long lastButtonPress = 0;

void checkButtons() {
  if (millis() - lastButtonPress < 200) return;  // debounce

  // Fixed: Pressing any button while sleeping wakes the pet up
  if (currentScreen == SCREEN_SLEEP) {
    if (digitalRead(BTN_LEFT) == LOW || digitalRead(BTN_MIDDLE) == LOW || digitalRead(BTN_RIGHT) == LOW) {
      currentScreen = SCREEN_MAIN;
      tone(BUZZER_PIN, 2000, 100); // Wake up tone
      lastButtonPress = millis();
      return;
    }
  }

  // Normal button routine when awake
  if (digitalRead(BTN_LEFT) == LOW) {
    currentScreen = SCREEN_FEED;
    tone(BUZZER_PIN, 3000, 50);
    lastButtonPress = millis();
  }
  else if (digitalRead(BTN_MIDDLE) == LOW) {
    currentScreen = SCREEN_PLAY;
    tone(BUZZER_PIN, 4000, 50);
    lastButtonPress = millis();
  }
  else if (digitalRead(BTN_RIGHT) == LOW) {
    currentScreen = SCREEN_SLEEP;
    tone(BUZZER_PIN, 3500, 50);
    lastButtonPress = millis();
  }
}

//Screen Logic
void handleScreenLogic() {
  switch(currentScreen) {
    case SCREEN_FEED:
      pet.hunger += 10;
      if (pet.hunger > 100) pet.hunger = 100;
      currentScreen = SCREEN_MAIN; // Direct return for immediate stat boost
      break;

    case SCREEN_PLAY:
      pet.happiness += 10;
      pet.energy -= 5;
      if (pet.happiness > 100) pet.happiness = 100;
      if (pet.energy < 0) pet.energy = 0;
      currentScreen = SCREEN_MAIN; // Direct return for immediate stat boost
      break;

    case SCREEN_SLEEP:
      // Fixed: Removed instant return to MAIN so the sleep state is persistent and visible
      break; 

    case SCREEN_MAIN:
      break; 
  }
}

//CHARACTER SPRITES DRAWINGS
//****************************************//

//NEUTRAL
const unsigned char PROGMEM petNeutral[] = {
  0b00000000, 0b00000000, 0b00000000, 0b00000100,
  0b00000000, 0b00000000, 0b00000000, 0b00000100,
  0b00010000, 0b00000000, 0b00000000, 0b00000100,
  0b00010000, 0b00000000, 0b00000000, 0b00001110,
  0b00111000, 0b00000111, 0b11110000, 0b00011011,
  0b01101100, 0b00001000, 0b00001000, 0b00001110,
  0b00111000, 0b00001011, 0b11101000, 0b00000100,
  0b00010000, 0b00001000, 0b00001000, 0b00000100,
  0b00000000, 0b00000111, 0b11110000, 0b00000000,
  0b01100000, 0b00000000, 0b00000000, 0b00011000,
  0b10010000, 0b00011110, 0b00011000, 0b00100100,
  0b10001000, 0b00110010, 0b00100100, 0b01000100,
  0b11000100, 0b00101010, 0b01010100, 0b10001100,
  0b00110011, 0b00100100, 0b01001011, 0b00010000,
  0b01001000, 0b11100111, 0b11001100, 0b00110000,
  0b10000110, 0b11000000, 0b00000100, 0b01001000,
  0b10000001, 0b00011000, 0b01100100, 0b11000100,
  0b01100001, 0b00011000, 0b01100111, 0b00001100,
  0b00011001, 0b00000000, 0b00000100, 0b00010000,
  0b00100111, 0b00000000, 0b00000111, 0b11110000,
  0b01000001, 0b00000011, 0b10000100, 0b00000000,
  0b00111000, 0b10000000, 0b00001000, 0b01111100,
  0b00000111, 0b11100000, 0b00010000, 0b11000110,
  0b00010000, 0b00110000, 0b00011011, 0b10000010,
  0b00010000, 0b00100100, 0b10000100, 0b00001110,
  0b01101100, 0b01010100, 0b10010111, 0b11111000,
  0b00010000, 0b10001111, 0b11100100, 0b00000000,
  0b00010000, 0b01110000, 0b00011100, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000
};

//SAD
const unsigned char PROGMEM petSad[] = {
  0b00100000, 0b00111000, 0b00000000, 0b00000100,
  0b00100000, 0b01100111, 0b10000000, 0b00000100,
  0b01010000, 0b01000000, 0b11000000, 0b00001010,
  0b00100000, 0b01101100, 0b01100000, 0b00110001,
  0b00100000, 0b00110110, 0b00100000, 0b00001010,
  0b00000000, 0b00011011, 0b00100000, 0b00000100,
  0b00111000, 0b00001100, 0b00100001, 0b11000100,
  0b01000100, 0b00000011, 0b11000111, 0b00100000,
  0b10000111, 0b00000000, 0b00000100, 0b00010000,
  0b10011011, 0b11111111, 0b11111111, 0b00010000,
  0b11100001, 0b10000000, 0b00000001, 0b11110000,
  0b00000001, 0b10000000, 0b00000001, 0b00000000,
  0b00000001, 0b00000010, 0b00100001, 0b11000000,
  0b00000001, 0b00000110, 0b00110000, 0b01100000,
  0b00011111, 0b00011110, 0b00111100, 0b00100000,
  0b00100011, 0b00001100, 0b00011000, 0b00100000,
  0b01000101, 0b00000000, 0b00000000, 0b00100000,
  0b01001001, 0b00001000, 0b00000000, 0b00100000,
  0b01010011, 0b00010100, 0b00000000, 0b00100000,
  0b10100111, 0b11010100, 0b11100000, 0b00100000,
  0b10001001, 0b01001001, 0b00010000, 0b01100000,
  0b11111010, 0b01000000, 0b00000000, 0b11110000,
  0b00010101, 0b11000000, 0b00000001, 0b10001100,
  0b00101010, 0b01000010, 0b00010001, 0b01000010,
  0b00100100, 0b11000010, 0b00010001, 0b01000010,
  0b00011100, 0b10010011, 0b11110101, 0b00100010,
  0b00000000, 0b11000100, 0b00001010, 0b00011100,
  0b00000000, 0b00111000, 0b00000110, 0b00000000,
  0b00000000, 0b00000000, 0b00000000, 0b00000000,
  0b00010000, 0b00000000, 0b00000000, 0b00000000,
  0b01101100, 0b00000000, 0b00000000, 0b00000000,
  0b00010000, 0b00000000, 0b00000000, 0b00000000
};

// HAPPY
const unsigned char PROGMEM petHappy[] = {
  0b00000000, 0b00010111, 0b11010000, 0b00001000,
  0b00000000, 0b00001000, 0b00100000, 0b00001000,
  0b00100000, 0b00000111, 0b11000000, 0b00010100,
  0b00100000, 0b00110000, 0b00110000, 0b01100011,
  0b01010000, 0b01001000, 0b01001000, 0b00010100,
  0b00100000, 0b01000100, 0b01001001, 0b11001000,
  0b00101110, 0b01000100, 0b10001010, 0b00101000,
  0b00010001, 0b01000011, 0b10000100, 0b00100000,
  0b00001000, 0b11000000, 0b00000101, 0b11000000,
  0b00001100, 0b11001100, 0b01100111, 0b00100000,
  0b00010011, 0b11010010, 0b10010100, 0b00100000,
  0b01010000, 0b10000000, 0b00000100, 0b11000010,
  0b10101000, 0b10000001, 0b00001011, 0b00100101,
  0b01001111, 0b10001000, 0b01010000, 0b11100010,
  0b00010000, 0b11100111, 0b10011111, 0b10000000,
  0b00001000, 0b00100011, 0b00000100, 0b11100000,
  0b00000111, 0b11100000, 0b00001100, 0b00111000,
  0b00000000, 0b00100100, 0b10001000, 0b00000100,
  0b00000000, 0b00100111, 0b10000111, 0b00000100,
  0b00000000, 0b00011000, 0b01100101, 0b10000100,
  0b00000000, 0b00000000, 0b00011100, 0b10001000,
  0b00000000, 0b01000000, 0b00000000, 0b01110000,
  0b00010000, 0b10100000, 0b00000000, 0b00000000,
  0b00010000, 0b01000000, 0b00000100, 0b00000000,
  0b00010000, 0b00000000, 0b00001010, 0b00000000,
  0b00101000, 0b00000000, 0b00000100, 0b00000000,
  0b11000110, 0b00000000, 0b00000000, 0b00000000,
  0b00101000, 0b00000000, 0b10000000, 0b00000000,
  0b00010000, 0b00000000, 0b10000000, 0b00000010,
  0b00010000, 0b00000001, 0b01000000, 0b00000101,
  0b00010000, 0b00000110, 0b00110000, 0b00000010,
  0b00000000, 0b00000001, 0b01000000, 0b00000000
};

// SLEEP
const unsigned char PROGMEM petSleep[] = {
  0b00000000, 0b00000000, 0b00000011, 0b11000000,
  0b01000000, 0b00000000, 0b01111000, 0b10000100,
  0b10100000, 0b01111100, 0b00010001, 0b00000100,
  0b01000001, 0b11000100, 0b00100011, 0b11000100,
  0b00000011, 0b00100100, 0b01111000, 0b00011011,
  0b00000110, 0b01001100, 0b00000000, 0b00000100,
  0b00001100, 0b10011001, 0b11100000, 0b00000100,
  0b00011001, 0b00110000, 0b01000000, 0b00000100,
  0b00010010, 0b01100000, 0b10000000, 0b00000000,
  0b00001000, 0b11000001, 0b11100000, 0b00000000,
  0b00001111, 0b10001100, 0b00000000, 0b00000000,
  0b11100000, 0b00010011, 0b11111110, 0b00000000,
  0b10010000, 0b00100010, 0b00000011, 0b10000000,
  0b01001000, 0b01000010, 0b00000000, 0b11000000,
  0b01001100, 0b01000010, 0b00011000, 0b01100000,
  0b01000111, 0b10000111, 0b00000111, 0b00110000,
  0b01100000, 0b00000100, 0b11110000, 0b10010000,
  0b01001100, 0b01100100, 0b00001110, 0b01010000,
  0b01000000, 0b00001000, 0b00000001, 0b11110000,
  0b01000000, 0b00001000, 0b00000000, 0b00001000,
  0b00100011, 0b00001000, 0b00001000, 0b00001000,
  0b00100001, 0b00010000, 0b00110000, 0b00001000,
  0b00100000, 0b00010000, 0b01100000, 0b00001000,
  0b00010000, 0b00100000, 0b11100000, 0b01001000,
  0b00101111, 0b11111111, 0b11100000, 0b10001000,
  0b00100011, 0b11110000, 0b00111111, 0b00001000,
  0b00100001, 0b10001101, 0b11100000, 0b00010000,
  0b01011000, 0b11000110, 0b00000000, 0b00100010,
  0b01000111, 0b10111101, 0b11111111, 0b11000010,
  0b10100000, 0b00000000, 0b00000000, 0b00000101,
  0b10111000, 0b00000000, 0b00000000, 0b00011101,
  0b01000000, 0b00000000, 0b00000000, 0b00000110
};

//***********************************************************
void drawBar(int x, int y, int value) {
  int maxBarWidth = 62; // Prevents clipping out the right boundary
  int barHeight = 5;    // Balanced text to spacing alignment
  int fillWidth = map(value, 0, 100, 0, maxBarWidth);

  display.drawRect(x, y, maxBarWidth, barHeight, SSD1306_WHITE);       // outline
  display.fillRect(x, y, fillWidth, barHeight, SSD1306_WHITE);        // filled portion
}

void render(){
  display.clearDisplay();
  const unsigned char* sprite;

  // Fixed: Validates sleep condition properly
  if (currentScreen == SCREEN_SLEEP) {
    sprite = petSleep;
  } else if (pet.hunger < 30 || pet.happiness < 30 || pet.energy < 30) {
    sprite = petSad;
  } else if (pet.hunger > 50 && pet.happiness > 50 && pet.energy > 50) {
    sprite = petHappy;
  } else {
    sprite = petNeutral;
  }

  // Refactored Layout: Pet rendered left (x=0) to make safe space for UI rows
  display.drawBitmap(0, 4, sprite, 32, 32, SSD1306_WHITE);
  display.setTextSize(1);

  // Status bars rendered at x=38 to remove any overlaps
  display.setCursor(38, 4);
  display.print("HUN");
  drawBar(62, 5, pet.hunger);

  display.setCursor(38, 14);
  display.print("HAP");
  drawBar(62, 15, pet.happiness);

  display.setCursor(38, 24);
  display.print("ENG");
  drawBar(62, 25, pet.energy);

  // Bottom action options adjusted perfectly within 128px screen wrap constraints
  int textWidth = 102;
  int x = (128 - textWidth) / 2;  // 13

  display.setCursor(13, 52);
  display.println("Feed  Play  Sleep");

  display.display();
}

void setup() {
  pinMode(BTN_LEFT, INPUT_PULLUP);
  pinMode(BTN_RIGHT, INPUT_PULLUP);
  pinMode(BTN_MIDDLE, INPUT_PULLUP); // Fixed: Missing trailing parenthesis added
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Fixed: Hardware connection safety check loop
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while(true); // Dead halt if I2C display address is not acknowledging
  }
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 24);
  display.println("Tamagotchi Init...");
  display.display();
  delay(1000);

  pet.hunger = 80;
  pet.happiness = 80;
  pet.energy = 80;
  pet.age = 0;
}

void loop() {
  checkButtons();       // 1. Read input
  updatePet();          // 2. Update state over time
  handleScreenLogic();  // 3. Process actions
  render();             // 4. Display results
  delay(100);           // 5. Short pause
}
