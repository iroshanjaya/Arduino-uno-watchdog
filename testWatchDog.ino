#include <avr/wdt.h>

void setup () { 
 Serial.begin (9600);
 
 Serial.println ("Restarted.");

 wdt_enable (WDTO_4S); // reset after four second, if no “pat the dog” received

} // end of setup

void loop () {

  Serial.println ("Entered loop...");

     while (true) {

         wdt_reset (); 
          //keep in the while loop. this clear watchdog timer. if delay()>WDT_xS, then MSU reset. or if MCU stuck
          //then WDT timer will reset MSU after WDTO_xS. because it will not reach wdt_reset() command.            
 
          Serial.println ("Entered while ...");
 
           delay(2000);

      }   // oops, went into a while loop

 
} // end of loop
