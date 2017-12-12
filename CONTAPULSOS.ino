// Programa que conta os "meio-ciclos" da onda senoidal fornecida pela
//concessionÃ¡ria de energia elÃ©trica.

// VariÃ¡vel que armazena os pulsos. Como serÃ¡ chamada dentro da rotina
// ContaPulsos(), que Ã© uma rotina de interrupÃ§Ã£o,
// tem que ter o comando volatile.
volatile unsigned int pulsos = 0;

// Rotina que Ã© chamada a cada meio ciclo, incrementando a variÃ¡vel pulsos.</pre>
void ContaPulso()
{
pulsos++;
}

void setup()
{
  Serial.begin(9600);
// Essa instruÃ§Ã£o faz com que, a cada vez que o pino 2 passa muda de 0 para 5V
// (RISING), a rotina ContaPulso() Ã© chmada. O nÃºmero 0 define o pino 2,
// o nÃºmero 1 define o pino 3. 
  attachInterrupt(0, ContaPulso, RISING);
}

void loop()
{
volatile unsigned long t=millis();
// Espera um segundo...
while((millis()-t) <= 1000)
{
}
// Durante a espera, a interrupÃ§Ã£o ocorre a cada vez que o pino 2 muda de
// zero para 5V. Como isso acontece a cada meio ciclo, apÃ³s um segundo</pre>
// a variÃ¡vel pulsos vai conter o valor 120, que serÃ¡ impresso repetidas</pre>
// vezes. 
Serial.println(pulsos);
// Zera a variÃ¡vel para contar os pulsos do prÃ³ximo ciclo.

pulsos=0;

}

