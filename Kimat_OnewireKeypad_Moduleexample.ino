//#include <Wire.h>
//#include <LiquidCrystal_I2C.h>
#include <OnewireKeypad.h>

char KEYS[] = {
  '1', '2', '3', 'A',
  '4', '5', '6', 'B',
  '7', '8', '9', 'C',
  '*', '0', '#', 'D'
};

//LiquidCrystal_I2C Lcd(0x20,20,4);
//OnewireKeypad <LiquidCrystal_I2C, 12> KP( Lcd, KEYS, 4, 3, A1, 4700, 1000, 10000 );

OnewireKeypad <Print, 16 > KP2(Serial, KEYS, 4, 4, A0, 4700, 1000, 10000, ExtremePrec );

void setup () {
  Serial.begin(115200);

  //  Lcd.init();
  //  Lcd.backlight();

  // This method is set in the constructor with a default value of 5.0
  // You only need to include this method if your Arduino is not supplying 5v to
  // the keypad. ie. ~4.7v or even with 3.3v Arduino boards too.
  //KP2.SetKeypadVoltage(5.0);
  KP2.SetKeypadVoltage(4.95);
}
void loop()
{

  if ( char key = KP2.Getkey() ) {
    
    switch (KP2.Key_State()) {
      case PRESSED:
        Serial << "Key: " << key << " State: ";
        Serial.println("PRESSED");
        break;

      case RELEASED:
        Serial << "Key: " << key << " State: ";
        Serial.println("RELEASED");
        break;

      case HELD:
        Serial << "Key: " << key << " State: ";
        Serial.println("HOLDING");
        break;
    }
  }
}


