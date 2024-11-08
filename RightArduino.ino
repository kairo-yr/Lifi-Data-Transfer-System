#include <LiquidCrystal.h>

const int ldrPin = A0; // LDR sensor connected to analog pin A0
const int threshold = 500; // Threshold value for detecting LED blink (adjust as needed)

// Initialize the LCD (pin numbers may vary based on your setup)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

long lastBlinkTime = 0;  // Time of last blink detected
String receivedBinaryPattern = "";  // Store the binary pattern of blinks
int blinkCounter = 0;    // Counter for detecting each blink

void setup() {
  lcd.begin(16, 2); // Initialize the LCD's columns and rows
  lcd.print("Waiting for input...");
  pinMode(ldrPin, INPUT);  // Set LDR as input
  Serial.begin(9600);  // Start serial communication
}

void loop() {
  int ldrValue = analogRead(ldrPin);  // Read the LDR value

  // If LDR value is above the threshold, we detect a blink
  if (ldrValue > threshold) {
    if (millis() - lastBlinkTime > 500) {  // Debounce to avoid multiple readings
      lastBlinkTime = millis();
      receivedBinaryPattern += '1';  // Register '1' for blink detected
      blinkCounter++;  // Count the blink
    }
  } else {
    // If no blink detected, register '0' after a small delay (debouncing)
    if (millis() - lastBlinkTime > 500 && blinkCounter > 0) {
      receivedBinaryPattern += '0';  // Register '0' for no blink
    }
  }

  // After enough bits are received, decode the pattern
  if (receivedBinaryPattern.length() >= 3) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Decoded Key:");

    char decodedKey = decodeBlinkPattern(receivedBinaryPattern);  // Decode the binary pattern
    lcd.setCursor(0, 1);
    lcd.print(decodedKey);  // Display the decoded key on the LCD

    receivedBinaryPattern = "";  // Reset the binary pattern for next input
    blinkCounter = 0;  // Reset the blink counter
  }
}

// Function to decode the binary pattern into corresponding key
char decodeBlinkPattern(String binaryPattern) {
  // Adjust the binary patterns to match the ones set in the Left Arduino code
  if (binaryPattern == "101") return '1';
  if (binaryPattern == "110") return '2';
  if (binaryPattern == "111") return '3';
  if (binaryPattern == "100") return '4';
  if (binaryPattern == "011") return '5';
  if (binaryPattern == "001") return '6';
  if (binaryPattern == "010") return '7';
  if (binaryPattern == "000") return '8';
  if (binaryPattern == "1101") return '9';
  if (binaryPattern == "0010") return '0';
  if (binaryPattern == "0101") return '#';
  if (binaryPattern == "1001") return '*';
  return '?';  // Return a '?' if no match
}
