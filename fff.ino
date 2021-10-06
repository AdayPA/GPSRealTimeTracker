#include <Arduino.h>
#include <avr/power.h>

void setup()
{
    Serial.begin(9600); // EDIT: added this line
    Serial.println("Setup...");
    pinMode(LED_BUILTIN, OUTPUT);
    /*
  if(F_CPU == 8000000) clock_prescale_set(clock_div_2);
  if(F_CPU == 4000000) clock_prescale_set(clock_div_4);
  if(F_CPU == 2000000) clock_prescale_set(clock_div_8);
  if(F_CPU == 1000000) clock_prescale_set(clock_div_16);
  */
  Serial.println(F_CPU);
  if(F_CPU == 16000000) clock_prescale_set(clock_div_256);
  Serial.println(F_CPU);
}

void loop()
{
  clock_prescale_set(clock_div_1);
  Serial.print("On!");
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10);                       // wait for a second
  
  Serial.print("Off!");
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW  
  delay(10);                       // wait for a second
  clock_prescale_set(clock_div_4);
  Serial.print("On!");
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(10);                       // wait for a second
  
  Serial.print("Off!");
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW  
  delay(10);   
}