//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>



LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  
}
  

void loop()
{

  
//Nome
lcd.clear();
lcd.setCursor(2,0);
lcd.print("BRUNO");//6 letras
delay(500);  
  
  //Rolando o lcd
  for (int i = 0; i < 12; i++){
        
    lcd.scrollDisplayRight();
    delay(500);
  } 
   for (int i = 0; i < 9; i++){
        
    lcd.scrollDisplayLeft();
    delay(500);
 
 }

//Nome
lcd.clear();
lcd.print("WESLEY");//6 letras
lcd.setCursor(2,0);
delay(500);  
  
  //Rolando o lcd
  for (int i = 0; i < 12; i++){
        
    lcd.scrollDisplayRight();
    delay(500);
  } 
   for (int i = 0; i < 9; i++){
        
    lcd.scrollDisplayLeft();
    delay(500);
 
 }



//Nome
lcd.clear();
lcd.setCursor(2,0);
lcd.print("FELIPE");//6 letras
delay(500);  
  
  //Rolando o lcd
  for (int i = 0; i < 12; i++){
        
    lcd.scrollDisplayRight();
    delay(500);
  } 
   for (int i = 0; i < 9; i++){
        
    lcd.scrollDisplayLeft();
    delay(500);
 
 }


//Nome
lcd.clear();
lcd.setCursor(2,0);
lcd.print("JOSUE");//6 letras
delay(500);  
  
  //Rolando o lcd
  for (int i = 0; i < 12; i++){
        
    lcd.scrollDisplayRight();
    delay(500);
  } 
   for (int i = 0; i < 9; i++){
        
    lcd.scrollDisplayLeft();
    delay(500);
 
 }


//Nome
lcd.clear();
lcd.setCursor(2,0);
lcd.print("KAROLINE");//6 letras
delay(500);  
  
  //Rolando o lcd
  for (int i = 0; i < 12; i++){
        
    lcd.scrollDisplayRight();
    delay(500);
  } 
   for (int i = 0; i < 9; i++){
        
    lcd.scrollDisplayLeft();
    delay(500);
 
 }




}
