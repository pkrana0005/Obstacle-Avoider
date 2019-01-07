#include<Servo.h>
Servo myservo; 
#define rmp 4
#define rmn 5
#define lmp 2
#define lmn 3
#define echo 10
#define trig 9

int duration;
int cm;
void setup() {
  myservo.attach(6); 
  pinMode(rmp,OUTPUT);
  pinMode(rmn,OUTPUT);
  pinMode(lmp,OUTPUT);
  pinMode(lmn,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  Serial.begin(9600);
  myservo.write(90); 
}

void loop() {
  
    
      delay(200);
      check();
   while(cm<=15||cm<0)
   {
    st();
    delay(20);
    myservo.write(0);
    delay(200); 
    check();
    if(cm>15)
    { 
      myservo.write(90);
      srm();
      delay(700);
      st();
      delay(50);
      check();
      }
      else
      {
        myservo.write(180);
        delay(200);
        check();
        if(cm>15)
          { 
            myservo.write(90);
            slm();
            delay(700);
            st();
            delay(100);
            check();
          }
          else st();
      }
   }
   check();
   while(cm>15)
   {
    fm();
    check();
   }
       
   
      
  
    
  
}
void check()
{
   digitalWrite(trig,LOW);
   delayMicroseconds(10);
   digitalWrite(trig,HIGH);
   delayMicroseconds(20);
   digitalWrite(trig,LOW);
   duration=pulseIn(echo,HIGH);
   cm=duration/29/2;
   Serial.print("Distance=");
   Serial.println(cm);
  }
void fm()
{
  digitalWrite(rmp,HIGH);
  digitalWrite(rmn,LOW;
  digitalWrite(lmp,LOW);
  digitalWrite(lmn,HIGH);
  }
  
void srm()
{
  digitalWrite(rmp,LOW);
  digitalWrite(rmn,HIGH;
  digitalWrite(lmp,LOW);
  digitalWrite(lmn,HIGH);
   }
   
void slm()
{
  digitalWrite(rmp,HIGH);
  digitalWrite(rmn,LOW;
  digitalWrite(lmp,HIGH);
  digitalWrite(lmn,LOW);
   }
void st()
{
  digitalWrite(lmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,LOW);
  
}
