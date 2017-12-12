#define loadR 3  
 
volatile int power = 100;  
void zero_crosss_int()  
{
  // Cálculo do ângulo de disparo: 60Hz-> 8.33ms (1/2 ciclo)
  // (8333us - 8.33us) / 256 = 32 (aprox)
  int powertime = (32*(256-power));      
  // Mantém o circuito desligado por powertime microssegundos 
  delayMicroseconds(powertime);   
  // Envia sinal ao TRIAC para que ele passe a conduzir 
  digitalWrite(loadR, HIGH);  
  // Espera alguns microssegundos para que o TRIAC perceba o pulso
  delayMicroseconds(8.33);      
  // Desliga o pulso
  digitalWrite(loadR, LOW);   
}
 
void setup()
{
  Serial.begin(9600);
  pinMode(loadR, OUTPUT);
  // Inicializa interrupção. O número zero indica a porta 2 do Arduino,
  // zero_crosss_int é a função que será chamada toda vez que o pino 2
  // "subir" (RISING) de valor de 0 para 1.  
  attachInterrupt(0, zero_crosss_int, RISING);  
}
 
void loop()
{
  // Seta a potência para diferentes níveis. Se o sistema estiver conectado a uma lâmpada,
  // esta vai variar de brilho.
  power=14;
  Serial.println(power);
  delay(3000);
  power=24;
  Serial.println(power);
  delay(3000);
  power=31;
  Serial.println(power);
  delay(3000);
  power=64;
  Serial.println(power);
  delay(3000);
  power=96;
  Serial.println(power);
  delay(3000); 
  power=128;
  Serial.println(power);
  delay(3000);
  power=160;
  Serial.println(power);
  delay(3000);
  power=170;
  Serial.println(power);
  delay(3000);
  power=180;
  Serial.println(power);
  delay(3000);
  power=190;
  Serial.println(power);
  delay(3000);
  power=200;
  Serial.println(power);
  delay(3000);
  power=224;
  Serial.println(power);
  delay(3000);
}
