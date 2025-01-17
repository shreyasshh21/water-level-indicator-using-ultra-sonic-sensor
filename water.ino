#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; //pins
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
int trigpin=6;
int echopin=7;
int pingtime;
float d;
int level;
float depth;
String msg0="Enter depth of the water tank";
 
void setup() {
  // put your setup code here, to run once:
pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
Serial.begin(9600);    //baud rate
lcd.begin(16,2);
lcd.setCursor(0,0);
lcd.print("Enter depth of");
lcd.setCursor(0,1);
lcd.print("water tank in cms");
Serial.println(msg0);
while (Serial.available()==0)
{
}
depth=Serial.parseInt();
}
 
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigpin,LOW);
delayMicroseconds(10);
digitalWrite(trigpin, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);
pingtime=pulseIn(echopin,HIGH);
 
d=(8./400.)*pingtime;    //equation after calibration
level=(1-d/depth)*100.0;
 
Serial.print("The distance of the object is:");
Serial.println(d);
Serial.println();
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Tank is");
lcd.setCursor(9,0);
lcd.print(level);
lcd.setCursor(12,0);
lcd.print("% f ");
lcd.setCursor(0,1);
lcd.print("Dist.= ");
// lcd.print(d);
lcd.println(d);
lcd.print("CM");
// lcd.print("f");
Serial.println(pingtime);
Serial.print(level);
Serial.println(d);
Serial.print("%\n");
delay(1000);
}