#include <Wire.h>
#include "RTClib.h"
RTC_DS1307 RTC;
void setup () {
    Serial.begin (9600);
    Wire.begin ();
    RTC.begin ();
  if (! RTC.isrunning ()) {
   Serial.println ("RTC NÃO está em execução!");
    // seguinte linha define o RTC para a data e hora em que este sketch foi compilado
    RTC.adjust (DateTime (__DATE__, __TIME__));
  }
}
void loop () {
    DateTime now = RTC.now (); 
    Serial.print (now.year (), DEC);
    Serial.print ('/');
    Serial.print (now.month (), DEC);
    Serial.print ('/');
    Serial.print (now.day (), DEC);
    Serial.print (' ');
    Serial.print (now.hour (), DEC);
    Serial.print (':');
    Serial.print (now.minute (), DEC);
    Serial.print (':');
    Serial.print (now.second (), DEC);
    Serial.println (); 
    delay (1000);
}
