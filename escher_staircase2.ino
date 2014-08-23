/* Copyright Alexander Crosby 2014
   
   Program to control a series of led backlights from an Arduino Lilypad.
   
   .Lilypad is an "LilyPad Arduino USB" target
   
   Part of Haunted Mansion Escher Staircase costume.
   
 */
 
 // Assign pins
 const int stair1  = 3;
 const int stair2  = 11;
 const int stair3  = 9;
 const int stair4  = 10;
 const int test    = 13;
 
 // Assign initial brightness
 float stair1_brightness = 0.;
 float stair2_brightness = 0.;
 float stair3_brightness = 0.;
 float stair4_brightness = 0.;
 float test_brightness   = 0.;
  
 void setup(){
     // Set pins to output for analogwrite pwm
     pinMode(stair1, OUTPUT);
     pinMode(stair2, OUTPUT);
     pinMode(stair3, OUTPUT);
     pinMode(stair4, OUTPUT);
     pinMode(test, OUTPUT);
 }
 
 void loop(){
     for (int count = 0; count < 12060; count++){ // 5020
         // Stair 1
         if (count < 20){
             test_brightness   += 12.75;
             stair1_brightness += 12.75; 
         }
         if (count >= 20){
             test_brightness -= 0.051;
             stair1_brightness -= 0.051;
         }
         
         
         //Stair 2
         if (count > 2000){
             if (count < 2020){
                 stair2_brightness += 12.75; 
             }
             if (count >= 2020 ){
                 stair2_brightness -= 0.051;
             }
         }
         
         //Stair 3
         if (count > 4000){
             if (count < 4020){
                 stair3_brightness += 12.75; 
             }
             if (count >= 4020 ){
                 stair3_brightness -= 0.051;
             }
         }
         
         //Stair 4
         if (count > 6000){
             if (count < 6020){
                 stair4_brightness += 12.75; 
             }
             if (count >= 6020 ){
                 stair4_brightness -= 0.051;
             }
         }
         
         if (test_brightness < 0){
             test_brightness = 0;
         }
         if (stair1_brightness < 0){
             stair1_brightness = 0;
         }
         if (stair2_brightness < 0){
             stair2_brightness = 0;
         }
         if (stair3_brightness < 0){
             stair3_brightness = 0;
         }
         if (stair4_brightness < 0){
             stair4_brightness = 0;
         }
         analogWrite(test, floor(test_brightness));
         analogWrite(stair1, floor(stair1_brightness));
         analogWrite(stair2, floor(stair2_brightness));
         analogWrite(stair3, floor(stair3_brightness));
         analogWrite(stair4, floor(stair4_brightness));
         delay(1);
     } 
     delay(1000);
 }

