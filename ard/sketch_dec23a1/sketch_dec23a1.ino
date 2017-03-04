
char data = 0;            //Variable for storing received data
long czas, dystans;
#define trigPin 5
#define echoPin 7
#define laserPin 4

void setup()
{
    Serial.begin(9600);   //Sets the baud for serial data transmission                               
    pinMode(11, OUTPUT);  //Sets digital pin 13 as output pin
     pinMode(10, OUTPUT);  //Sets digital pin 13 as output pin
     pinMode(laserPin, OUTPUT);  //Sets digital pin 12 as output pin
     digitalWrite(11, LOW);
     digitalWrite(10, LOW);
      digitalWrite(laserPin, LOW);
     pinMode(trigPin, OUTPUT); //Pin, do którego podłączymy trig jako wyjście
  pinMode(echoPin, INPUT); //a echo, jako wejście
     
}
void loop()
{
  
   if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      Serial.print(data);          //Print Value inside data in Serial monitor
      Serial.print("\n");        
      if(data == 'a')              
       { do_przodu();}
      else if(data == 'c')        
         {_stop();}
      else if(data == 'b')         
         {prawo();}
      else if(data == 'd')         
         {lewo();}
      else if (data == 'f')
        { dupa();}
      else if (data == 'x')
      { pomiarL();}
      else if (data == 'u')
      { pomiarU();}
      else if (data == 'l')
      { laser();}
   }
}

int i;

void do_przodu()
{ 
for(i = 150; i<190 ; i++)
  {
  analogWrite(10, i);   //If value is 1 then LED turns ON
  analogWrite(11, i);
  i+=2;
  delay(50);
  }
  delay(200);
  analogWrite(10, 0);   //If value is 1 then LED turns ON
  analogWrite(11, 0);
}
void _stop()
{
analogWrite(10, 0);    //If value is 0 then LED turns OFF
analogWrite(11, 0);    //If value is 0 then LED turns OFF

}

void lewo()
{
  _stop();
 analogWrite(10, 150);    //If value is 0 then LED turns OFF
 delay(600);
 analogWrite(10, 0);
 


}


void prawo()
{
  
 _stop();
 analogWrite(11, 150);    //If value is 0 then LED turns OFF
 delay(600);
 analogWrite(11, 0);
}

void dupa()
{
  for(i = 150; i<190 ; i++)
  {
  analogWrite(10, i);   //If value is 1 then LED turns ON
  i+=2;
  delay(50);
  }
    for(i = 150; i<190 ; i++)
  {
  analogWrite(11, i);   //If value is 1 then LED turns ON
  i+=2;
  delay(50);
  }
  delay(100);
  analogWrite(10, 0);   //If value is 1 then LED turns ON
  analogWrite(11, 0);

}

void pomiarL()

 {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  czas = pulseIn(echoPin, HIGH);
  dystans = czas / 58;
  
  Serial.print(dystans);
  
  }


int vol;
float voltage;

  void pomiarU()
  {
    vol = analogRead(A0);
    voltage = (vol*0.0048828125)*3;

    Serial.print(voltage);
  }

 void laser()
 {
  digitalWrite(laserPin, HIGH);
 }

