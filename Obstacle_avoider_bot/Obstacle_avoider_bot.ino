
#define rmp A0
#define rmn A4
#define lmp A2
#define lmn A3
#define echo 2
#define trig 3
#define enl 3
#define enr 6
int duration;
int cm;
void setup() {
  pinMode(rmp,OUTPUT);
  pinMode(rmn,OUTPUT);
  pinMode(lmp,OUTPUT);
  pinMode(lmn,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(enl,OUTPUT);
  pinMode(enr,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(50);
  digitalWrite(trig,LOW);
   duration=pulseIn(echo,HIGH);
   cm=duration/29/2;
   Serial.print(duration); Serial.print("    ");
   Serial.print("Distance=");
   Serial.println(cm);
   
   while(cm<=15||cm<0)
   {
    st();
    delay(200);
    srm();
    delay(500);
    st();
    delay(200);
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
   duration=pulseIn(echo,HIGH);
   cm=duration/29/2;
   Serial.print("Distance=");
   Serial.println(cm);
   
   }
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
   duration=pulseIn(echo,HIGH);
   cm=duration/29/2;
   Serial.print("Distance=");
   Serial.println(cm);
   while(cm>7)
   {
    fm();
    digitalWrite(trig,LOW);
    delayMicroseconds(2);
    digitalWrite(trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(trig,LOW);
   duration=pulseIn(echo,HIGH);
   cm=duration/29/2;
   Serial.print("Distance=");
   Serial.println(cm);
   }
   
}
void fm()
{
  digitalWrite(lmp,HIGH);
  digitalWrite(lmn,LOW);
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,HIGH);
  analogWrite(enl,100);
  analogWrite(enr,100);
}
void srm()
{
   digitalWrite(lmp,HIGH);
   digitalWrite(lmn,LOW);
   digitalWrite(rmn,HIGH);
   digitalWrite(rmp,LOW);
   analogWrite(enl,60);
   analogWrite(enr,60);
 }
void st()
{
   digitalWrite(lmp,LOW);
  digitalWrite(lmn,LOW);
  digitalWrite(rmn,LOW);
  digitalWrite(rmp,LOW);
  analogWrite(enl,0);
  analogWrite(enr,0);
}
