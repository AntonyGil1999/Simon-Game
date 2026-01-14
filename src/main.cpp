#include <LiquidCrystal.h>

#define ON 0
#define OFF 1

// LED pin assignment
int leds[4] = {10, 11, 12, 13};

// Button pin assignment
int buttons[4] = {0, 1, 2, 3};

// Potentiometer
int sensorValue = 0;
int potentiometerPin = A0;

// LCD
const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Pattern and score
int pattern[20];
int patternLength = 2;
int score = 0;
int patternCount = 0;

// Delay (in ms) between two LED lights
int delayTime = 0;



void setup() 
{
  // LED initialization
  for (int i = 0; i < 4; i++)
  {
      // Configure leds[i] pin as output
      pinMode(leds[i], OUTPUT);
      // Turn off the LED
      digitalWrite(leds[i], OFF);
  } 

  // Button initialization
  for (int i = 0; i < 4; i++)
   pinMode(buttons[i], INPUT);

  sensorValue = analogRead(potentiometerPin);
  delayTime = map(sensorValue, 0, 1023, 200, 1000);

  // LCD
  // Set LCD size
  // 16 columns and 2 rows
  lcd.begin(16, 2);
  updateLCD(0);
}



void loop()
{
  delay(1500);
  randomSeed(millis());
  // Read potentiometer to adjust speed
  sensorValue = analogRead(potentiometerPin);
  delayTime = map(sensorValue, 0, 1023, 200, 1000);

  // Generate pattern
  for (int i = 0; i < patternLength; i++)
   pattern[i] = random(0, 4);
 
  // Display pattern
  showPattern();

  // Player turn
  bool ok = playerTurn();
  if (ok) {
    score += patternLength;
    patternLength++;
  } else {
    score -= patternLength;
    patternLength--;
    if (patternLength < 2) patternLength = 2;
    errorFlash();
  }  
  patternCount++;
  updateLCD(0);
  delay(1000);
  if (patternCount >= 10 || score < 0)
   gameOver();
  updateLCD(1);
  delay(1000);
  updateLCD(0);
  
}

// Display LED sequence
void showPattern() {
  for (int i = 0; i < patternLength; i++)
  {
    int numero_de_led = pattern[i];
    int pin_led = leds[numero_de_led];
    digitalWrite(pin_led, ON);
    delay(delayTime);
    digitalWrite(leds[pattern[i]], OFF);
    delay(delayTime);
  }
}

// Player turn
bool playerTurn() {
  unsigned long time_0;
  // Number of milliseconds at this moment
  time_0 = millis();
  for (int i = 0; i < patternLength; i++)
  {
    int pressed = waitForButton(time_0);
    if (pressed != pattern[i]) return false;
  }
  return true;
}

// Wait for a button press and release
int waitForButton(unsigned long t0)
{
  // Continue scanning buttons as long as less than 15s have passed since pattern display
  while ( (millis() - t0) < 15000)
  {
    for (int i = 0; i < 4; i++)
    {      
      // Is button i pressed ( = LOW )?
      if (digitalRead(buttons[i]) == LOW)
      {
        delay(20);
        // Check if it is still pressed
        if (digitalRead(buttons[i]) == LOW) 
        {
          // Wait until button is released
          while (digitalRead(buttons[i]) == LOW)
          {

          }
          
          // Wait 20ms before scanning the next button
          delay(20);
          return i;
        }
      }
    }
  }
  // If we reach here, more than 15s have passed since pattern display
  return -1;
}

// Error LED flash
void errorFlash() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) digitalWrite(leds[j], ON);
    delay(200);
    for (int j = 0; j < 4; j++) digitalWrite(leds[j], OFF);
    delay(200);
  }
}

// LCD update
void updateLCD(int ready)
 {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Score: ");
  lcd.print(score);
  lcd.setCursor(0, 1);
  if (ready)
  {
    lcd.print("Ready ?");
  }
  else
  {
    lcd.print("P:");
    lcd.print(patternLength);
    lcd.print(" N:");
    lcd.print(patternCount);
    lcd.print(" D:");
    lcd.print(delayTime);
    lcd.print("ms");
  }
}

// End of game
void gameOver() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("GAME OVER!");
  lcd.setCursor(0, 1);
  lcd.print("Score: ");
  lcd.print(score);
  while (true);
}