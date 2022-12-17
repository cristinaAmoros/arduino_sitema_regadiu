#define AOUT_PIN A0
#define analici 100
int opcio;
const int pin = 9;

#define echoPin 2 
#define trigPin 3 
long duration; 
int distance;

int conta =0;
void setup() {
  Serial.begin(9600);
  pinMode(pin, OUTPUT);

  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);

  pinMode(4,INPUT);
}

void loop() {
  Serial.print("tria la opcio que vols realitzar: ");
  Serial.print("opcio A: analitzar la humetat ");
  Serial.print("opcio B: analitzar la luminositat ");
  Serial.print("opccio C: regar plantes");
  Serial.print(" opcio D:  a crescut la planta");

  Serial.print("Pots utilitza el polsador per idicar la oppcio desitjada");
  Serial.print("opcio 1 : analitzar la humetat ");
  Serial.print("opcio 2 : analitzar la luminositat ");
  Serial.print("opccio 3 : regar plantes");
  Serial.print(" opcio 4 :  a crescut la planta");
  if (opcio == 'A') {
    int valor = analogRead(AOUT_PIN);

    if (valor < analici)
      Serial.print("el terra esta sec: (");
    else
      Serial.print("el terra esa humit: (");

    Serial.print(valor);
    Serial.println(")");


    delay(500);
  }

  if (opcio == 'B') {
    
    int valorLDR = 0;
    int pinLDR = A0;



 
    valorLDR = analogRead(pinLDR);
    Serial.println(valorLDR);
    delay(50);
    
  

  }

  if (opcio == 'C') {
    digitalWrite(pin, HIGH);
    delay(5000);
    digitalWrite(pin, LOW);
    delay(5000);

  }


  if (opcio == 'D') {
 
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2; 
 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
    }

    
if(digitalRead(4) == HIGH){
  if(digitalRead(4)==LOW){
    conta++;
    Serial.println(conta);
    delay(100);
  }
  
}
if(conta==1){
  int valor = analogRead(AOUT_PIN);

    if (valor < analici)
      Serial.print("el terra esta sec: (");
    else
      Serial.print("el terra esa humit: (");

    Serial.print(valor);
    Serial.println(")");


    delay(500);
}
if(conta==2){
    int valorLDR = 0;
    int pinLDR = A0;



 
    valorLDR = analogRead(pinLDR);
    Serial.println(valorLDR);
    delay(50);
    
  
}
if(conta==3){
  digitalWrite(pin, HIGH);
    delay(5000);
    digitalWrite(pin, LOW);
    delay(5000);

}

if(conta==5){
    digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2; 
 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
}
    

}
