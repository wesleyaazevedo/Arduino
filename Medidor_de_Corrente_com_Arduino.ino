

//Programa : Medidor de Corrente com Arduino
//Usando sensor de corrente ACS712
//Incluindo Bibliotecas
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
const int viPin = A1;
long valorTensao;
long volts;
long valorCorrente;
float amper;
long amper_aux;
float potencia;
float consumo;
float consumo_aux;
float vs1Pin = 6.273;
//float tarifa = 0.3907;
void setup()
{
   lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  //Inicializa a Serial
  Serial.begin(9600); //inicia a porta serial
}
void loop ()
{

  // Rotina de leitura do Sensor de Tensão

  valorTensao = (vs1Pin); // Atribui a variavel valorTensao o valor do pino vs1Pin
  volts = valorTensao; // Atribui a variavel temperatura o valorLido * cte


  valorCorrente = analogRead(viPin);
  amper = valorCorrente * 2.5 / 511;

/*
  potencia = amper * volts;
  potencia = potencia / 1000;

  consumo_aux = potencia * 0.3907;
  consumo = consumo + consumo_aux;
*/
  // Interface do display
  lcd.clear();
  //lcd.print("Tensao: ");
  //lcd.print(volts);
  //lcd.print(" V");
  lcd.setCursor(0, 1);
  lcd.print("Corrente: ");
  lcd.print(amper);
  lcd.print(" A");
  delay(2000);
Serial.print(viPin);
  /*
  lcd.clear();
  lcd.print("Potencia: ");
  lcd.print(potencia);
  lcd.print("KWh");
  lcd.setCursor(0, 1);
  lcd.print("R$: ");
  lcd.print(consumo);
  delay(2000);
*/
}

