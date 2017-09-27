#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <OnewireKeypad.h>

char KEYS[] = {
  '1', '2', '3', 'A',
  '4', '5', '6', 'B',
  '7', '8', '9', 'C',
  '*', '0', '#', 'D'
};

LiquidCrystal_I2C lcd(0x3F,16,2);
OnewireKeypad <Print, 16 > KP2(Serial, KEYS, 4, 4, A0, 4700, 1000, 10000, ExtremePrec );

void setup () {
  Serial.begin(115200);

  lcd.init();
  lcd.backlight();

  // This method is set in the constructor with a default value of 5.0
  // You only need to include this method if your Arduino is not supplying 5v to
  // the keypad. ie. ~4.7v or even with 3.3v Arduino boards too.
  //KP2.SetKeypadVoltage(5.0);
  KP2.SetKeypadVoltage(4.95);
  lcd.setCursor(0,0);lcd.print(" LAYAD CIRCUITS ");
  lcd.setCursor(0,1);lcd.print("LC 1-WIRE KEYPAD");
  delay(2000);
  lcd.clear();
}
void loop()
{
  if ( char key = KP2.Getkey() ) {
    switch (KP2.Key_State()) {
      case PRESSED:
        lcd.clear();
        lcd.setCursor(0,0);lcd.print("LC 1-WIRE KEYPAD");
        lcd.setCursor(2,1);lcd.print(key);
        lcd.setCursor(4,1);lcd.print(": PRESSED");
        Serial.print(key);
        Serial.println(" PRESSED");
        break;

      case RELEASED:
        lcd.clear();
        lcd.setCursor(0,0);lcd.print("LC 1-WIRE KEYPAD");
        lcd.setCursor(2,1);lcd.print(key);
        lcd.setCursor(4,1);lcd.print(": RELEASED");
                Serial.print(key);
        Serial.println(" RELEASED");
        break;

      case HELD:
        lcd.clear();
        lcd.setCursor(0,0);lcd.print("LC 1-WIRE KEYPAD");
        lcd.setCursor(2,1);lcd.print(key);
        lcd.setCursor(4,1);lcd.print(": HOLDING");
        Serial.print(key);
        Serial.println(" HOLDING");
        break;
    }
  }
}


