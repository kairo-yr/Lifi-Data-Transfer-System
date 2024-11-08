#include <Keypad.h>

const byte ROWS = 4; // Four rows on the keypad
const byte COLS = 4; // Four columns on the keypad

// Define the key map and initialize the keypad library
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int ledPin = 10; // LED connected to pin 10

// Function to blink LED for each binary '1' in the code pattern
void blinkLED(String binaryPattern) {
  for (int i = 0; i < binaryPattern.length(); i++) {
    if (binaryPattern[i] == '1') {
      digitalWrite(ledPin, HIGH);  // Turn LED on (blink)
      delay(500);                   // Wait for 500 ms (visible blink)
      digitalWrite(ledPin, LOW);   // Turn LED off
    }
    delay(500);  // Pause between bits
  }
}

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);  // Start serial communication
}

void loop() {
  char key = keypad.getKey();  // Check if a key is pressed

  if (key) {
    Serial.print("Key pressed: ");
    Serial.println(key);

    // Map each key to a unique binary string (adjust as needed)
    String binaryPattern = "";
    switch (key) {
      case '1': binaryPattern = "101"; break;
      case '2': binaryPattern = "110"; break;
      case '3': binaryPattern = "111"; break;
      case '4': binaryPattern = "100"; break;
      case '5': binaryPattern = "011"; break;
      case '6': binaryPattern = "001"; break;
      case '7': binaryPattern = "010"; break;
      case '8': binaryPattern = "000"; break;
      case '9': binaryPattern = "1101"; break;
      case '0': binaryPattern = "0010"; break;
      case '#': binaryPattern = "0101"; break;
      case '*': binaryPattern = "1001"; break;
      default: binaryPattern = "0000"; break;  // Default to a no-blink pattern
    }
    blinkLED(binaryPattern);  // Blink LED according to binary code
  }
}
