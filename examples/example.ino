/*
 * MillisTimer Library
 * 
 * Copyright (c) 2025 Gabriel Bernardes
 *
 * Licensed under the MIT License. See LICENSE file in the project root for more details.
 */

 #include <Arduino.h>
 #include <MillisTimer.h>
 
 MillisTimer timer;
 
 void logTime(String msg){
   Serial.print(millis()); 
   Serial.println(" " + msg);
 }
 
 void wait(uint32_t ms) {
   Serial.print(F("Delaying for "));
   Serial.print(ms);
   Serial.println(F("ms"));
   delay(ms);
 }
 
 void callback(){
   logTime("Callback!");
 }
 
 void setup() {
   Serial.begin(9600);
   
   logTime("Single. 1000ms duration");
   timer.single(1000, &callback);
   while(!timer.update());
   logTime("Finished!");
 
   logTime("Repeat 3x. 1000ms duration");
   timer.repeatX(3, 1000, &callback);
   uint8_t count = 0;
   while(count < 3) { if (timer.update()) count++; };
   logTime("Finished!");
 
   logTime("Repeat. 1000ms duration");
   timer.repeat(1000, &callback);
 }
 
 void loop() {
   timer.update();
 }
 