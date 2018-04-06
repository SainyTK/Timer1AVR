#include <avr/io.h>
#include <avr/interrupt.h>
#define TIME_HIGH 65130
#define TIME_LOW 64380
unsigned char state;
int main()
 { 
    DDRD = 0xff;
    TIMSK1 = 0x01;
    
    TCCR1A = 0x00;
    TCCR1B = 0x04;
    TCNT1 = TIME_LOW;
    state = 1;
    sei();
   while (1);
   return 0;
 }
 
 ISR(TIMER1_OVF_vect)
 {
    if(state == 1)
    {
       PORTD = ~PORTD;
       TCNT1 = TIME_HIGH;
       state = 2;
    }
    else
    {
       PORTD = ~PORTD;
       TCNT1 = TIME_LOW;
       state = 1;
    }
 }
