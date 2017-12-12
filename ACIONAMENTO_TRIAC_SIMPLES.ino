/*Projeto Medidor de Energia 
 * 
 * Neste prjeto pretendemos acionar uma carga AC via triac aferir os paramentros como corrente e potencia da mesma
 * 
 * 
 * Wesley Azevedo
 *  
 */

// =============================================================================================================
// --- Bibliotecas ---

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "SoftwareSerial.h"
#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;                   // Create an instance

// =============================================================================================================
// --- Criando as Instâncias de necessárias ---

// Cria conexao com bluetooth nas portas padrao /Create a new software  serial
SoftwareSerial bluetooth(0, 1); //RX, TX

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display


// =============================================================================================================
// --- Mapeamento de portas e definação de Variaveis ---

//Informar VALOR DA REDE para calculo de potencia
#define rede 127

// LED para identificar status ligado/desligado
#define LED 13

// Pino SCT Sensor de Corrente 100A
int pinoSCT = A1;

// Pino de acionamento do triac
#define loadR 6

//Variavel Liga/Desliga Triac
int UPP; // Incremento e Decremento da potencia;


// =============================================================================================================
// --- Configurações de Iicio / SETUP  ---


void setup()
{
    
//Inicia comunicação Serial
  Serial.begin(9600);
//Inicia comunicação blutooth   
  bluetooth.begin(9600);            
// initialize the lcd   
  lcd.init();                      
// Print a message to the LCD.
  lcd.backlight();


//DEFINE PINMODE
  pinMode(loadR, OUTPUT);
 
//Instacia da biblioteca EMON
  emon1.current(pinoSCT, 9.09);        // Current: input pin, calibration. A calibração é feita assim: (CurrentMax / CurrentMin / ResistordeCarga) no nosso caso (100/0,05/220)=

// Vou incluir o blink para saber que o atmega está funcionando
  pinMode(LED, OUTPUT);

}
  
  

// =============================================================================================================
// --- LOOP INFINITO  ---

void loop()
{

  
//--- Calcula a corrente ---
float Irms = emon1.calcIrms(1480);

//Percebi que a corrente está sendo calculada em dobro ainda não sei como resolver;
//Irms = Irms/2;


//=============================================================================
//---Imprime Corrente e Potência no LCD  -----

//lcd.clear(); //Fica piscando a tela demais
lcd.setCursor(0,0); 
lcd.print("CORRENTE: ");
lcd.print(Irms);
lcd.print("A ");

//lcd.clear(); //Fica piscando a tela demais
lcd.setCursor(0,1);
lcd.print("POTENCIA: ");// Calculo da Potência
lcd.print(Irms*rede);
lcd.print("W ");


//=============================================================================
//---Imprime Corrente e Potência no Bluetooth -----
bluetooth.print("CORRENTE: ");
bluetooth.print(Irms);
bluetooth.println("A");

// =============================================================================================================
// --- Varia a potencia da lalmpada  ---
  UPP = bluetooth.read();

if (UPP == 'F' || UPP == 'f'){ digitalWrite(loadR, LOW); Serial.println("Triac Desligado");}
if (UPP == 'O' || UPP == 'o'){ digitalWrite(loadR, HIGH); Serial.println("Triac Acionado");}


delay(500);
//=============================================================================
//---Imprime Corrente e Potência no SerialMonitor---

//corrente no SerialMonitor
Serial.print("CORRENTE: ");//corrente no SerialMonitor
Serial.print(Irms);
Serial.println("A");

//Imprime Potência SerialMonitor e no LCD
Serial.print("POTENCIA: ");
Serial.print((Irms*rede)); // Calculo da Potência
Serial.println("W");
Serial.println(" ");
 
// =============================================================================================================
// --- Varia a potencia da lalmpada  ---
  UPP = Serial.read();

if (UPP == 'F' || UPP == 'f'){ digitalWrite(loadR, LOW); Serial.println("Triac Desligado");}
if (UPP == 'O' || UPP == 'o'){ digitalWrite(loadR, HIGH); Serial.println("Triac Acionado");}


delay (500);
}
  












