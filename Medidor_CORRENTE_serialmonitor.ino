// EmonLibrary examples openenergymonitor.org, Licence GNU GPL V3


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;                   // Create an instance


LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{  
  Serial.begin(9600);
  
  emon1.current(1, 60);             // Current: input pin, calibration.

  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
}

void loop()
{
  double Irms = emon1.calcIrms(1480);  // Calculate Irms only
  
  //Serial.print(Irms*110.0);	       // Apparent power
  Serial.print("CORRENTE: ");
  Serial.print(Irms);		       // Irms
  Serial.println("A");
 
  //Imprimir no LCD                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                zz
  
  lcd.clear();
  lcd.print("CORRENTE: ");
  lcd.print(Irms);           // Irms
  lcd.print("A");
  delay(10);

}
