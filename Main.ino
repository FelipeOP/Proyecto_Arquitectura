//Pulsador
#define on 3
//Piezo
#define pBuzzer 2
//Distancia
int cm = 0;
//Notas Buzzer
int NOTA_C4 = 264;
int NOTA_A4 = 440;
int NOTA_E5 = 653;
//Tiempos entre nota
int cu = 1000/4;
int oc = 1000/8;
double pausa = 1.30;

long readUltrasonicDistance(int triggerPin, int echoPin){
  //Se configura el pin del trigger
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  //Se configura el pin del echo
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  //Retorna la lectura del echo
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(motor,OUTPUT);
  pinMode(on,INPUT);
  pinMode(pBuzzer,OUTPUT);
}

void loop()
{
    warning();
}


void warning()
{
  // Se calcula la distancia
  cm = 0.01723 * readUltrasonicDistance(7, 8 );
  Serial.println(cm);
  
  if ( cm < 110)
  {
   tone(pBuzzer,NOTA_E5,cu);
   delay(cu*pausa);
  }

   delay(100); // Wait for 100 millisecond(s)
  
}
