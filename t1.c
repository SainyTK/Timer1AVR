#include <avr/io.h>
#include <avr/interrupt.h>
#define TIME 64755
int main()
 { 
    DDRD = 0xff;
    TIMSK1 = 0x01;
    TCCR1A = 0x00;
    TCCR1B = 0x04;
    TCNT1 = TIME;
    sei();
   while (1);
   return 0;
 }
ISR(TIMER1_OVF_vect)
 {
    TCNT1 = TIME;
    PORTD = ~PORTD;
 }
