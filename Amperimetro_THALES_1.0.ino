//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "SoftwareSerial.h"
#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;                   // Create an instance

// Cria conexão com bluetooth nas portas padrão /Create a new software  serial
SoftwareSerial bluetooth(0, 1); //RX, TX

//Informar valor da rede para calculo de potencia
int rede = 127;

// LED para identificar status ligado/desligado
#define LED 13

// teste power
int power = 0;
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
int UPP;

void setup()
{
  Serial.begin(9600);               //Inicia comunicação Serial
  bluetooth.begin(9600);            //Inicia comunicação blutooth 
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  
  //Instacia da bib
  emon1.current(1, 8.888);        // Current: input pin, calibration. A calibração é feita assim: (CurrentMax / CurrentMin / ResistordeCarga) no nosso caso (100/0,05/220)

// Vou incluir o blink para saber que o atmega está funcionando
  pinMode(LED, OUTPUT);

  
}
  

void loop()
{
  //Liga led status
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);                       // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW

  
//Calcula a corrente
double Irms = emon1.calcIrms(1480);

//Percebi que a corrente está sendo calculada em dobro ainda não sei como resolver;

//Irms = Irms/2;

//Imprime Corrente no SerialMonitor, LCD e Bluetooth

Serial.print("CORRENTE: ");//corrente no SerialMonitor
Serial.print(Irms);
Serial.println("A");

//lcd.clear(); //Fica piscando a tela demais
lcd.setCursor(0,0); 
lcd.print("CORRENTE: ");//corrente no LCD
lcd.print(Irms);
lcd.print("A ");

bluetooth.print("CORRENTE: ");//corrente no Bluetooth
bluetooth.print(Irms);
bluetooth.println(" A");


//Imprime Potência SerialMonitor e no LCD

Serial.print("POTENCIA: ");
Serial.print((Irms*rede)); // Calculo da Potência
Serial.println(" W");
Serial.println(" ");

//lcd.clear(); //Fica piscando a tela demais
lcd.setCursor(0,1);
lcd.print("POTENCIA: ");// Calculo da Potência
lcd.print((Irms*rede));
lcd.print("W ");

//Espera para atualizar os valores de Corrente e Potencia
delay(500);


UPP = Serial.read();  
if (UPP == 'U') { 
  if (power >= 120) {power = 0;} 
  else { power=power+12; } 
}
  
if (UPP == 'D') { 
  if (power <= 0) {power = 0;} 
  else { power=power-12; } 
}
  Serial.println(power);
}
