
#define M1  A2     //Definimos as saidas que compoñen as bobinas. 
#define M2  A3
#define M3  A4
#define M4  A5

#define Iana A0   //Definimos a entrada analoxica para comparar

#define Buzz 10   //Usaremos o Buzzer como indicador de PAUSA
#define LedO 12      //Usaremos o Led como indicador de PAUSA
#define LedR 13   //Usaremos o Led como indicador de xiro R
#define LedG 11   //Usaremos o Led  como indicador de xiro l

#define joyX A0


//Esta é a variable paso. Como vemos, es unha matriz que inclue cada unha das catro fases durante 8 ciclos, nos que imos alternando a activación de un o duas fases.

int Paso [ 8 ][ 4 ] =
{ {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 1, 1},
  {1, 0, 0, 1},

};


boolean Direcion = 1; //Define o sentido del motor (1/0).

int PasosV = 2096;     // nº de pasos por volta
int ContaP = 0;       // contar nº de pasos por vuelta
int Steps = 0;       // Define el paso actual de la secuencia
int RETARDO = 2;     //Tempo en microsegundos que tarda o motor en dar un paso

int valX = 0;

void setup() {
  Serial.begin(9600);

  pinMode(M1, OUTPUT); //Declaramos como saidas as fases do motor
  pinMode(M2, OUTPUT);
  pinMode(M3, OUTPUT);
  pinMode(M4, OUTPUT);

  pinMode(Buzz, OUTPUT); //Declaramos como saidas os indicadores
  pinMode(LedO, OUTPUT);
  pinMode(LedG, OUTPUT);
  pinMode(LedR, OUTPUT);

pinMode(joyX,INPUT);

}

void stepper()            //Avanza un paso
{
  digitalWrite( M1, Paso[Steps][ 0] );
  digitalWrite( M2, Paso[Steps][ 1] );
  digitalWrite( M3, Paso[Steps][ 2] );
  digitalWrite( M4, Paso[Steps][ 3] );

  /*
     En funcion da posición na que estemos da matriz activanse unha fase ou outra.
     Logo con setDirecion avanzamos unha posición ou a retrocedemos.
  */
  SetDirecion();
}

void SetDirecion() // Establece o  sentido
{
  if (Direcion)
  {
    Steps++;
  }
  else
  {
    Steps--;
  }

  Steps =  (Steps + 8) % 8 ;
}

void apaga()            //Apaga o motor
{ digitalWrite( M1, 0 );
  digitalWrite( M2, 0 );
  digitalWrite( M3, 0 );
  digitalWrite( M4, 0 );
}

void loop()
{

valX = analogRead(joyX);

Serial.println(valX);
if (valX > 300){
  Direcion = true;
}else if (valX < 200){
  Direcion = false;
}

if (valX > 300 || valX < 200){
  
  stepper();
  if (valX > 400 || valX < 100){
    delay(1);
  }else delay(10);

}else apaga();
  

}

