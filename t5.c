#include <avr/io.h>
int main()
 { 
    DDRB = 0xff;
    
    TIMSK1 = 0x01;
    
    TCCR1A = 0x40; //0100 0000
    TCCR1B = 0x0C; //0000 1100
    
    TCNT1 = 0;
    OCR1A = 173;
    
   while (1);
   return 0;
 }


