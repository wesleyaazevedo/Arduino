// Programa : Scroll LCD 16x2 apenas em uma linha  
// Alteracoes e adaptacoes : Arduino e Cia  
//  
// Baseado no programa original de Nishant Arora  
   
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
   
   
//Configuracoes LCD 16x2  
int screenWidth = 16;  
int screenHeight = 2;  
   
//String para as 2 linhas 
 
//line1 = Scroll linha superior
String line1 = "Arduino e Cia, dicas, projetos e tutoriais: www.arduinoecia.com.br"; 
 
//line2 = Linha inferior - estatica  
String line2 = " Arduino e Cia";  
   
// just some reference flags  
int stringStart, stringStop = 0;  
int scrollCursor = screenWidth;  
int tamanho =0;  
   
void setup() 
{  
  //Inicializacao do display  
  lcd.begin(screenWidth,screenHeight);  
}  
   
void loop() 
{  
  lcd.setCursor(scrollCursor, 0);  
  lcd.print(line1.substring(stringStart,stringStop));  
  lcd.setCursor(0, 1);  
  lcd.print(line2);  

  //Quanto menor o valor do delay, mais rapido o scroll  
  delay(250);  
  scroll_sup(); //Chama a rotina que executa o scroll  

  //Verifica o tamanho da string  
  tamanho = line1.length();  
  if (stringStart == tamanho)  
  {  
    stringStart = 0;  
    stringStop = 0;  
  }  
}  
   
void scroll_sup()  
{  
  lcd.clear();  
  if(stringStart == 0 && scrollCursor > 0)
  {  
    scrollCursor--;  
    stringStop++;  
  } else if (stringStart == stringStop){  
    stringStart = stringStop = 0;  
    scrollCursor = screenWidth;  
  } else if (stringStop == line1.length() && scrollCursor == 0) {  
    stringStart++;  
  } else {  
    stringStart++;  
    stringStop++;  
  }  
}
